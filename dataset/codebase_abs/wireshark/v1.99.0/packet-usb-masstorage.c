static void
F_1 ( T_1 * T_2 V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 V_5 , T_6 * T_7 V_1 , T_8 * T_9 V_1 )
{
if( V_5 ) {
F_2 ( V_2 , V_6 , V_3 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
F_2 ( V_2 , V_8 , V_3 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
F_2 ( V_2 , V_9 , V_3 , V_4 , 2 , V_7 ) ;
} else {
}
}
static void
F_3 ( T_1 * T_2 V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 V_5 , T_6 * T_7 V_1 , T_8 * T_9 V_1 )
{
if( V_5 ) {
F_2 ( V_2 , V_6 , V_3 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
F_2 ( V_2 , V_8 , V_3 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
F_2 ( V_2 , V_9 , V_3 , V_4 , 2 , V_7 ) ;
} else {
F_2 ( V_2 , V_10 , V_3 , V_4 , 1 , V_7 ) ;
V_4 ++ ;
}
}
static T_10
F_4 ( T_4 * V_3 , T_1 * T_2 , T_3 * V_2 , void * V_11 )
{
T_5 V_5 ;
T_8 * T_9 ;
T_6 * T_7 ;
int V_4 = 0 ;
T_11 V_12 = NULL ;
const T_12 * V_13 ;
if ( V_11 == NULL || ( ( T_8 * ) V_11 ) -> T_7 == NULL )
return 0 ;
T_9 = ( T_8 * ) V_11 ;
T_7 = T_9 -> T_7 ;
V_5 = ( T_2 -> V_14 == V_15 ) ;
for( V_13 = V_16 ; V_13 -> V_12 ; V_13 ++ ) {
if ( V_13 -> V_17 == T_7 -> V_18 . V_17 ) {
V_12 = V_13 -> V_12 ;
break;
}
}
if( ! V_12 ) {
return 0 ;
}
F_5 ( T_2 -> V_19 , V_20 , L_1 ) ;
F_6 ( T_2 -> V_19 , V_21 , L_2 ,
F_7 ( T_7 -> V_18 . V_17 , V_22 , L_3 ) ,
V_5 ? L_4 : L_5 ) ;
if( V_5 ) {
F_2 ( V_2 , V_23 , V_3 , V_4 , 1 , V_24 ) ;
V_4 += 1 ;
}
V_12 ( T_2 , V_2 , V_3 , V_4 , V_5 , T_7 , T_9 ) ;
return F_8 ( V_3 ) ;
}
static int
F_9 ( T_4 * V_3 , T_1 * T_2 , T_3 * V_25 , void * V_11 )
{
T_8 * T_9 ;
T_13 * V_26 ;
T_3 * V_2 = NULL ;
T_14 V_27 = 0 ;
int V_4 = 0 ;
T_5 V_5 ;
T_15 * V_28 ;
T_16 * V_29 ;
if ( V_11 == NULL )
return 0 ;
T_9 = ( T_8 * ) V_11 ;
V_26 = ( T_13 * ) T_9 -> V_30 ;
if( ! V_26 ) {
V_26 = F_10 ( F_11 () , T_13 ) ;
V_26 -> V_28 = F_12 ( F_11 () ) ;
V_26 -> V_29 = F_12 ( F_11 () ) ;
T_9 -> V_30 = V_26 ;
}
V_5 = ( T_2 -> V_14 == V_15 ) ;
F_5 ( T_2 -> V_19 , V_20 , L_1 ) ;
F_13 ( T_2 -> V_19 , V_21 ) ;
if( V_25 ) {
T_17 * V_31 = NULL ;
V_31 = F_14 ( V_25 , V_32 , V_3 , 0 , - 1 , L_6 ) ;
V_2 = F_15 ( V_31 , V_33 ) ;
}
V_27 = F_16 ( V_3 , V_4 ) ;
if( V_5 && ( V_27 == 0x43425355 ) && ( F_8 ( V_3 ) == 31 ) ) {
T_4 * V_34 ;
int V_35 , V_36 ;
T_18 V_37 , V_38 ;
T_14 V_39 ;
F_2 ( V_2 , V_40 , V_3 , V_4 , 4 , V_24 ) ;
V_4 += 4 ;
F_2 ( V_2 , V_41 , V_3 , V_4 , 4 , V_24 ) ;
V_4 += 4 ;
F_2 ( V_2 , V_42 , V_3 , V_4 , 4 , V_24 ) ;
V_39 = F_16 ( V_3 , V_4 ) ;
V_4 += 4 ;
F_2 ( V_2 , V_43 , V_3 , V_4 , 1 , V_24 ) ;
V_38 = F_17 ( V_3 , V_4 ) ;
V_4 += 1 ;
F_2 ( V_2 , V_44 , V_3 , V_4 , 1 , V_24 ) ;
V_37 = F_17 ( V_3 , V_4 ) & 0x0f ;
V_4 += 1 ;
V_28 = ( T_15 * ) F_18 ( V_26 -> V_28 , V_37 ) ;
if( ! V_28 ) {
V_28 = F_10 ( F_11 () , T_15 ) ;
V_28 -> V_45 = 0xff ;
V_28 -> V_46 = NULL ;
F_19 ( V_26 -> V_28 , V_37 , V_28 ) ;
}
V_29 = ( T_16 * ) F_18 ( V_26 -> V_29 , T_2 -> V_47 -> V_48 ) ;
if( ! V_29 ) {
V_29 = F_10 ( F_11 () , T_16 ) ;
V_29 -> V_37 = V_37 ;
V_29 -> V_49 = 0xffff ;
V_29 -> V_50 = 0 ;
if( V_39 ) {
if( V_38 & 0x80 ) {
V_29 -> V_50 |= V_51 ;
} else {
V_29 -> V_50 |= V_52 ;
}
}
V_29 -> V_53 = V_39 ;
V_29 -> V_54 = 0 ;
V_29 -> V_55 = T_2 -> V_47 -> V_56 ;
V_29 -> V_57 = T_2 -> V_47 -> V_48 ;
V_29 -> V_58 = 0 ;
V_29 -> V_38 = 0 ;
V_29 -> V_59 = 0 ;
V_29 -> V_60 = NULL ;
F_19 ( V_26 -> V_29 , T_2 -> V_47 -> V_48 , V_29 ) ;
}
F_2 ( V_2 , V_61 , V_3 , V_4 , 1 , V_24 ) ;
V_35 = F_17 ( V_3 , V_4 ) & 0x1f ;
V_4 += 1 ;
V_36 = V_35 ;
if( V_36 > F_20 ( V_3 , V_4 ) ) {
V_36 = F_20 ( V_3 , V_4 ) ;
}
if( V_36 ) {
V_34 = F_21 ( V_3 , V_4 , V_36 , V_35 ) ;
F_22 ( V_34 , T_2 , V_25 , V_62 , V_29 , V_28 ) ;
}
return F_8 ( V_3 ) ;
}
if( ( ! V_5 ) && ( V_27 == 0x53425355 ) && ( F_8 ( V_3 ) == 13 ) ) {
T_18 V_63 ;
F_2 ( V_2 , V_64 , V_3 , V_4 , 4 , V_24 ) ;
V_4 += 4 ;
F_2 ( V_2 , V_41 , V_3 , V_4 , 4 , V_24 ) ;
V_4 += 4 ;
F_2 ( V_2 , V_65 , V_3 , V_4 , 4 , V_24 ) ;
V_4 += 4 ;
F_2 ( V_2 , V_66 , V_3 , V_4 , 1 , V_24 ) ;
V_63 = F_17 ( V_3 , V_4 ) ;
V_29 = ( T_16 * ) F_23 ( V_26 -> V_29 , T_2 -> V_47 -> V_48 ) ;
if( ! V_29 ) {
return F_8 ( V_3 ) ;
}
V_29 -> V_58 = T_2 -> V_47 -> V_48 ;
V_28 = ( T_15 * ) F_18 ( V_26 -> V_28 , V_29 -> V_37 ) ;
if( ! V_28 ) {
return F_8 ( V_3 ) ;
}
if( ! V_63 ) {
F_24 ( V_3 , T_2 , V_25 , V_29 , V_28 , 0 ) ;
} else {
F_24 ( V_3 , T_2 , V_25 , V_29 , V_28 , 0x02 ) ;
}
return F_8 ( V_3 ) ;
}
V_29 = ( T_16 * ) F_23 ( V_26 -> V_29 , T_2 -> V_47 -> V_48 ) ;
if( ! V_29 ) {
return F_8 ( V_3 ) ;
}
V_28 = ( T_15 * ) F_18 ( V_26 -> V_28 , V_29 -> V_37 ) ;
if( ! V_28 ) {
return F_8 ( V_3 ) ;
}
F_25 ( V_3 , T_2 , V_25 , V_5 , V_29 , V_28 , 0 ) ;
return F_8 ( V_3 ) ;
}
static T_5
F_26 ( T_4 * V_3 , T_1 * T_2 , T_3 * V_2 , void * V_11 )
{
const T_19 V_67 [] = { 0x55 , 0x53 , 0x42 , 0x43 } ;
const T_19 V_68 [] = { 0x55 , 0x53 , 0x42 , 0x53 } ;
if ( F_27 ( V_3 ) < 4 )
return FALSE ;
if ( F_28 ( V_3 , 0 , V_67 , sizeof( V_67 ) ) == 0 ||
F_28 ( V_3 , 0 , V_68 , sizeof( V_68 ) ) == 0 ) {
F_9 ( V_3 , T_2 , V_2 , V_11 ) ;
return TRUE ;
}
return FALSE ;
}
void
F_29 ( void )
{
static T_20 V_69 [] = {
{ & V_40 ,
{ L_7 , L_8 , V_70 , V_71 ,
NULL , 0x0 , NULL , V_72 } } ,
{ & V_41 ,
{ L_9 , L_10 , V_70 , V_71 ,
NULL , 0x0 , NULL , V_72 } } ,
{ & V_42 ,
{ L_11 , L_12 , V_70 , V_73 ,
NULL , 0x0 , NULL , V_72 } } ,
{ & V_43 ,
{ L_13 , L_14 , V_74 , V_71 ,
NULL , 0x0 , NULL , V_72 } } ,
{ & V_44 ,
{ L_15 , L_16 , V_74 , V_71 ,
NULL , 0x0f , NULL , V_72 } } ,
{ & V_61 ,
{ L_17 , L_18 , V_74 , V_71 ,
NULL , 0x1f , NULL , V_72 } } ,
{ & V_64 ,
{ L_7 , L_19 , V_70 , V_71 ,
NULL , 0x0 , NULL , V_72 } } ,
{ & V_65 ,
{ L_20 , L_21 , V_70 , V_73 ,
NULL , 0x0 , NULL , V_72 } } ,
{ & V_66 ,
{ L_22 , L_23 , V_74 , V_71 ,
F_30 ( V_75 ) , 0x0 , NULL , V_72 } } ,
{ & V_23 ,
{ L_24 , L_25 , V_74 , V_71 , F_30 ( V_22 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_6 ,
{ L_26 , L_27 , V_76 , V_71 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_8 ,
{ L_28 , L_29 , V_76 , V_73 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_9 ,
{ L_30 , L_31 , V_76 , V_73 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_10 ,
{ L_32 , L_33 , V_74 , V_73 , NULL , 0x0 ,
NULL , V_72 } } ,
} ;
static T_10 * V_77 [] = {
& V_33 ,
} ;
V_32 = F_31 ( L_6 , L_1 , L_34 ) ;
F_32 ( V_32 , V_69 , F_33 ( V_69 ) ) ;
F_34 ( V_77 , F_33 ( V_77 ) ) ;
F_35 ( L_34 , F_9 , V_32 ) ;
}
void
F_36 ( void )
{
T_21 V_78 ;
T_21 V_79 ;
V_78 = F_37 ( L_34 ) ;
F_38 ( L_35 , V_80 , V_78 ) ;
V_79 = F_39 ( F_4 , V_32 ) ;
F_38 ( L_36 , V_80 , V_79 ) ;
F_40 ( L_35 , F_26 , V_32 ) ;
}
