static void F_1 ( struct V_1 * V_2 , const char * V_3 , unsigned V_4 )
{
int V_5 = 0 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
do {
V_5 += F_3 ( V_3 + V_5 , V_4 - V_5 ) ;
} while ( V_5 < V_4 );
F_4 ( & V_7 , V_6 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_8 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
V_8 = F_6 () ;
F_4 ( & V_7 , V_6 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 , char * V_9 )
{
return 0 ;
}
static int F_8 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
F_9 ( & V_14 , V_15 + V_16 ) ;
return 0 ;
}
static void F_10 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
if ( ! V_11 -> V_4 )
F_11 ( & V_14 ) ;
}
static int F_12 ( struct V_10 * V_11 , const unsigned char * V_17 , int V_4 )
{
F_1 ( NULL , V_17 , V_4 ) ;
return V_4 ;
}
static int F_13 ( struct V_10 * V_11 )
{
return 32768 ;
}
static int F_14 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_15 ( unsigned long V_18 )
{
int V_19 , V_4 = 0 ;
struct V_10 * V_11 = V_20 -> V_21 [ 0 ] ;
if ( ! V_11 )
return;
while ( 1 ) {
V_19 = F_5 ( NULL ) ;
if ( V_19 == - 1 )
break;
F_16 ( V_11 , V_19 & 0xFF , V_22 ) ;
V_4 ++ ;
}
if ( V_4 )
F_17 ( V_11 ) ;
if ( V_11 -> V_4 && ( V_23 . V_6 & V_24 ) )
F_9 ( & V_14 , V_15 + V_16 ) ;
}
static int T_1 F_18 ( void )
{
int V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_28 ;
F_19 () ;
F_20 (tmp)
if ( V_28 == & V_23 )
break;
F_21 () ;
if ( ! V_28 ) {
F_22 ( V_29 L_1 , V_23 . V_30 ) ;
return - V_31 ;
}
F_22 ( V_29 L_2 ) ;
V_23 . V_6 &= ~ V_32 ;
V_27 = F_23 ( 1 ) ;
if ( ! V_27 )
return - V_33 ;
V_27 -> V_34 = L_3 ;
V_27 -> V_30 = L_4 ;
V_27 -> V_35 = V_36 ;
V_27 -> V_37 = 0 ;
V_27 -> type = V_38 ;
V_27 -> V_39 = V_40 ;
V_27 -> V_6 = V_41 | V_42 ;
F_24 ( V_27 , & V_43 ) ;
V_25 = F_25 ( V_27 ) ;
if ( V_25 ) {
F_22 ( V_44 L_5 ) ;
return V_25 ;
}
V_20 = V_27 ;
F_26 ( & V_14 ) ;
V_14 . V_45 = F_15 ;
return 0 ;
}
static struct V_26 * F_27 ( struct V_1 * V_8 , int * V_46 )
{
* V_46 = V_8 -> V_46 ;
return V_20 ;
}
static void F_28 ( void )
{
if ( V_47 )
return;
++ V_47 ;
if ( V_48 -> V_49 . V_50 == V_51 )
memcpy ( & V_48 -> V_52 , & V_48 -> V_49 , sizeof( V_48 -> V_49 ) ) ;
F_29 ( & V_23 ) ;
}
void T_1 F_30 ( void )
{
#if F_31 ( V_53 ) || F_31 ( V_54 )
F_28 () ;
#endif
#ifdef V_53
F_22 ( V_29 L_6 ) ;
#endif
}
void F_32 ( void )
{
struct V_1 * V_1 ;
if ( V_47 )
return;
if ( V_55 != NULL )
V_23 . V_6 &= ~ V_56 ;
while ( ( V_1 = V_55 ) != NULL )
F_33 ( V_55 ) ;
F_28 () ;
}
