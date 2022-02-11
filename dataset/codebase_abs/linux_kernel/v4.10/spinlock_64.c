static inline T_1 F_1 ( void * V_1 )
{
return F_2 ( ( V_2 * ) V_1 , - 1 , - 1 ) ;
}
void F_3 ( T_2 * V_1 , T_1 V_3 )
{
if ( F_4 ( V_3 & V_4 ) ) {
F_5 ( & V_1 -> V_1 , ~ V_4 ) ;
V_3 &= ~ V_4 ;
}
for (; ; ) {
T_1 V_5 = F_1 ( V_1 ) ;
T_1 V_6 = V_3 - F_6 ( V_5 ) ;
if ( V_6 == 0 )
return;
F_7 ( ( 128 / V_7 ) * V_6 ) ;
}
}
int F_8 ( T_2 * V_1 )
{
T_1 V_5 = F_1 ( V_1 ) ;
if ( F_4 ( F_6 ( V_5 ) != F_9 ( V_5 ) ) )
return 0 ;
return F_10 ( & V_1 -> V_1 , V_5 , ( V_5 + 1 ) & ~ V_4 )
== V_5 ;
}
void F_11 ( T_2 * V_1 )
{
T_1 V_8 = 0 ;
T_1 V_5 = F_12 ( V_1 -> V_1 ) ;
T_1 V_9 = F_6 ( V_5 ) ;
if ( F_9 ( V_5 ) == V_9 )
return;
do {
F_13 ( V_8 ++ ) ;
} while ( F_6 ( F_12 ( V_1 -> V_1 ) ) == V_9 );
F_14 () ;
}
void F_15 ( T_3 * V_10 )
{
T_1 V_5 ;
int V_8 = 0 ;
do {
F_13 ( V_8 ++ ) ;
V_5 = F_16 ( & V_10 -> V_1 , 1 ) ;
} while ( F_4 ( F_17 ( V_5 ) ) );
}
void F_18 ( T_3 * V_10 , T_1 V_5 )
{
int V_8 = 0 ;
do {
if ( ! F_17 ( V_5 ) )
V_5 = F_5 ( & V_10 -> V_1 , ~ V_11 ) ;
F_13 ( V_8 ++ ) ;
V_5 = F_19 ( & V_10 -> V_1 , V_11 ) ;
} while ( V_5 != 0 );
}
