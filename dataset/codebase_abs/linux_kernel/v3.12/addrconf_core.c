static inline unsigned int F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_2 :
return ( F_2 ( V_2 ) |
V_3 ) ;
case V_4 :
return ( F_2 ( V_4 ) |
V_5 ) ;
case V_6 :
return ( F_2 ( V_6 ) |
V_7 ) ;
}
return F_2 ( V_1 ) ;
}
int F_3 ( const struct V_8 * V_9 )
{
T_1 V_10 ;
V_10 = V_9 -> V_11 [ 0 ] ;
if ( ( V_10 & F_4 ( 0xE0000000 ) ) != F_4 ( 0x00000000 ) &&
( V_10 & F_4 ( 0xE0000000 ) ) != F_4 ( 0xE0000000 ) )
return ( V_12 |
F_2 ( V_13 ) ) ;
if ( ( V_10 & F_4 ( 0xFF000000 ) ) == F_4 ( 0xFF000000 ) ) {
return ( V_14 |
F_1 ( F_5 ( V_9 ) ) ) ;
}
if ( ( V_10 & F_4 ( 0xFFC00000 ) ) == F_4 ( 0xFE800000 ) )
return ( V_5 | V_12 |
F_2 ( V_4 ) ) ;
if ( ( V_10 & F_4 ( 0xFFC00000 ) ) == F_4 ( 0xFEC00000 ) )
return ( V_7 | V_12 |
F_2 ( V_6 ) ) ;
if ( ( V_10 & F_4 ( 0xFE000000 ) ) == F_4 ( 0xFC000000 ) )
return ( V_12 |
F_2 ( V_13 ) ) ;
if ( ( V_9 -> V_11 [ 0 ] | V_9 -> V_11 [ 1 ] ) == 0 ) {
if ( V_9 -> V_11 [ 2 ] == 0 ) {
if ( V_9 -> V_11 [ 3 ] == 0 )
return V_15 ;
if ( V_9 -> V_11 [ 3 ] == F_4 ( 0x00000001 ) )
return ( V_3 | V_12 |
F_2 ( V_4 ) ) ;
return ( V_16 | V_12 |
F_2 ( V_13 ) ) ;
}
if ( V_9 -> V_11 [ 2 ] == F_4 ( 0x0000ffff ) )
return ( V_17 |
F_2 ( V_13 ) ) ;
}
return ( V_12 |
F_2 ( V_13 ) ) ;
}
int F_6 ( struct V_18 * V_19 )
{
return F_7 ( & V_20 , V_19 ) ;
}
int F_8 ( struct V_18 * V_19 )
{
return F_9 ( & V_20 , V_19 ) ;
}
int F_10 ( unsigned long V_21 , void * V_22 )
{
return F_11 ( & V_20 , V_21 , V_22 ) ;
}
static void F_12 ( struct V_23 * V_24 )
{
F_13 ( V_24 -> V_25 . V_26 ) ;
F_13 ( V_24 -> V_25 . V_27 ) ;
F_14 ( ( void V_28 * * ) V_24 -> V_25 . V_29 ) ;
}
void F_15 ( struct V_23 * V_24 )
{
struct V_30 * V_31 = V_24 -> V_31 ;
F_16 ( ! F_17 ( & V_24 -> V_32 ) ) ;
F_16 ( V_24 -> V_33 != NULL ) ;
F_16 ( F_18 ( & V_24 -> V_34 ) ) ;
#ifdef F_19
F_20 ( L_1 , V_35 , V_31 ? V_31 -> V_36 : L_2 ) ;
#endif
F_21 ( V_31 ) ;
if ( ! V_24 -> V_37 ) {
F_22 ( L_3 , V_24 ) ;
return;
}
F_12 ( V_24 ) ;
F_23 ( V_24 , V_38 ) ;
}
