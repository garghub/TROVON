void F_1 ( T_1 * V_1 , T_2 V_2 , T_2 V_3 , T_2 V_4 )
{
T_2 V_5 = 0 ;
T_2 V_6 ;
T_2 V_7 ;
T_1 V_8 ;
if ( ! V_1 ) {
F_2 ( L_1 ) ;
return;
}
if ( ( V_2 < 4 ) || ( V_2 & 0x01 ) ) {
V_3 = V_9 ;
}
while ( V_5 < V_2 ) {
F_2 ( L_2 , ( V_4 + V_5 ) ) ;
for ( V_6 = 0 ; V_6 < 16 ; ) {
if ( V_5 + V_6 >= V_2 ) {
F_2 ( L_3 , ( ( V_3 * 2 ) + 1 ) , L_4 ) ;
V_6 += V_3 ;
continue;
}
switch ( V_3 ) {
case V_9 :
default:
F_2 ( L_5 ,
V_1 [ ( V_10 ) V_5 + V_6 ] ) ;
break;
case V_11 :
F_3 ( & V_7 ,
& V_1 [ ( V_10 ) V_5 + V_6 ] ) ;
F_2 ( L_6 , V_7 ) ;
break;
case V_12 :
F_4 ( & V_7 ,
& V_1 [ ( V_10 ) V_5 + V_6 ] ) ;
F_2 ( L_7 , V_7 ) ;
break;
case V_13 :
F_4 ( & V_7 ,
& V_1 [ ( V_10 ) V_5 + V_6 ] ) ;
F_2 ( L_8 , V_7 ) ;
F_4 ( & V_7 ,
& V_1 [ ( V_10 ) V_5 + V_6 +
4 ] ) ;
F_2 ( L_7 , V_7 ) ;
break;
}
V_6 += V_3 ;
}
F_2 ( L_4 ) ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
if ( V_5 + V_6 >= V_2 ) {
F_2 ( L_9 ) ;
return;
}
V_8 = V_1 [ ( V_10 ) V_5 + V_6 ] ;
if ( F_5 ( V_8 ) ) {
F_2 ( L_10 , V_8 ) ;
} else {
F_2 ( L_11 ) ;
}
}
F_2 ( L_9 ) ;
V_5 += 16 ;
}
return;
}
void
F_6 ( T_1 * V_1 , T_2 V_2 , T_2 V_3 , T_2 V_14 )
{
if ( ! ( ( V_15 & V_16 ) &&
( V_14 & V_17 ) ) ) {
return;
}
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
}
void
F_7 ( T_3 V_18 ,
T_1 * V_1 , T_2 V_2 , T_2 V_3 , T_2 V_4 )
{
T_2 V_5 = 0 ;
T_2 V_6 ;
T_2 V_7 ;
T_1 V_8 ;
if ( ! V_1 ) {
F_8 ( V_18 ,
L_1 ) ;
return;
}
if ( ( V_2 < 4 ) || ( V_2 & 0x01 ) ) {
V_3 = V_9 ;
}
while ( V_5 < V_2 ) {
F_8 ( V_18 , L_2 , ( V_4 + V_5 ) ) ;
for ( V_6 = 0 ; V_6 < 16 ; ) {
if ( V_5 + V_6 >= V_2 ) {
F_8 ( V_18 , L_3 ,
( ( V_3 * 2 ) + 1 ) , L_4 ) ;
V_6 += V_3 ;
continue;
}
switch ( V_3 ) {
case V_9 :
default:
F_8 ( V_18 , L_5 ,
V_1 [ ( V_10 ) V_5 + V_6 ] ) ;
break;
case V_11 :
F_3 ( & V_7 ,
& V_1 [ ( V_10 ) V_5 + V_6 ] ) ;
F_8 ( V_18 , L_6 , V_7 ) ;
break;
case V_12 :
F_4 ( & V_7 ,
& V_1 [ ( V_10 ) V_5 + V_6 ] ) ;
F_8 ( V_18 , L_7 , V_7 ) ;
break;
case V_13 :
F_4 ( & V_7 ,
& V_1 [ ( V_10 ) V_5 + V_6 ] ) ;
F_8 ( V_18 , L_8 , V_7 ) ;
F_4 ( & V_7 ,
& V_1 [ ( V_10 ) V_5 + V_6 +
4 ] ) ;
F_8 ( V_18 , L_7 , V_7 ) ;
break;
}
V_6 += V_3 ;
}
F_8 ( V_18 , L_4 ) ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
if ( V_5 + V_6 >= V_2 ) {
F_8 ( V_18 , L_9 ) ;
return;
}
V_8 = V_1 [ ( V_10 ) V_5 + V_6 ] ;
if ( F_5 ( V_8 ) ) {
F_8 ( V_18 , L_10 , V_8 ) ;
} else {
F_8 ( V_18 , L_11 ) ;
}
}
F_8 ( V_18 , L_9 ) ;
V_5 += 16 ;
}
return;
}
