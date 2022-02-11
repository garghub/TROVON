static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
int V_5 = 0 ;
unsigned int V_6 = 0 , V_7 = 0 ;
V_6 = 0x0000 | V_3 ;
V_7 = 0x0100 | V_4 ;
V_7 = ( V_6 << 16 ) | V_7 ;
V_5 = F_2 ( V_2 , ( unsigned char * ) & V_7 , 4 ) ;
if ( V_5 )
F_3 ( L_1 , V_7 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < ( F_5 ( V_9 ) - 1 ) ; V_8 ++ )
F_1 ( V_2 , V_9 [ V_8 ] . V_10 ,
V_9 [ V_8 ] . V_11 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , V_9 [ V_8 ] . V_10 ,
V_9 [ V_8 ] . V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_12 * V_16 = V_15 -> V_16 ;
int V_17 ;
if ( F_9 ( V_13 ) )
return 0 ;
V_17 = V_16 -> V_18 . V_19 -> V_20 ( V_16 , V_13 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static void F_10 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_12 * V_16 = V_15 -> V_16 ;
if ( ! F_9 ( V_13 ) )
return;
V_16 -> V_18 . V_19 -> V_21 ( V_16 , V_13 ) ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_12 * V_16 = V_15 -> V_16 ;
int V_17 ;
if ( ! F_9 ( V_13 ) )
return - V_22 ;
if ( F_12 ( V_13 ) )
return 0 ;
if ( V_15 -> V_23 )
V_16 -> V_18 . V_19 -> V_24 ( V_16 , V_15 -> V_23 ) ;
V_16 -> V_18 . V_19 -> V_25 ( V_16 , & V_15 -> V_26 ) ;
V_17 = V_16 -> V_18 . V_19 -> V_27 ( V_16 ) ;
if ( V_17 )
return V_17 ;
if ( F_13 ( V_15 -> V_28 ) )
F_14 ( V_15 -> V_28 , 1 ) ;
V_13 -> V_29 = V_30 ;
return 0 ;
}
static void F_15 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_12 * V_16 = V_15 -> V_16 ;
if ( ! F_12 ( V_13 ) )
return;
if ( F_13 ( V_15 -> V_28 ) )
F_14 ( V_15 -> V_28 , 0 ) ;
V_16 -> V_18 . V_19 -> V_31 ( V_16 ) ;
V_13 -> V_29 = V_32 ;
}
static void F_16 ( struct V_12 * V_13 ,
struct V_33 * V_26 )
{
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_12 * V_16 = V_15 -> V_16 ;
V_15 -> V_26 = * V_26 ;
V_13 -> V_34 . V_26 = * V_26 ;
V_16 -> V_18 . V_19 -> V_25 ( V_16 , V_26 ) ;
}
static void F_17 ( struct V_12 * V_13 ,
struct V_33 * V_26 )
{
struct V_14 * V_15 = F_8 ( V_13 ) ;
* V_26 = V_15 -> V_26 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_33 * V_26 )
{
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_12 * V_16 = V_15 -> V_16 ;
return V_16 -> V_18 . V_19 -> V_35 ( V_16 , V_26 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_38 . V_39 ;
struct V_14 * V_15 = F_20 ( & V_2 -> V_38 ) ;
struct V_12 * V_16 ;
int V_40 ;
V_40 = F_21 ( V_37 , L_2 , 0 ) ;
if ( ! F_13 ( V_40 ) ) {
F_22 ( & V_2 -> V_38 , L_3 ) ;
return V_40 ;
}
V_15 -> V_28 = V_40 ;
V_15 -> V_41 = - V_42 ;
V_16 = F_23 ( V_37 ) ;
if ( F_24 ( V_16 ) ) {
F_22 ( & V_2 -> V_38 , L_4 ) ;
return F_25 ( V_16 ) ;
}
V_15 -> V_16 = V_16 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_17 ;
F_27 ( & V_2 -> V_38 , L_5 , V_43 ) ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = 32 ;
V_17 = F_28 ( V_2 ) ;
if ( V_17 < 0 ) {
F_22 ( & V_2 -> V_38 , L_6 , V_17 ) ;
return V_17 ;
}
F_4 ( V_2 ) ;
V_15 = F_29 ( & V_2 -> V_38 , sizeof( * V_15 ) , V_47 ) ;
if ( V_15 == NULL )
return - V_48 ;
F_30 ( & V_2 -> V_38 , V_15 ) ;
V_15 -> V_2 = V_2 ;
if ( ! V_2 -> V_38 . V_39 )
return - V_22 ;
V_17 = F_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
if ( F_13 ( V_15 -> V_41 ) ) {
V_17 = F_31 ( & V_2 -> V_38 , V_15 -> V_41 ,
V_49 , L_7 ) ;
if ( V_17 )
goto V_50;
}
if ( F_13 ( V_15 -> V_28 ) ) {
V_17 = F_31 ( & V_2 -> V_38 , V_15 -> V_28 ,
V_51 , L_8 ) ;
if ( V_17 )
goto V_50;
}
V_15 -> V_26 = V_52 ;
V_13 = & V_15 -> V_13 ;
V_13 -> V_38 = & V_2 -> V_38 ;
V_13 -> V_53 = & V_54 ;
V_13 -> type = V_55 ;
V_13 -> V_56 = V_57 ;
V_13 -> V_34 . V_26 = V_15 -> V_26 ;
V_17 = F_32 ( V_13 ) ;
if ( V_17 ) {
F_22 ( & V_2 -> V_38 , L_9 ) ;
goto V_58;
}
return 0 ;
V_58:
V_50:
F_33 ( V_15 -> V_16 ) ;
return V_17 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_20 ( & V_2 -> V_38 ) ;
struct V_12 * V_13 = & V_15 -> V_13 ;
struct V_12 * V_16 = V_15 -> V_16 ;
F_27 ( & V_15 -> V_2 -> V_38 , L_5 , V_43 ) ;
F_35 ( V_13 ) ;
F_15 ( V_13 ) ;
F_10 ( V_13 ) ;
F_33 ( V_16 ) ;
return 0 ;
}
static int F_36 ( struct V_59 * V_38 )
{
struct V_1 * V_2 = F_37 ( V_38 ) ;
F_1 ( V_2 , 2 , 0x01 ) ;
F_38 ( 40 ) ;
return 0 ;
}
static int F_39 ( struct V_59 * V_38 )
{
struct V_1 * V_2 = F_37 ( V_38 ) ;
F_28 ( V_2 ) ;
F_1 ( V_2 , 2 , 0x00 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
