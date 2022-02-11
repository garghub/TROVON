static void F_1 ( T_1 V_1 , T_1 V_2 ,
T_1 V_3 )
{
F_2 ( L_1 , V_2 , V_3 ) ;
F_2 ( L_2 ) ;
F_2 ( L_3 ,
( unsigned int ) ( F_3 ( V_1 ) & 0x3f ) ,
( int ) ( F_3 ( V_1 ) >> 6 ) ,
( int ) F_4 ( V_1 ) ,
( int ) F_5 ( V_1 ) ) ;
}
void F_6 ( void )
{
T_2 V_1 , V_2 , V_3 ;
#ifdef F_7
V_1 = F_8 ( F_9 ( V_4 ) ) ;
#else
V_1 = F_8 ( F_9 ( V_5 ) ) ;
#endif
if ( ! ( V_1 & 0x7fffffff ) ) {
F_2 ( L_4 ) ;
V_1 = V_6 . V_1 ;
V_2 = V_6 . V_2 ;
V_3 = V_6 . V_3 ;
} else {
V_2 = F_8 ( F_9 ( V_7 ) ) ;
V_3 = F_8 ( F_9 ( V_8 ) ) ;
}
if ( V_1 & ~ ( 1UL << 31 ) )
F_1 ( V_1 , V_2 , V_3 ) ;
else
F_2 ( L_5 ) ;
}
static int F_10 ( char * V_9 , struct V_10 * V_11 )
{
int V_12 ;
V_12 = sprintf ( V_9 , L_6 ) ;
V_12 += sprintf ( V_9 + V_12 , L_7 ) ;
V_12 += sprintf ( V_9 + V_12 , L_8 ,
V_11 -> V_13 , V_11 -> V_14 ) ;
V_12 += sprintf ( V_9 + V_12 , L_9 ,
V_11 -> V_15 , V_11 -> V_16 ) ;
V_12 += sprintf ( V_9 + V_12 , L_10 ,
V_11 -> V_17 , V_11 -> V_18 ) ;
V_12 += sprintf ( V_9 + V_12 , L_11 , V_11 -> V_19 ) ;
V_12 += sprintf ( V_9 + V_12 , L_2 ) ;
V_12 += sprintf ( V_9 + V_12 , L_3 ,
( unsigned int ) ( F_3 ( V_11 -> V_1 ) & 0x3f ) ,
( int ) ( F_3 ( V_11 -> V_1 ) >> 6 ) ,
( int ) F_4 ( V_11 -> V_1 ) ,
( int ) F_5 ( V_11 -> V_1 ) ) ;
if ( V_11 -> V_1 & V_20 )
V_12 += sprintf ( V_9 + V_12 , L_12 ) ;
if ( V_11 -> V_21 ) {
V_12 += sprintf ( V_9 + V_12 , L_13 ) ;
} else {
V_11 -> V_21 = 1 ;
}
return V_12 ;
}
static int F_11 ( char * V_9 , char * * V_22 , T_3 V_23 ,
int V_24 , int * V_25 , void * V_26 )
{
int V_12 ;
if ( V_23 == 0 ) {
V_12 = F_10 ( V_9 , V_26 ) ;
* V_22 = V_9 ;
} else {
V_12 = 0 ;
* V_25 = 1 ;
}
return V_12 ;
}
static void F_12 ( struct V_10 * V_11 )
{
struct V_27 * V_28 ;
V_28 = F_13 ( L_14 , V_29 | V_30 , NULL ,
F_11 , V_11 ) ;
if ( ! V_28 ) {
F_2 ( V_31 L_15 ) ;
return;
}
}
static T_4 F_14 ( int V_32 , void * V_26 )
{
struct V_10 * V_11 = V_26 ;
unsigned long V_33 ;
#ifdef F_15
int V_34 ;
#endif
#ifndef F_16
char V_35 [ 1024 ] ;
#endif
#ifdef F_15
F_17 ( V_36 , F_9 ( V_37 ) ) ;
F_17 ( V_38 , F_9 ( V_37 ) ) ;
for ( V_34 = 0 ; V_34 < 256 * 6 ; V_34 ++ )
F_2 ( L_16 ,
( long long ) F_18 ( F_9 ( V_39 ) ) ) ;
F_17 ( V_40 , F_9 ( V_37 ) ) ;
F_17 ( V_41 , F_9 ( V_37 ) ) ;
#endif
V_11 -> V_1 = F_8 ( F_9 ( V_4 ) ) ;
V_11 -> V_21 = 0 ;
V_11 -> V_2 = V_33 = F_8 ( F_9 ( V_7 ) ) ;
V_11 -> V_13 += F_19 ( V_33 ) ;
V_11 -> V_14 += F_20 ( V_33 ) ;
V_11 -> V_15 += F_21 ( V_33 ) ;
V_11 -> V_16 += F_22 ( V_33 ) ;
F_17 ( 0 , F_9 ( V_7 ) ) ;
V_11 -> V_3 = V_33 = F_8 ( F_9 ( V_8 ) ) ;
V_11 -> V_17 += F_23 ( V_33 ) ;
V_11 -> V_18 += F_24 ( V_33 ) ;
V_11 -> V_19 += F_25 ( V_33 ) ;
F_17 ( 0 , F_9 ( V_8 ) ) ;
#ifndef F_16
F_10 ( V_35 , V_11 ) ;
F_2 ( V_35 ) ;
#endif
return V_42 ;
}
int T_5 F_26 ( void )
{
memset ( & V_6 , 0 , sizeof( struct V_10 ) ) ;
V_6 . V_21 = 1 ;
if ( F_27 ( V_43 , F_14 , 0 , L_17 , & V_6 ) ) {
F_2 ( L_18 ) ;
return - 1 ;
}
if ( F_27 ( V_44 , F_14 , 0 , L_17 , & V_6 ) ) {
F_28 ( V_43 , & V_6 ) ;
F_2 ( L_19 ) ;
return - 1 ;
}
if ( F_27 ( V_45 , F_14 , 0 , L_17 , & V_6 ) ) {
F_28 ( V_43 , & V_6 ) ;
F_28 ( V_44 , & V_6 ) ;
F_2 ( L_20 ) ;
return - 1 ;
}
#ifdef F_16
F_12 ( & V_6 ) ;
#endif
#ifdef F_15
F_17 ( ( V_46 | V_47 |
V_48 ) ,
F_9 ( V_49 ) ) ;
F_17 ( V_40 , F_9 ( V_37 ) ) ;
F_17 ( V_41 , F_9 ( V_37 ) ) ;
#endif
return 0 ;
}
