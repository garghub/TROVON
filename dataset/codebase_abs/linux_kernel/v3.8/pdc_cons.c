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
F_9 ( & V_14 , V_11 ) ;
F_10 ( & V_15 , V_16 + V_17 ) ;
return 0 ;
}
static void F_11 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
if ( V_11 -> V_4 == 1 ) {
F_12 ( & V_15 ) ;
F_9 ( & V_14 , NULL ) ;
}
}
static int F_13 ( struct V_10 * V_11 , const unsigned char * V_18 , int V_4 )
{
F_1 ( NULL , V_18 , V_4 ) ;
return V_4 ;
}
static int F_14 ( struct V_10 * V_11 )
{
return 32768 ;
}
static int F_15 ( struct V_10 * V_11 )
{
return 0 ;
}
static void F_16 ( unsigned long V_19 )
{
int V_20 , V_4 = 0 ;
struct V_10 * V_11 = F_17 ( & V_14 ) ;
if ( ! V_11 )
return;
while ( 1 ) {
V_20 = F_5 ( NULL ) ;
if ( V_20 == - 1 )
break;
F_18 ( V_11 , V_20 & 0xFF , V_21 ) ;
V_4 ++ ;
}
if ( V_4 )
F_19 ( V_11 ) ;
F_20 ( V_11 ) ;
if ( V_22 . V_6 & V_23 )
F_10 ( & V_15 , V_16 + V_17 ) ;
}
static int T_1 F_21 ( void )
{
int V_24 ;
struct V_1 * V_25 ;
F_22 () ;
F_23 (tmp)
if ( V_25 == & V_22 )
break;
F_24 () ;
if ( ! V_25 ) {
F_25 ( V_26 L_1 , V_22 . V_27 ) ;
return - V_28 ;
}
F_25 ( V_26 L_2 ) ;
V_22 . V_6 &= ~ V_29 ;
V_30 = F_26 ( 1 ) ;
if ( ! V_30 )
return - V_31 ;
F_27 ( & V_14 ) ;
V_30 -> V_32 = L_3 ;
V_30 -> V_27 = L_4 ;
V_30 -> V_33 = V_34 ;
V_30 -> V_35 = 0 ;
V_30 -> type = V_36 ;
V_30 -> V_37 = V_38 ;
V_30 -> V_6 = V_39 |
V_40 ;
F_28 ( V_30 , & V_41 ) ;
F_29 ( & V_14 , V_30 , 0 ) ;
V_24 = F_30 ( V_30 ) ;
if ( V_24 ) {
F_25 ( V_42 L_5 ) ;
F_31 ( & V_14 ) ;
return V_24 ;
}
return 0 ;
}
static struct V_43 * F_32 ( struct V_1 * V_8 , int * V_44 )
{
* V_44 = V_8 -> V_44 ;
return V_30 ;
}
static void F_33 ( void )
{
if ( V_45 )
return;
++ V_45 ;
if ( V_46 -> V_47 . V_48 == V_49 )
memcpy ( & V_46 -> V_50 , & V_46 -> V_47 , sizeof( V_46 -> V_47 ) ) ;
F_34 ( & V_22 ) ;
}
void T_1 F_35 ( void )
{
#if F_36 ( V_51 ) || F_36 ( V_52 )
F_33 () ;
#endif
#ifdef V_51
F_25 ( V_26 L_6 ) ;
#endif
}
void F_37 ( void )
{
struct V_1 * V_1 ;
if ( V_45 )
return;
if ( V_53 != NULL )
V_22 . V_6 &= ~ V_54 ;
while ( ( V_1 = V_53 ) != NULL )
F_38 ( V_53 ) ;
F_33 () ;
}
