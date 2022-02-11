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
#elif F_10 ( V_5 ) || F_10 ( V_6 )
V_1 = F_8 ( F_9 ( V_7 ) ) ;
#elif F_10 ( V_8 ) || F_10 ( V_9 )
V_1 = F_8 ( F_9 ( V_10 ) ) ;
#else
#error bus watcher being built for unknown Sibyte SOC!
#endif
if ( ! ( V_1 & 0x7fffffff ) ) {
F_2 ( L_4 ) ;
V_1 = V_11 . V_1 ;
V_2 = V_11 . V_2 ;
V_3 = V_11 . V_3 ;
} else {
V_2 = F_8 ( F_9 ( V_12 ) ) ;
V_3 = F_8 ( F_9 ( V_13 ) ) ;
}
if ( V_1 & ~ ( 1UL << 31 ) )
F_1 ( V_1 , V_2 , V_3 ) ;
else
F_2 ( L_5 ) ;
}
static int F_11 ( struct V_14 * V_15 , void * V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
F_12 ( V_15 , L_6 ) ;
F_12 ( V_15 , L_7 ) ;
F_13 ( V_15 , L_8 ,
V_18 -> V_20 , V_18 -> V_21 ) ;
F_13 ( V_15 , L_9 ,
V_18 -> V_22 , V_18 -> V_23 ) ;
F_13 ( V_15 , L_10 ,
V_18 -> V_24 , V_18 -> V_25 ) ;
F_13 ( V_15 , L_11 , V_18 -> V_26 ) ;
F_12 ( V_15 , L_2 ) ;
F_13 ( V_15 , L_3 ,
( unsigned int ) ( F_3 ( V_18 -> V_1 ) & 0x3f ) ,
( int ) ( F_3 ( V_18 -> V_1 ) >> 6 ) ,
( int ) F_4 ( V_18 -> V_1 ) ,
( int ) F_5 ( V_18 -> V_1 ) ) ;
if ( V_18 -> V_1 & V_27 )
F_12 ( V_15 , L_12 ) ;
if ( V_18 -> V_28 ) {
F_12 ( V_15 , L_13 ) ;
} else {
V_18 -> V_28 = 1 ;
}
return 0 ;
}
static int F_14 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
return F_15 ( V_30 , F_11 , F_16 ( V_29 ) ) ;
}
static void F_17 ( struct V_17 * V_18 )
{
struct V_31 * V_32 ;
V_32 = F_18 ( L_14 , V_33 | V_34 , NULL ,
& V_35 , V_18 ) ;
if ( ! V_32 ) {
F_2 ( V_36 L_15 ) ;
return;
}
}
static T_3 F_19 ( int V_37 , void * V_38 )
{
struct V_17 * V_18 = V_38 ;
unsigned long V_39 ;
#ifdef F_20
int V_40 ;
#endif
#ifdef F_20
F_21 ( V_41 , F_9 ( V_42 ) ) ;
F_21 ( V_43 , F_9 ( V_42 ) ) ;
for ( V_40 = 0 ; V_40 < 256 * 6 ; V_40 ++ )
F_2 ( L_16 ,
( long long ) F_22 ( F_9 ( V_44 ) ) ) ;
F_21 ( V_45 , F_9 ( V_42 ) ) ;
F_21 ( V_46 , F_9 ( V_42 ) ) ;
#endif
V_18 -> V_1 = F_8 ( F_9 ( V_4 ) ) ;
V_18 -> V_28 = 0 ;
V_18 -> V_2 = V_39 = F_8 ( F_9 ( V_12 ) ) ;
V_18 -> V_20 += F_23 ( V_39 ) ;
V_18 -> V_21 += F_24 ( V_39 ) ;
V_18 -> V_22 += F_25 ( V_39 ) ;
V_18 -> V_23 += F_26 ( V_39 ) ;
F_21 ( 0 , F_9 ( V_12 ) ) ;
V_18 -> V_3 = V_39 = F_8 ( F_9 ( V_13 ) ) ;
V_18 -> V_24 += F_27 ( V_39 ) ;
V_18 -> V_25 += F_28 ( V_39 ) ;
V_18 -> V_26 += F_29 ( V_39 ) ;
F_21 ( 0 , F_9 ( V_13 ) ) ;
return V_47 ;
}
int T_4 F_30 ( void )
{
memset ( & V_11 , 0 , sizeof( struct V_17 ) ) ;
V_11 . V_28 = 1 ;
if ( F_31 ( V_48 , F_19 , 0 , L_17 , & V_11 ) ) {
F_2 ( L_18 ) ;
return - 1 ;
}
if ( F_31 ( V_49 , F_19 , 0 , L_17 , & V_11 ) ) {
F_32 ( V_48 , & V_11 ) ;
F_2 ( L_19 ) ;
return - 1 ;
}
if ( F_31 ( V_50 , F_19 , 0 , L_17 , & V_11 ) ) {
F_32 ( V_48 , & V_11 ) ;
F_32 ( V_49 , & V_11 ) ;
F_2 ( L_20 ) ;
return - 1 ;
}
#ifdef F_33
F_17 ( & V_11 ) ;
#endif
#ifdef F_20
F_21 ( ( V_51 | V_52 |
V_53 ) ,
F_9 ( V_54 ) ) ;
F_21 ( V_45 , F_9 ( V_42 ) ) ;
F_21 ( V_46 , F_9 ( V_42 ) ) ;
#endif
return 0 ;
}
