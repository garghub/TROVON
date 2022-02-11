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
return 0 ;
}
static void F_13 ( int V_24 , int V_25 )
{
union V_13 V_14 ;
int V_7 = F_14 ( V_26 , V_24 ) ;
V_14 . V_15 . V_16 = V_7 ;
V_14 . V_15 . V_17 = V_25 ;
V_14 . V_15 . V_18 = ( V_25 == V_27 ? V_28 : V_29 ) >> 8 ;
V_14 . V_15 . V_20 = 0 ;
F_12 ( V_21 , V_14 . V_22 ) ;
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
T_2 V_40 ;
T_3 V_41 = 1 ;
F_26 ( V_42 , V_39 ) ;
if ( F_2 ( V_4 ) ) {
F_3 ( V_5 , V_40 ) ;
V_41 = ( ( V_40 >> 3 ) & 7 ) + 1 ;
}
V_38 -> V_43 = V_39 / V_41 ;
}
static int T_1 F_27 ( void )
{
if ( ! V_44 )
return 0 ;
F_28 ( V_45 , V_46 ) ;
F_28 ( V_47 , V_48 ) ;
V_49 . F_25 = F_25 ;
V_50 . V_51 . V_52 = V_53 ;
return 0 ;
}
static int F_29 ( char * V_54 , char * V_55 )
{
if ( ! strncmp ( V_54 , L_1 , 6 ) ) {
V_44 = 1 ;
return 1 ;
}
return 0 ;
}
