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
#if F_7 ( V_4 ) || F_7 ( V_5 )
V_1 = F_8 ( F_9 ( V_6 ) ) ;
#elif F_7 ( V_7 ) || F_7 ( V_8 )
V_1 = F_8 ( F_9 ( V_9 ) ) ;
#else
#error bus watcher being built for unknown Sibyte SOC!
#endif
if ( ! ( V_1 & 0x7fffffff ) ) {
F_2 ( L_4 ) ;
V_1 = V_10 . V_1 ;
V_2 = V_10 . V_2 ;
V_3 = V_10 . V_3 ;
} else {
V_2 = F_8 ( F_9 ( V_11 ) ) ;
V_3 = F_8 ( F_9 ( V_12 ) ) ;
}
if ( V_1 & ~ ( 1UL << 31 ) )
F_1 ( V_1 , V_2 , V_3 ) ;
else
F_2 ( L_5 ) ;
}
static int F_10 ( struct V_13 * V_14 , void * V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_11 ( V_14 , L_6 ) ;
F_11 ( V_14 , L_7 ) ;
F_12 ( V_14 , L_8 ,
V_17 -> V_19 , V_17 -> V_20 ) ;
F_12 ( V_14 , L_9 ,
V_17 -> V_21 , V_17 -> V_22 ) ;
F_12 ( V_14 , L_10 ,
V_17 -> V_23 , V_17 -> V_24 ) ;
F_12 ( V_14 , L_11 , V_17 -> V_25 ) ;
F_11 ( V_14 , L_2 ) ;
F_12 ( V_14 , L_3 ,
( unsigned int ) ( F_3 ( V_17 -> V_1 ) & 0x3f ) ,
( int ) ( F_3 ( V_17 -> V_1 ) >> 6 ) ,
( int ) F_4 ( V_17 -> V_1 ) ,
( int ) F_5 ( V_17 -> V_1 ) ) ;
if ( V_17 -> V_1 & V_26 )
F_11 ( V_14 , L_12 ) ;
if ( V_17 -> V_27 ) {
F_11 ( V_14 , L_13 ) ;
} else {
V_17 -> V_27 = 1 ;
}
return 0 ;
}
static int F_13 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
return F_14 ( V_29 , F_10 , F_15 ( V_28 ) ) ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_30 * V_31 ;
V_31 = F_17 ( L_14 , V_32 | V_33 , NULL ,
& V_34 , V_17 ) ;
if ( ! V_31 ) {
F_2 ( V_35 L_15 ) ;
return;
}
}
static T_3 F_18 ( int V_36 , void * V_37 )
{
struct V_16 * V_17 = V_37 ;
unsigned long V_38 ;
#ifdef F_19
int V_39 ;
#endif
#ifdef F_19
F_20 ( V_40 , F_9 ( V_41 ) ) ;
F_20 ( V_42 , F_9 ( V_41 ) ) ;
for ( V_39 = 0 ; V_39 < 256 * 6 ; V_39 ++ )
F_2 ( L_16 ,
( long long ) F_21 ( F_9 ( V_43 ) ) ) ;
F_20 ( V_44 , F_9 ( V_41 ) ) ;
F_20 ( V_45 , F_9 ( V_41 ) ) ;
#endif
V_17 -> V_1 = F_8 ( F_9 ( V_46 ) ) ;
V_17 -> V_27 = 0 ;
V_17 -> V_2 = V_38 = F_8 ( F_9 ( V_11 ) ) ;
V_17 -> V_19 += F_22 ( V_38 ) ;
V_17 -> V_20 += F_23 ( V_38 ) ;
V_17 -> V_21 += F_24 ( V_38 ) ;
V_17 -> V_22 += F_25 ( V_38 ) ;
F_20 ( 0 , F_9 ( V_11 ) ) ;
V_17 -> V_3 = V_38 = F_8 ( F_9 ( V_12 ) ) ;
V_17 -> V_23 += F_26 ( V_38 ) ;
V_17 -> V_24 += F_27 ( V_38 ) ;
V_17 -> V_25 += F_28 ( V_38 ) ;
F_20 ( 0 , F_9 ( V_12 ) ) ;
return V_47 ;
}
int T_4 F_29 ( void )
{
memset ( & V_10 , 0 , sizeof( struct V_16 ) ) ;
V_10 . V_27 = 1 ;
if ( F_30 ( V_48 , F_18 , 0 , L_17 , & V_10 ) ) {
F_2 ( L_18 ) ;
return - 1 ;
}
if ( F_30 ( V_49 , F_18 , 0 , L_17 , & V_10 ) ) {
F_31 ( V_48 , & V_10 ) ;
F_2 ( L_19 ) ;
return - 1 ;
}
if ( F_30 ( V_50 , F_18 , 0 , L_17 , & V_10 ) ) {
F_31 ( V_48 , & V_10 ) ;
F_31 ( V_49 , & V_10 ) ;
F_2 ( L_20 ) ;
return - 1 ;
}
#ifdef F_32
F_16 ( & V_10 ) ;
#endif
#ifdef F_19
F_20 ( ( V_51 | V_52 |
V_53 ) ,
F_9 ( V_54 ) ) ;
F_20 ( V_44 , F_9 ( V_41 ) ) ;
F_20 ( V_45 , F_9 ( V_41 ) ) ;
#endif
return 0 ;
}
