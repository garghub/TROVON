static unsigned int F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
unsigned int V_3 = ( V_1 >> 24 ) & 0xff ;
if ( F_2 ( V_4 ) ) {
F_3 ( V_5 , V_2 ) ;
V_3 |= ( V_2 << 2 ) & 0xff00 ;
}
return V_3 ;
}
static unsigned long F_4 ( unsigned int V_3 )
{
unsigned long V_1 ;
V_1 = ( ( V_3 & 0xffU ) << 24 ) ;
return V_1 ;
}
static unsigned int F_5 ( void )
{
return F_1 ( F_6 ( V_6 ) ) ;
}
static int F_7 ( int V_7 )
{
return 1 ;
}
static int F_8 ( void )
{
return F_9 ( F_5 () , V_8 ) ;
}
static int F_10 ( int V_9 , int V_10 )
{
return V_9 >> V_10 ;
}
static int F_11 ( int V_11 , unsigned long V_12 )
{
union V_13 V_14 ;
V_14 . V_15 . V_16 = V_11 ;
V_14 . V_15 . V_17 = 0 ;
V_14 . V_15 . V_18 = V_19 >> 8 ;
V_14 . V_15 . V_20 = 0 ;
F_12 ( V_21 , V_14 . V_22 ) ;
V_14 . V_15 . V_18 = V_23 >> 8 ;
V_14 . V_15 . V_17 = V_12 >> 12 ;
F_12 ( V_21 , V_14 . V_22 ) ;
F_13 ( & V_24 , 1 ) ;
return 0 ;
}
static void F_14 ( int V_25 , int V_26 )
{
union V_13 V_14 ;
int V_7 = F_15 ( V_27 , V_25 ) ;
V_14 . V_15 . V_16 = V_7 ;
V_14 . V_15 . V_17 = V_26 ;
V_14 . V_15 . V_18 = ( V_26 == V_28 ? V_29 : V_30 ) >> 8 ;
V_14 . V_15 . V_20 = 0 ;
F_12 ( V_21 , V_14 . V_22 ) ;
}
static void F_16 ( const struct V_31 * V_32 , int V_26 )
{
unsigned int V_25 ;
F_17 (cpu, mask)
F_14 ( V_25 , V_26 ) ;
}
static void F_18 ( const struct V_31 * V_32 ,
int V_26 )
{
unsigned int V_33 = F_19 () ;
unsigned int V_25 ;
F_17 (cpu, mask) {
if ( V_25 != V_33 )
F_14 ( V_25 , V_26 ) ;
}
}
static void F_20 ( int V_26 )
{
unsigned int V_33 = F_19 () ;
unsigned int V_25 ;
F_21 (cpu) {
if ( V_25 != V_33 )
F_14 ( V_25 , V_26 ) ;
}
}
static void F_22 ( int V_26 )
{
F_16 ( V_34 , V_26 ) ;
}
static void F_23 ( int V_26 )
{
F_24 ( V_35 , V_26 ) ;
}
static int T_1 F_25 ( void )
{
return V_36 == & V_37 ;
}
static void F_26 ( struct V_38 * V_39 , int V_40 )
{
T_2 V_41 ;
T_3 V_42 = 1 ;
F_27 ( V_43 , V_40 ) ;
if ( F_2 ( V_4 ) ) {
F_3 ( V_5 , V_41 ) ;
V_42 = ( ( V_41 >> 3 ) & 7 ) + 1 ;
}
V_39 -> V_44 = V_40 / V_42 ;
}
static int T_1 F_28 ( void )
{
if ( ! V_45 )
return 0 ;
F_29 ( V_46 , V_47 ) ;
F_29 ( V_48 , V_49 ) ;
V_50 . F_26 = F_26 ;
V_51 . V_52 . V_53 = V_54 ;
return 0 ;
}
static int F_30 ( char * V_55 , char * V_56 )
{
if ( ! strncmp ( V_55 , L_1 , 6 ) ) {
V_45 = 1 ;
return 1 ;
}
return 0 ;
}
