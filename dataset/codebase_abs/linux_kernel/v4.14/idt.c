static inline void F_1 ( T_1 * V_1 , const struct V_2 * V_3 )
{
unsigned long V_4 = ( unsigned long ) V_3 -> V_4 ;
V_1 -> V_5 = ( V_6 ) V_4 ;
V_1 -> V_7 = ( V_6 ) V_3 -> V_7 ;
V_1 -> V_8 = V_3 -> V_8 ;
V_1 -> V_9 = ( V_6 ) ( V_4 >> 16 ) ;
#ifdef F_2
V_1 -> V_10 = ( V_11 ) ( V_4 >> 32 ) ;
V_1 -> V_12 = 0 ;
#endif
}
static void
F_3 ( T_1 * V_13 , const struct V_2 * V_14 , int V_15 , bool V_16 )
{
T_1 V_17 ;
for (; V_15 > 0 ; V_14 ++ , V_15 -- ) {
F_1 ( & V_17 , V_14 ) ;
F_4 ( V_13 , V_14 -> V_18 , & V_17 ) ;
if ( V_16 )
F_5 ( V_14 -> V_18 , V_19 ) ;
}
}
static void F_6 ( unsigned int V_20 , const void * V_4 )
{
struct V_2 V_21 ;
F_7 ( V_20 > 0xFF ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_18 = V_20 ;
V_21 . V_4 = V_4 ;
V_21 . V_7 = V_22 ;
V_21 . V_8 . type = V_23 ;
V_21 . V_8 . V_24 = 1 ;
F_3 ( V_25 , & V_21 , 1 , false ) ;
}
void T_2 F_8 ( void )
{
F_3 ( V_25 , V_26 , F_9 ( V_26 ) ,
true ) ;
F_10 ( & V_27 ) ;
}
void T_2 F_11 ( void )
{
F_3 ( V_25 , V_28 , F_9 ( V_28 ) , true ) ;
}
void T_2 F_12 ( void )
{
F_3 ( V_25 , V_29 ,
F_9 ( V_29 ) , true ) ;
}
void T_2 F_13 ( void )
{
F_3 ( V_25 , V_30 , F_9 ( V_30 ) , true ) ;
}
void T_2 F_14 ( void )
{
memcpy ( & V_31 , & V_25 , V_32 * 16 ) ;
F_3 ( V_31 , V_33 , F_9 ( V_33 ) , false ) ;
}
void T_2 F_15 ( void )
{
int V_34 = V_35 ;
void * V_36 ;
F_3 ( V_25 , V_37 , F_9 ( V_37 ) , true ) ;
F_16 (i, used_vectors, FIRST_SYSTEM_VECTOR) {
V_36 = V_38 + 8 * ( V_34 - V_35 ) ;
F_6 ( V_34 , V_36 ) ;
}
F_16 (i, used_vectors, NR_VECTORS) {
#ifdef F_17
F_5 ( V_34 , V_19 ) ;
F_6 ( V_34 , V_39 ) ;
#else
V_36 = V_38 + 8 * ( V_34 - V_35 ) ;
F_6 ( V_34 , V_36 ) ;
#endif
}
}
void T_2 F_18 ( void )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_40 ; V_34 ++ )
F_6 ( V_34 , V_41 [ V_34 ] ) ;
#ifdef F_19
for ( ; V_34 < V_42 ; V_34 ++ )
F_6 ( V_34 , V_43 ) ;
#endif
F_10 ( & V_27 ) ;
}
void F_20 ( void * V_4 )
{
struct V_44 V_13 = { . V_45 = ( unsigned long ) V_4 , . V_15 = 0 } ;
F_10 ( & V_13 ) ;
}
void T_2 F_21 ( unsigned int V_20 , const void * V_4 )
{
if ( F_22 ( ! F_23 ( V_20 , V_19 ) ) )
return;
F_6 ( V_20 , V_4 ) ;
}
void F_24 ( unsigned int V_20 , const void * V_4 )
{
F_7 ( V_20 < V_46 ) ;
if ( ! F_25 ( V_20 , V_19 ) )
F_6 ( V_20 , V_4 ) ;
}
