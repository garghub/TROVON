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
static int F_6 ( void )
{
return F_7 ( F_4 () , V_6 ) ;
}
static int F_8 ( int V_7 , int V_8 )
{
return V_7 >> V_8 ;
}
static const struct V_9 * F_9 ( void )
{
return V_10 ;
}
static void F_10 ( int V_11 , struct V_9 * V_12 )
{
F_11 ( V_12 ) ;
F_12 ( V_11 , V_12 ) ;
}
static int T_1 F_13 ( int V_13 , unsigned long V_14 )
{
union V_15 V_16 ;
V_16 . V_17 . V_18 = V_13 ;
V_16 . V_17 . V_19 = 0 ;
V_16 . V_17 . V_20 = V_21 >> 8 ;
V_16 . V_17 . V_22 = 0 ;
F_14 ( V_23 , V_16 . V_24 ) ;
V_16 . V_17 . V_20 = V_25 >> 8 ;
V_16 . V_17 . V_19 = V_14 >> 12 ;
F_14 ( V_23 , V_16 . V_24 ) ;
F_15 ( & V_26 , 1 ) ;
return 0 ;
}
static void F_16 ( int V_11 , int V_27 )
{
union V_15 V_16 ;
int V_28 = F_17 ( V_29 , V_11 ) ;
V_16 . V_17 . V_18 = V_28 ;
V_16 . V_17 . V_19 = V_27 ;
V_16 . V_17 . V_20 = ( V_27 == V_30 ? V_31 : V_32 ) >> 8 ;
V_16 . V_17 . V_22 = 0 ;
F_14 ( V_23 , V_16 . V_24 ) ;
}
static void F_18 ( const struct V_9 * V_33 , int V_27 )
{
unsigned int V_11 ;
F_19 (cpu, mask)
F_16 ( V_11 , V_27 ) ;
}
static void F_20 ( const struct V_9 * V_33 ,
int V_27 )
{
unsigned int V_34 = F_21 () ;
unsigned int V_11 ;
F_19 (cpu, mask) {
if ( V_11 != V_34 )
F_16 ( V_11 , V_27 ) ;
}
}
static void F_22 ( int V_27 )
{
unsigned int V_34 = F_21 () ;
unsigned int V_11 ;
F_23 (cpu) {
if ( V_11 != V_34 )
F_16 ( V_11 , V_27 ) ;
}
}
static void F_24 ( int V_27 )
{
F_18 ( V_10 , V_27 ) ;
}
static void F_25 ( int V_27 )
{
F_26 ( V_35 , V_27 , V_36 ) ;
}
static unsigned int F_27 ( const struct V_9 * V_9 )
{
int V_11 ;
V_11 = F_28 ( V_9 ) ;
if ( F_29 ( ( unsigned ) V_11 < V_37 ) )
return F_17 ( V_29 , V_11 ) ;
return V_38 ;
}
static unsigned int
F_30 ( const struct V_9 * V_9 ,
const struct V_9 * V_39 )
{
int V_11 ;
F_31 (cpu, cpumask, andmask) {
if ( F_32 ( V_11 , V_10 ) )
break;
}
return F_17 ( V_29 , V_11 ) ;
}
static int T_2 F_33 ( void )
{
return V_40 == & V_41 ;
}
static void T_2 F_34 ( void )
{
F_35 ( V_42 L_1 ,
V_43 , V_43 + V_44 - 1 ) ;
F_36 ( V_43 , V_44 ) ;
F_35 ( V_42 L_2 ,
V_45 , V_45 + V_46 - 1 ) ;
F_36 ( V_45 , V_46 ) ;
}
static void F_37 ( struct V_47 * V_48 , int V_49 )
{
V_48 -> V_50 = V_49 ;
F_17 ( V_51 , F_21 () ) = V_49 ;
}
static int T_2 F_38 ( void )
{
unsigned int V_52 ;
if ( ! V_53 )
return 0 ;
V_54 . F_37 = F_37 ;
F_34 () ;
V_52 = F_39 ( V_55 ) ;
F_35 ( V_42 L_3 , V_52 ) ;
return 0 ;
}
static int F_40 ( char * V_56 , char * V_57 )
{
if ( ! strncmp ( V_56 , L_4 , 6 ) ) {
V_53 = 1 ;
return 1 ;
}
return 0 ;
}
