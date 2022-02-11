static int F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 = 0x00 ;
if ( F_2 ( V_2 -> V_4 , V_5 , 0x08 ) < 0 ||
F_2 ( V_2 -> V_4 , V_6 , 0x05 ) < 0 )
return - V_7 ;
return F_3 ( V_2 -> V_4 , V_8 ,
2 , ( unsigned char * ) & V_3 ) ;
}
static int F_4 ( struct V_9 * V_10 )
{
unsigned char V_11 [ 2 ] ;
if ( ! V_10 -> V_2 . V_4 )
return - V_12 ;
if ( V_10 -> V_13 > V_14 )
V_11 [ 0 ] = V_14 ;
else
V_11 [ 0 ] = V_10 -> V_13 ;
if ( V_10 -> V_15 > V_14 )
V_11 [ 1 ] = V_14 ;
else
V_11 [ 1 ] = V_10 -> V_15 ;
V_11 [ 1 ] |= V_10 -> V_16 ? 0x40 : 0 ;
if ( F_3 ( V_10 -> V_2 . V_4 , V_8 ,
2 , V_11 ) < 0 ) {
F_5 ( V_17 L_1 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_6 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_19 ) ;
struct V_9 * V_10 ;
if ( ! ( V_10 = V_23 -> V_24 ) )
return - V_12 ;
V_21 -> V_25 . integer . V_25 [ 0 ] = V_10 -> V_16 ? 1 : 0 ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_19 ) ;
struct V_9 * V_10 ;
int V_26 ;
if ( ! ( V_10 = V_23 -> V_24 ) )
return - V_12 ;
V_26 = V_10 -> V_16 != V_21 -> V_25 . integer . V_25 [ 0 ] ;
if ( V_26 ) {
V_10 -> V_16 = ! ! V_21 -> V_25 . integer . V_25 [ 0 ] ;
F_4 ( V_10 ) ;
}
return V_26 ;
}
static int F_9 ( struct V_18 * V_19 ,
struct V_27 * V_28 )
{
V_28 -> type = V_29 ;
V_28 -> V_30 = 2 ;
V_28 -> V_25 . integer . V_31 = 0 ;
V_28 -> V_25 . integer . V_32 = V_14 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_19 ) ;
struct V_9 * V_10 ;
if ( ! ( V_10 = V_23 -> V_24 ) )
return - V_12 ;
V_21 -> V_25 . integer . V_25 [ 0 ] = V_10 -> V_13 ;
V_21 -> V_25 . integer . V_25 [ 1 ] = V_10 -> V_15 ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_19 ) ;
struct V_9 * V_10 ;
unsigned int V_33 [ 2 ] ;
int V_26 ;
if ( ! ( V_10 = V_23 -> V_24 ) )
return - V_12 ;
V_33 [ 0 ] = V_21 -> V_25 . integer . V_25 [ 0 ] ;
V_33 [ 1 ] = V_21 -> V_25 . integer . V_25 [ 1 ] ;
if ( V_33 [ 0 ] > V_14 || V_33 [ 1 ] > V_14 )
return - V_7 ;
V_26 = V_10 -> V_13 != V_33 [ 0 ] ||
V_10 -> V_15 != V_33 [ 1 ] ;
if ( V_26 ) {
V_10 -> V_13 = V_33 [ 0 ] ;
V_10 -> V_15 = V_33 [ 1 ] ;
F_4 ( V_10 ) ;
}
return V_26 ;
}
static int F_12 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_19 ) ;
struct V_9 * V_10 ;
if ( ! ( V_10 = V_23 -> V_24 ) )
return - V_12 ;
V_21 -> V_25 . integer . V_25 [ 0 ] = V_10 -> V_34 ? 1 : 0 ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_19 ) ;
struct V_9 * V_10 ;
int V_26 ;
if ( ! ( V_10 = V_23 -> V_24 ) )
return - V_12 ;
V_26 = V_10 -> V_34 != V_21 -> V_25 . integer . V_25 [ 0 ] ;
if ( V_26 ) {
V_10 -> V_34 = ! ! V_21 -> V_25 . integer . V_25 [ 0 ] ;
F_2 ( V_10 -> V_2 . V_4 , V_6 ,
V_10 -> V_34 ? 0x05 : 0x04 ) ;
}
return V_26 ;
}
static void F_14 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = V_23 -> V_24 ;
F_2 ( V_10 -> V_2 . V_4 , V_5 , 0x08 ) ;
F_2 ( V_10 -> V_2 . V_4 , V_6 ,
V_10 -> V_34 ? 0x05 : 0x04 ) ;
F_4 ( V_10 ) ;
}
static void F_15 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = V_23 -> V_24 ;
if ( ! V_10 )
return;
F_16 ( & V_10 -> V_2 ) ;
F_17 ( V_10 ) ;
V_23 -> V_24 = NULL ;
}
int T_1 F_18 ( struct V_22 * V_23 )
{
int V_35 , V_36 ;
struct V_9 * V_10 ;
F_19 ( L_2 ) ;
V_10 = F_20 ( sizeof( * V_10 ) , V_37 ) ;
if ( ! V_10 )
return - V_38 ;
V_23 -> V_24 = V_10 ;
V_23 -> V_39 = F_15 ;
V_10 -> V_34 = 1 ;
V_10 -> V_2 . V_40 = V_41 ;
V_10 -> V_2 . V_42 = F_1 ;
V_10 -> V_2 . V_43 = L_3 ;
if ( ( V_36 = F_21 ( & V_10 -> V_2 ) ) < 0 )
return V_36 ;
strcpy ( V_23 -> V_44 -> V_45 , L_4 ) ;
for ( V_35 = 0 ; V_35 < F_22 ( V_46 ) ; V_35 ++ ) {
if ( ( V_36 = F_23 ( V_23 -> V_44 , F_24 ( & V_46 [ V_35 ] , V_23 ) ) ) < 0 )
return V_36 ;
}
#ifdef F_25
V_23 -> V_47 = F_14 ;
#endif
return 0 ;
}
