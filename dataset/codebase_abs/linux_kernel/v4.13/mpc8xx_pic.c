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
return 0 ;
return F_12 ( V_15 , V_12 ) ;
}
static int F_13 ( struct V_16 * V_17 , unsigned int V_18 ,
T_1 V_19 )
{
F_14 ( L_1 , V_18 , V_19 ) ;
F_15 ( V_18 , & V_20 , V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 , struct V_22 * V_23 ,
const T_2 * V_24 , unsigned int V_25 ,
T_1 * V_26 , unsigned int * V_27 )
{
static unsigned char V_28 [ 4 ] = {
V_29 ,
V_30 ,
V_31 ,
V_8 ,
} ;
if ( V_24 [ 0 ] > 0x1f )
return 0 ;
* V_26 = V_24 [ 0 ] ;
if ( V_25 > 1 && V_24 [ 1 ] < 4 )
* V_27 = V_28 [ V_24 [ 1 ] ] ;
else
* V_27 = V_32 ;
return 0 ;
}
int F_17 ( void )
{
struct V_33 V_34 ;
struct V_22 * V_35 ;
int V_36 ;
V_35 = F_18 ( NULL , NULL , L_2 ) ;
if ( V_35 == NULL )
V_35 = F_19 ( NULL , L_3 ) ;
if ( V_35 == NULL ) {
F_20 ( V_37 L_4 ) ;
return - V_38 ;
}
V_36 = F_21 ( V_35 , 0 , & V_34 ) ;
if ( V_36 )
goto V_39;
V_4 = F_22 ( V_34 . V_40 , F_23 ( & V_34 ) ) ;
if ( V_4 == NULL ) {
V_36 = - V_41 ;
goto V_39;
}
V_15 = F_24 ( V_35 , 64 , & V_42 , NULL ) ;
if ( V_15 == NULL ) {
F_20 ( V_37 L_5 ) ;
V_36 = - V_38 ;
goto V_39;
}
return 0 ;
V_39:
F_25 ( V_35 ) ;
return V_36 ;
}
