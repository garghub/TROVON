static T_1
F_1 ( const T_2 * V_1 , int V_2 , int V_3 , T_3 * V_4 , const union V_5 * T_4 V_6 )
{
T_5 V_7 ;
if ( ! F_2 ( V_2 , V_3 , V_8 + 1 ) )
return FALSE ;
V_7 = F_3 ( & V_1 [ V_2 + V_8 - 2 ] ) ;
if ( V_7 <= V_9 ) {
if ( V_1 [ V_2 + V_8 ] == 0xff
&& V_1 [ V_2 + V_8 + 1 ] == 0xff ) {
return F_4 ( V_1 , V_2 + V_8 , V_3 , V_4 , T_4 ) ;
}
else {
return F_5 ( V_1 , V_2 + V_8 , V_3 , V_4 , T_4 ) ;
}
}
return F_6 ( L_1 , V_7 , V_1 , V_2 + V_8 , V_3 , V_4 , T_4 ) ;
}
static
int F_7 ( T_6 * V_10 , T_7 * V_11 ,
T_8 * V_12 , void * T_9 V_6 )
{
T_8 * V_13 = NULL ;
T_8 * V_14 = NULL ;
T_10 V_15 , V_16 ;
T_5 V_7 ;
int V_17 ;
T_11 V_18 ;
T_6 * V_19 = NULL ;
T_8 * V_20 ;
T_8 * V_21 ;
V_17 = V_22 ;
F_8 ( V_11 -> V_23 , V_24 , L_2 ) ;
F_9 ( V_11 -> V_23 , V_25 ) ;
V_15 = F_10 ( V_10 , 0 ) ;
F_11 ( V_11 -> V_23 , V_25 ,
L_3 ,
( V_15 >> 13 ) , ( ( V_15 >> 12 ) & 1 ) , ( V_15 & 0xFFF ) ) ;
V_13 = F_12 ( V_12 , V_17 , V_10 , 0 , V_26 , V_27 ) ;
V_20 = F_13 ( V_13 , V_28 ) ;
V_7 = F_10 ( V_10 , V_26 - 2 ) ;
V_18 . V_29 = V_20 ;
V_18 . V_30 = V_31 ;
V_18 . V_32 = V_33 ;
V_18 . V_34 = 0 ;
if ( V_7 == V_35 ) {
if ( V_12 ) {
V_14 = F_12 ( V_13 , V_17 , V_10 , 0 , 2 , V_27 ) ;
V_21 = F_13 ( V_14 , V_28 ) ;
F_14 ( V_21 , V_36 , V_10 ,
0 , 1 , V_15 ) ;
F_14 ( V_21 , V_37 , V_10 , 0 , 1 , V_15 ) ;
F_14 ( V_21 , V_38 , V_10 , 0 , 2 , V_15 ) ;
F_15 ( V_21 , L_4 , V_15 & 0x0FFF ) ;
}
V_19 = F_16 ( V_10 , V_26 ) ;
if ( V_13 ) {
F_15 ( V_13 , L_5 , V_15 & 0x0FFF ) ;
F_17 ( V_19 , V_11 , V_13 , V_12 , V_17 ) ;
}
else {
F_17 ( V_19 , V_11 , V_12 , NULL , V_17 ) ;
}
} else if ( V_7 == V_39 ) {
V_16 = F_10 ( V_10 , V_26 ) ;
if ( V_12 ) {
F_14 ( V_20 , V_36 , V_10 ,
0 , 1 , V_15 ) ;
F_14 ( V_20 , V_37 , V_10 , 0 , 1 , V_15 ) ;
F_14 ( V_20 , V_40 , V_10 , 0 , 2 , V_15 ) ;
F_14 ( V_20 , V_36 , V_10 ,
V_26 , 1 , V_16 ) ;
F_14 ( V_20 , V_37 , V_10 ,
V_26 , 1 , V_16 ) ;
F_14 ( V_20 , V_41 , V_10 , V_26 ,
2 , V_16 ) ;
}
F_15 ( V_13 , L_6 , V_15 & 0x0FFF ,
V_16 & 0x0FFF ) ;
V_18 . V_42 = F_10 ( V_10 , V_26 * 2 - 2 ) ;
V_18 . V_43 = V_26 * 2 ;
F_18 ( V_44 , V_10 , V_11 , V_12 , & V_18 ) ;
} else {
if ( V_12 ) {
F_14 ( V_20 , V_36 , V_10 ,
0 , 1 , V_15 ) ;
F_14 ( V_20 , V_37 , V_10 , 0 , 1 , V_15 ) ;
F_14 ( V_20 , V_38 , V_10 , 0 , 2 , V_15 ) ;
}
F_15 ( V_13 , L_7 , V_15 & 0x0FFF ) ;
V_18 . V_42 = V_7 ;
V_18 . V_43 = V_26 ;
F_18 ( V_44 , V_10 , V_11 , V_12 , & V_18 ) ;
}
return F_19 ( V_10 ) ;
}
void
F_17 ( T_6 * V_10 , T_7 * V_11 ,
T_8 * V_12 , T_8 * V_45 , int V_46 ) {
T_10 V_15 ;
T_5 V_7 ;
T_8 * V_13 ;
T_11 V_18 ;
T_8 * V_47 ;
V_15 = F_20 ( V_10 , 0 ) ;
F_11 ( V_11 -> V_23 , V_25 ,
L_8 ,
( V_15 >> 29 ) , ( ( V_15 >> 28 ) & 1 ) , ( ( V_15 >> 27 ) & 1 ) ,
( ( V_15 >> 26 ) & 1 ) , ( ( V_15 >> 24 ) & 3 ) , V_15 & V_48 ) ;
V_13 = NULL ;
V_47 = NULL ;
if ( V_12 ) {
V_13 = F_12 ( V_12 , V_46 , V_10 , 0 , 4 , V_27 ) ;
V_47 = F_13 ( V_13 , V_49 ) ;
F_14 ( V_47 , V_50 , V_10 ,
0 , 1 , V_15 ) ;
F_14 ( V_47 , V_51 , V_10 , 0 , 1 , V_15 ) ;
F_14 ( V_47 , V_52 , V_10 , 0 , 1 , V_15 ) ;
F_14 ( V_47 , V_53 , V_10 , 0 , 1 , V_15 ) ;
F_14 ( V_47 , V_54 , V_10 , 0 , 1 , V_15 ) ;
F_14 ( V_47 , V_55 , V_10 , 1 , 3 , V_15 ) ;
F_15 ( V_47 , L_9 ,
V_15 & V_48 ) ;
F_12 ( V_12 , V_56 , V_10 , 4 , 6 , V_27 ) ;
F_12 ( V_12 , V_57 , V_10 , 10 , 6 , V_27 ) ;
if ( V_45 ) {
F_21 ( V_12 , L_10 ,
V_15 & V_48 ,
F_22 ( F_23 () , V_10 , V_58 , 10 ) ,
F_22 ( F_23 () , V_10 , V_58 , 4 ) ) ;
}
}
V_7 = F_10 ( V_10 , V_8 - 2 ) ;
V_18 . V_42 = V_7 ;
V_18 . V_29 = V_12 ;
V_18 . V_43 = V_8 ;
V_18 . V_30 = V_31 ;
V_18 . V_32 = V_33 ;
V_18 . V_34 = 0 ;
if ( V_45 ) {
F_18 ( V_44 , V_10 , V_11 , V_45 , & V_18 ) ;
}
else {
F_18 ( V_44 , V_10 , V_11 , V_12 , & V_18 ) ;
}
}
static
int F_24 ( T_6 * V_10 , T_7 * V_11 ,
T_8 * V_12 , void * T_9 V_6 )
{
T_12 * V_59 ;
T_10 V_15 ;
int V_17 ;
T_8 * V_60 ;
V_17 = V_61 ;
F_8 ( V_11 -> V_23 , V_24 , L_11 ) ;
F_9 ( V_11 -> V_23 , V_25 ) ;
V_15 = F_20 ( V_10 , 0 ) ;
F_11 ( V_11 -> V_23 , V_25 ,
L_8 ,
( V_15 >> 29 ) , ( ( V_15 >> 28 ) & 1 ) , ( ( V_15 >> 27 ) & 1 ) ,
( ( V_15 >> 26 ) & 1 ) , ( ( V_15 >> 24 ) & 3 ) , ( V_15 & 0x00FFFFFF ) ) ;
V_59 = F_12 ( V_12 , V_17 , V_10 , 0 , V_8 , V_27 ) ;
V_60 = F_13 ( V_59 , V_49 ) ;
if ( V_60 ) {
F_17 ( V_10 , V_11 , V_60 , V_12 , V_17 ) ;
} else {
F_17 ( V_10 , V_11 , V_12 , NULL , V_17 ) ;
}
return F_19 ( V_10 ) ;
}
void
F_25 ( void )
{
static T_13 V_62 [] = {
{ & V_50 , {
L_12 , L_13 , V_63 , V_64 ,
0 , 0xE0000000 , NULL , V_65 } } ,
{ & V_51 , {
L_14 , L_15 , V_63 , V_64 ,
0 , 0x10000000 , NULL , V_65 } } ,
{ & V_52 , {
L_16 , L_17 , V_63 , V_64 ,
0 , 0x08000000 , L_18 , V_65 } } ,
{ & V_53 , {
L_19 , L_20 , V_63 , V_64 ,
0 , 0x04000000 , L_21 , V_65 } } ,
{ & V_54 , {
L_22 , L_23 , V_63 , V_64 ,
0 , 0x03000000 , L_24 , V_65 } } ,
{ & V_55 , {
L_25 , L_26 , V_63 , V_64 ,
0 , 0x00FFFFFF , NULL , V_65 } } ,
{ & V_56 , {
L_27 , L_28 , V_66 , V_67 ,
NULL , 0x0 , L_29 , V_65 } } ,
{ & V_57 , {
L_30 , L_31 , V_66 , V_67 ,
NULL , 0x0 , L_32 , V_65 } } ,
{ & V_31 , {
L_33 , L_34 , V_68 , V_69 ,
F_26 ( V_70 ) , 0x0 , NULL , V_65 } } ,
#if 0
{ &hf_ieee8021ah_len, {
"Length", "ieee8021ah.len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
#endif
{ & V_33 , {
L_35 , L_36 , V_71 , V_67 ,
NULL , 0x0 , L_37 , V_65 } }
} ;
static T_13 V_72 [] = {
{ & V_36 , {
L_12 , L_38 , V_68 , V_64 ,
0 , 0xE000 , NULL , V_65 } } ,
{ & V_37 , {
L_39 , L_40 , V_68 , V_64 ,
0 , 0x1000 , L_41 , V_65 } } ,
{ & V_38 , {
L_42 , L_43 , V_68 , V_64 ,
0 , 0x0FFF , L_44 , V_65 } } ,
{ & V_40 , {
L_42 , L_45 , V_68 , V_64 ,
0 , 0x0FFF , L_46 , V_65 } } ,
{ & V_41 , {
L_42 , L_47 , V_68 , V_64 ,
0 , 0x0FFF , L_48 , V_65 } } ,
} ;
static T_14 * V_73 [] = {
& V_49 ,
& V_28
} ;
T_15 * V_74 ;
V_61 = F_27 ( L_49 , L_50 ,
L_51 ) ;
F_28 ( V_61 , V_62 , F_29 ( V_62 ) ) ;
V_22 = F_27 ( L_52 , L_53 ,
L_54 ) ;
F_28 ( V_22 , V_72 , F_29 ( V_72 ) ) ;
F_30 ( V_73 , F_29 ( V_73 ) ) ;
V_74 = F_31 ( V_61 ,
V_75 ) ;
F_32 ( V_74 , L_55 ,
L_56 ,
L_57 ,
16 , & V_76 ) ;
}
void
V_75 ( void )
{
static T_1 V_77 = FALSE ;
static T_16 V_78 ;
static unsigned int V_79 ;
if ( ! V_77 ) {
T_16 V_80 ;
V_78 = F_33 ( F_24 ,
V_61 ) ;
V_80 = F_33 ( F_7 ,
V_22 ) ;
F_34 ( L_1 , V_39 , V_80 ) ;
V_44 = F_35 ( L_1 , V_61 ) ;
F_35 ( L_1 , V_22 ) ;
F_36 ( L_1 , V_39 , F_1 , V_61 ) ;
F_36 ( L_1 , V_35 , F_1 , V_61 ) ;
V_77 = TRUE ;
}
else {
F_37 ( L_1 , V_79 , V_78 ) ;
}
V_79 = V_76 ;
F_34 ( L_1 , V_76 , V_78 ) ;
}
