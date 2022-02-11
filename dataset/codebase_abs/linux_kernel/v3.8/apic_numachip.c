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
static int T_1 F_10 ( int V_10 , unsigned long V_11 )
{
union V_12 V_13 ;
V_13 . V_14 . V_15 = V_10 ;
V_13 . V_14 . V_16 = 0 ;
V_13 . V_14 . V_17 = V_18 >> 8 ;
V_13 . V_14 . V_19 = 0 ;
F_11 ( V_20 , V_13 . V_21 ) ;
V_13 . V_14 . V_17 = V_22 >> 8 ;
V_13 . V_14 . V_16 = V_11 >> 12 ;
F_11 ( V_20 , V_13 . V_21 ) ;
F_12 ( & V_23 , 1 ) ;
return 0 ;
}
static void F_13 ( int V_24 , int V_25 )
{
union V_12 V_13 ;
int V_6 = F_14 ( V_26 , V_24 ) ;
V_13 . V_14 . V_15 = V_6 ;
V_13 . V_14 . V_16 = V_25 ;
V_13 . V_14 . V_17 = ( V_25 == V_27 ? V_28 : V_29 ) >> 8 ;
V_13 . V_14 . V_19 = 0 ;
F_11 ( V_20 , V_13 . V_21 ) ;
}
static void F_15 ( const struct V_30 * V_31 , int V_25 )
{
unsigned int V_24 ;
F_16 (cpu, mask)
F_13 ( V_24 , V_25 ) ;
}
static void F_17 ( const struct V_30 * V_31 ,
int V_25 )
{
unsigned int V_32 = F_18 () ;
unsigned int V_24 ;
F_16 (cpu, mask) {
if ( V_24 != V_32 )
F_13 ( V_24 , V_25 ) ;
}
}
static void F_19 ( int V_25 )
{
unsigned int V_32 = F_18 () ;
unsigned int V_24 ;
F_20 (cpu) {
if ( V_24 != V_32 )
F_13 ( V_24 , V_25 ) ;
}
}
static void F_21 ( int V_25 )
{
F_15 ( V_33 , V_25 ) ;
}
static void F_22 ( int V_25 )
{
F_23 ( V_34 , V_25 , V_35 ) ;
}
static int T_2 F_24 ( void )
{
return V_36 == & V_37 ;
}
static void T_2 F_25 ( void )
{
F_26 ( V_38 L_1 ,
V_39 , V_39 + V_40 - 1 ) ;
F_27 ( V_39 , V_40 ) ;
F_26 ( V_38 L_2 ,
V_41 , V_41 + V_42 - 1 ) ;
F_27 ( V_41 , V_42 ) ;
}
static void F_28 ( struct V_43 * V_44 , int V_45 )
{
if ( V_44 -> V_46 != V_45 ) {
V_44 -> V_46 = V_45 ;
F_14 ( V_47 , F_18 () ) = V_45 ;
}
}
static int T_2 F_29 ( void )
{
unsigned int V_48 ;
if ( ! V_49 )
return 0 ;
V_50 . F_28 = F_28 ;
V_51 . V_52 . V_53 = V_54 ;
F_25 () ;
V_48 = F_30 ( V_55 ) ;
F_26 ( V_38 L_3 , V_48 ) ;
return 0 ;
}
static int F_31 ( char * V_56 , char * V_57 )
{
if ( ! strncmp ( V_56 , L_4 , 6 ) ) {
V_49 = 1 ;
return 1 ;
}
return 0 ;
}
