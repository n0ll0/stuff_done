const Message = (Nimi) => {
    const message = Nimi + ', oled oodatud Uko sünnipäevale\n(1.04.2022) 19:00-21:00\nAkadeemia Bowling Mustamäe Elamuskeskus';
    console.log(message);
};

const nimed = ['Emma Britta Lee', 'Marten Leppik', 'Erik Tutt', 'Kaur Joosep Kivistik', 'Alexander Reinola'];

for (nimi of nimed) {
    Message(nimi);
};