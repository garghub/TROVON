static unsigned int F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
unsigned int V_3 ;
F_2 ( V_4 , V_2 ) ;
V_3 = ( ( V_1 >> 24 ) & 0xffU ) | ( ( V_2 << 2 ) & 0xff00U ) ;
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
static int F_10 ( int V_10 , unsigned long V_11 )
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
F_23 ( V_34 , V_25 ) ;
}
static int T_1 F_24 ( void )
{
return V_35 == & V_36 ;
}
static void F_25 ( struct V_37 * V_38 , int V_39 )
{
if ( V_38 -> V_40 != V_39 ) {
V_38 -> V_40 = V_39 ;
F_14 ( V_41 , F_18 () ) = V_39 ;
}
}
static int T_1 F_26 ( void )
{
if ( ! V_42 )
return 0 ;
F_27 ( V_43 , V_44 ) ;
F_27 ( V_45 , V_46 ) ;
V_47 . F_25 = F_25 ;
V_48 . V_49 . V_50 = V_51 ;
return 0 ;
}
static int F_28 ( char * V_52 , char * V_53 )
{
if ( ! strncmp ( V_52 , L_1 , 6 ) ) {
V_42 = 1 ;
return 1 ;
}
return 0 ;
}
