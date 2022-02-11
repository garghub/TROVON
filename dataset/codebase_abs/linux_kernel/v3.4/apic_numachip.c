static unsigned int F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
unsigned int V_3 ;
F_2 ( V_4 , V_2 ) ;
V_3 = ( ( V_1 >> 24 ) & 0xffU ) | ( ( V_2 << 2 ) & 0x3f00U ) ;
return V_3 ;
}
static unsigned long F_3 ( unsigned int V_3 )
{
unsigned long V_1 ;
V_1 = ( ( V_3 & 0xffU ) << 24 ) ;
return V_1 ;
}
static unsigned int F_4 ( void )
{
return F_1 ( F_5 ( V_5 ) ) ;
}
static int F_6 ( int V_6 )
{
return 1 ;
}
static int F_7 ( void )
{
return F_8 ( F_4 () , V_7 ) ;
}
static int F_9 ( int V_8 , int V_9 )
{
return V_8 >> V_9 ;
}
static const struct V_10 * F_10 ( void )
{
return V_11 ;
}
static void F_11 ( int V_12 , struct V_10 * V_13 )
{
F_12 ( V_13 ) ;
F_13 ( V_12 , V_13 ) ;
}
static int T_1 F_14 ( int V_14 , unsigned long V_15 )
{
union V_16 V_17 ;
V_17 . V_18 . V_19 = V_14 ;
V_17 . V_18 . V_20 = 0 ;
V_17 . V_18 . V_21 = V_22 >> 8 ;
V_17 . V_18 . V_23 = 0 ;
F_15 ( V_24 , V_17 . V_25 ) ;
V_17 . V_18 . V_21 = V_26 >> 8 ;
V_17 . V_18 . V_20 = V_15 >> 12 ;
F_15 ( V_24 , V_17 . V_25 ) ;
F_16 ( & V_27 , 1 ) ;
return 0 ;
}
static void F_17 ( int V_12 , int V_28 )
{
union V_16 V_17 ;
int V_6 = F_18 ( V_29 , V_12 ) ;
V_17 . V_18 . V_19 = V_6 ;
V_17 . V_18 . V_20 = V_28 ;
V_17 . V_18 . V_21 = ( V_28 == V_30 ? V_31 : V_32 ) >> 8 ;
V_17 . V_18 . V_23 = 0 ;
F_15 ( V_24 , V_17 . V_25 ) ;
}
static void F_19 ( const struct V_10 * V_33 , int V_28 )
{
unsigned int V_12 ;
F_20 (cpu, mask)
F_17 ( V_12 , V_28 ) ;
}
static void F_21 ( const struct V_10 * V_33 ,
int V_28 )
{
unsigned int V_34 = F_22 () ;
unsigned int V_12 ;
F_20 (cpu, mask) {
if ( V_12 != V_34 )
F_17 ( V_12 , V_28 ) ;
}
}
static void F_23 ( int V_28 )
{
unsigned int V_34 = F_22 () ;
unsigned int V_12 ;
F_24 (cpu) {
if ( V_12 != V_34 )
F_17 ( V_12 , V_28 ) ;
}
}
static void F_25 ( int V_28 )
{
F_19 ( V_11 , V_28 ) ;
}
static void F_26 ( int V_28 )
{
F_27 ( V_35 , V_28 , V_36 ) ;
}
static unsigned int F_28 ( const struct V_10 * V_10 )
{
int V_12 ;
V_12 = F_29 ( V_10 ) ;
if ( F_30 ( ( unsigned ) V_12 < V_37 ) )
return F_18 ( V_29 , V_12 ) ;
return V_38 ;
}
static unsigned int
F_31 ( const struct V_10 * V_10 ,
const struct V_10 * V_39 )
{
int V_12 ;
F_32 (cpu, cpumask, andmask) {
if ( F_33 ( V_12 , V_11 ) )
break;
}
return F_18 ( V_29 , V_12 ) ;
}
static int T_2 F_34 ( void )
{
return V_40 == & V_41 ;
}
static void T_2 F_35 ( void )
{
F_36 ( V_42 L_1 ,
V_43 , V_43 + V_44 - 1 ) ;
F_37 ( V_43 , V_44 ) ;
F_36 ( V_42 L_2 ,
V_45 , V_45 + V_46 - 1 ) ;
F_37 ( V_45 , V_46 ) ;
}
static void F_38 ( struct V_47 * V_48 , int V_49 )
{
if ( V_48 -> V_50 != V_49 ) {
V_48 -> V_50 = V_49 ;
F_18 ( V_51 , F_22 () ) = V_49 ;
}
}
static int T_2 F_39 ( void )
{
unsigned int V_52 ;
if ( ! V_53 )
return 0 ;
V_54 . F_38 = F_38 ;
F_35 () ;
V_52 = F_40 ( V_55 ) ;
F_36 ( V_42 L_3 , V_52 ) ;
return 0 ;
}
static int F_41 ( char * V_56 , char * V_57 )
{
if ( ! strncmp ( V_56 , L_4 , 6 ) ) {
V_53 = 1 ;
return 1 ;
}
return 0 ;
}
