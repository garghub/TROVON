static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 = NULL ;
T_3 * V_6 = NULL ;
int V_7 = 0 ;
unsigned int V_8 = 0 ;
T_1 * V_9 ;
int V_10 = 0 ;
V_8 = ( F_2 ( V_1 , V_7 ) & 0xc0 ) >> 6 ;
F_3 ( V_2 -> V_11 , V_12 , L_1 ) ;
if( V_8 == 0x00 ) {
F_4 ( V_2 -> V_11 , V_13 , L_2 ) ;
V_10 = 4 ;
}
else if( V_8 == 0x02 ) {
F_4 ( V_2 -> V_11 , V_13 , L_3 ) ;
V_10 = 8 ;
}
else if( V_8 == 0x03 ) {
F_4 ( V_2 -> V_11 , V_13 , L_4 ) ;
V_10 = 12 ;
}
if ( V_3 ) {
V_5 = F_5 ( V_3 , V_14 , V_1 , V_7 , V_10 , V_15 ) ;
V_6 = F_6 ( V_5 , V_16 ) ;
F_5 ( V_6 , V_17 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_19 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_20 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_21 , V_1 , V_7 , 1 , V_18 ) ;
V_7 ++ ;
F_5 ( V_6 , V_22 , V_1 , V_7 , 1 , V_18 ) ;
if( V_8 == 0x00 ) {
F_5 ( V_6 , V_23 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_24 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_25 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_26 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_27 , V_1 , V_7 , 2 , V_18 ) ;
V_7 ++ ;
F_5 ( V_6 , V_28 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_29 , V_1 , V_7 , 1 , V_18 ) ;
V_7 ++ ;
F_5 ( V_6 , V_30 , V_1 , V_7 , 1 , V_15 ) ;
V_7 ++ ;
} else {
F_5 ( V_6 , V_31 , V_1 , V_7 , 1 , V_15 ) ;
V_7 ++ ;
F_5 ( V_6 , V_32 , V_1 , V_7 , 1 , V_15 ) ;
F_5 ( V_6 , V_33 , V_1 , V_7 , 2 , V_18 ) ;
V_7 ++ ;
F_5 ( V_6 , V_34 , V_1 , V_7 , 1 , V_15 ) ;
V_7 ++ ;
F_5 ( V_6 , V_35 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_36 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_37 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_38 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_39 , V_1 , V_7 , 2 , V_18 ) ;
V_7 ++ ;
F_5 ( V_6 , V_40 , V_1 , V_7 , 2 , V_18 ) ;
V_7 ++ ;
F_5 ( V_6 , V_41 , V_1 , V_7 , 2 , V_18 ) ;
V_7 ++ ;
F_5 ( V_6 , V_42 , V_1 , V_7 , 1 , V_15 ) ;
V_7 ++ ;
if( V_8 == 0x03 ) {
F_5 ( V_6 , V_43 , V_1 , V_7 , 3 , V_18 ) ;
V_7 += 2 ;
F_5 ( V_6 , V_28 , V_1 , V_7 , 1 , V_18 ) ;
F_5 ( V_6 , V_29 , V_1 , V_7 , 1 , V_18 ) ;
V_7 ++ ;
F_5 ( V_6 , V_30 , V_1 , V_7 , 1 , V_15 ) ;
V_7 ++ ;
}
}
} else {
switch( V_8 ) {
case 0x00 :
V_7 += 4 ;
break;
case 0x01 :
V_7 += 8 ;
break;
case 0x02 :
V_7 += 12 ;
break;
}
}
V_9 = F_7 ( V_1 , V_7 ) ;
F_8 ( V_44 , V_9 , V_2 , V_3 ) ;
return F_9 ( V_1 ) ;
}
void
F_10 ( void )
{
F_11 ( L_5 , V_45 , V_46 ) ;
F_11 ( L_6 , V_47 , V_46 ) ;
V_44 = F_12 ( L_7 , V_14 ) ;
}
void
F_13 ( void )
{
static T_6 V_48 [] = {
{
& V_17 ,
{
L_8 ,
L_9 ,
V_49 ,
8 ,
NULL ,
0x80 ,
L_10 , V_50
}
} ,
{
& V_19 ,
{
L_11 ,
L_12 ,
V_49 ,
8 ,
NULL ,
0x40 ,
L_13 , V_50
}
} ,
{
& V_20 ,
{
L_14 ,
L_15 ,
V_51 ,
V_52 ,
NULL ,
0x38 ,
L_16 , V_50
}
} ,
{
& V_21 ,
{
L_17 ,
L_18 ,
V_51 ,
V_52 ,
NULL ,
0x7 ,
L_19 , V_50
}
} ,
{
& V_22 ,
{
L_20 ,
L_21 ,
V_51 ,
V_52 ,
F_14 ( V_53 ) ,
0xe0 ,
L_22 , V_50
}
} ,
{
& V_23 ,
{
L_23 ,
L_24 ,
V_49 ,
8 ,
NULL ,
0x08 ,
L_25 , V_50
}
} ,
{
& V_24 ,
{
L_26 ,
L_27 ,
V_49 ,
8 ,
NULL ,
0x10 ,
L_28 , V_50
}
} ,
{
& V_25 ,
{
L_29 ,
L_30 ,
V_49 ,
8 ,
NULL ,
0x20 ,
L_31 , V_50
}
} ,
{
& V_26 ,
{
L_32 ,
L_33 ,
V_49 ,
8 ,
NULL ,
0x40 ,
L_34 , V_50
}
} ,
{
& V_35 ,
{
L_23 ,
L_24 ,
V_49 ,
8 ,
NULL ,
0x80 ,
L_25 , V_50
}
} ,
{
& V_36 ,
{
L_26 ,
L_27 ,
V_49 ,
8 ,
NULL ,
0x40 ,
L_28 , V_50
}
} ,
{
& V_37 ,
{
L_29 ,
L_30 ,
V_49 ,
8 ,
NULL ,
0x20 ,
L_31 , V_50
}
} ,
{
& V_38 ,
{
L_32 ,
L_33 ,
V_49 ,
8 ,
NULL ,
0x10 ,
L_34 , V_50
}
} ,
{
& V_28 ,
{
L_35 ,
L_36 ,
V_51 ,
V_52 ,
NULL ,
0x18 ,
L_37 , V_50
}
} ,
{
& V_29 ,
{
L_38 ,
L_39 ,
V_51 ,
V_52 ,
NULL ,
0x07 ,
L_40 , V_50
}
} ,
{
& V_30 ,
{
L_41 ,
L_42 ,
V_51 ,
V_52 ,
NULL ,
0x0 ,
L_43 , V_50
}
} ,
{
& V_31 ,
{
L_44 ,
L_45 ,
V_51 ,
V_52 ,
NULL ,
0x1F ,
L_46 , V_50
}
} ,
{
& V_32 ,
{
L_47 ,
L_48 ,
V_51 ,
V_52 ,
NULL ,
0xF8 ,
L_49 , V_50
}
} ,
{
& V_33 ,
{
L_50 ,
L_51 ,
V_54 ,
V_52 ,
NULL ,
0x3FE0 ,
L_52 , V_50
}
} ,
{
& V_39 ,
{
L_53 ,
L_54 ,
V_54 ,
V_52 ,
NULL ,
0x07F0 ,
L_55 , V_50
}
} ,
{
& V_40 ,
{
L_56 ,
L_57 ,
V_51 ,
V_52 ,
NULL ,
0x03F8 ,
L_58 , V_50
}
} ,
{
& V_41 ,
{
L_59 ,
L_60 ,
V_51 ,
V_52 ,
NULL ,
0x01FC ,
L_61 , V_50
}
} ,
{
& V_42 ,
{
L_62 ,
L_63 ,
V_51 ,
V_52 ,
NULL ,
0x7F ,
L_64 , V_50
}
} ,
{
& V_27 ,
{
L_65 ,
L_66 ,
V_54 ,
V_52 ,
NULL ,
0x0380 ,
L_67 , V_50
}
} ,
{
& V_34 ,
{
L_65 ,
L_66 ,
V_51 ,
V_52 ,
NULL ,
0x03 ,
L_67 , V_50
}
} ,
{
& V_43 ,
{
L_68 ,
L_69 ,
V_55 ,
V_52 ,
NULL ,
0x07FFFF ,
L_67 , V_50
}
} ,
} ;
static T_7 * V_56 [] = {
& V_16 ,
} ;
F_15 ( V_56 , F_16 ( V_56 ) ) ;
V_14 = F_17 ( L_70 ,
L_71 , L_72 ) ;
F_18 ( V_14 , V_48 , F_16 ( V_48 ) ) ;
V_46 = F_19 ( L_72 , F_1 , V_14 ) ;
}
