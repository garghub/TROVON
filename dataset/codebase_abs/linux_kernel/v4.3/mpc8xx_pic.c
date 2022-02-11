static inline unsigned long F_1 ( struct V_1 * V_2 )
{
return 0x80000000 >> F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_3 |= F_1 ( V_2 ) ;
F_4 ( & V_4 -> V_5 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_3 &= ~ F_1 ( V_2 ) ;
F_4 ( & V_4 -> V_5 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_4 ( & V_4 -> V_6 , F_1 ( V_2 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
V_3 |= F_1 ( V_2 ) ;
F_4 ( & V_4 -> V_5 , V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_7 )
{
if ( ( V_7 & V_8 ) && ! ( F_2 ( V_2 ) & 1 ) ) {
unsigned int V_9 = F_9 ( & V_4 -> V_10 ) ;
V_9 |= F_1 ( V_2 ) ;
F_4 ( & V_4 -> V_10 , V_9 ) ;
F_10 ( V_2 , V_11 ) ;
}
return 0 ;
}
unsigned int F_11 ( void )
{
int V_12 ;
V_12 = F_9 ( & V_4 -> V_13 ) >> 26 ;
if ( V_12 == V_14 )
V_12 = V_15 ;
return F_12 ( V_16 , V_12 ) ;
}
static int F_13 ( struct V_17 * V_18 , unsigned int V_19 ,
T_1 V_20 )
{
F_14 ( L_1 , V_19 , V_20 ) ;
F_15 ( V_19 , & V_21 , V_22 ) ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 , struct V_23 * V_24 ,
const T_2 * V_25 , unsigned int V_26 ,
T_1 * V_27 , unsigned int * V_28 )
{
static unsigned char V_29 [ 4 ] = {
V_30 ,
V_31 ,
V_32 ,
V_8 ,
} ;
if ( V_25 [ 0 ] > 0x1f )
return 0 ;
* V_27 = V_25 [ 0 ] ;
if ( V_26 > 1 && V_25 [ 1 ] < 4 )
* V_28 = V_29 [ V_25 [ 1 ] ] ;
else
* V_28 = V_33 ;
return 0 ;
}
int F_17 ( void )
{
struct V_34 V_35 ;
struct V_23 * V_36 ;
int V_37 ;
V_36 = F_18 ( NULL , NULL , L_2 ) ;
if ( V_36 == NULL )
V_36 = F_19 ( NULL , L_3 ) ;
if ( V_36 == NULL ) {
F_20 ( V_38 L_4 ) ;
return - V_39 ;
}
V_37 = F_21 ( V_36 , 0 , & V_35 ) ;
if ( V_37 )
goto V_40;
V_4 = F_22 ( V_35 . V_41 , F_23 ( & V_35 ) ) ;
if ( V_4 == NULL ) {
V_37 = - V_42 ;
goto V_40;
}
V_16 = F_24 ( V_36 , 64 , & V_43 , NULL ) ;
if ( V_16 == NULL ) {
F_20 ( V_38 L_5 ) ;
V_37 = - V_39 ;
goto V_40;
}
return 0 ;
V_40:
F_25 ( V_36 ) ;
return V_37 ;
}
