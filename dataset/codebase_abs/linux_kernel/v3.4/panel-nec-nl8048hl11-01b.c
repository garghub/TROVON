static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
if ( ! V_4 -> V_7 )
return - V_8 ;
if ( V_2 -> V_9 . V_10 == V_11 &&
V_2 -> V_9 . V_12 == V_11 )
V_6 = V_2 -> V_9 . V_13 ;
else
V_6 = 0 ;
return V_4 -> V_7 ( V_4 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 . V_10 == V_11 &&
V_2 -> V_9 . V_12 == V_11 )
return V_2 -> V_9 . V_13 ;
return 0 ;
}
static int F_4 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_16 V_9 ;
int V_17 ;
V_4 -> V_18 . V_19 = V_20 | V_21 |
V_22 | V_23 |
V_24 ;
V_4 -> V_18 . V_25 = V_26 ;
V_15 = F_5 ( sizeof( * V_15 ) , V_27 ) ;
if ( ! V_15 )
return - V_28 ;
F_6 ( & V_4 -> V_5 , V_15 ) ;
memset ( & V_9 , 0 , sizeof( struct V_16 ) ) ;
V_9 . V_29 = 255 ;
V_2 = F_7 ( L_1 , & V_4 -> V_5 , V_4 ,
& V_30 , & V_9 ) ;
if ( F_8 ( V_2 ) ) {
V_17 = F_9 ( V_2 ) ;
F_10 ( V_15 ) ;
return V_17 ;
}
V_15 -> V_2 = V_2 ;
V_2 -> V_9 . V_10 = V_11 ;
V_2 -> V_9 . V_12 = V_11 ;
V_2 -> V_9 . V_29 = V_4 -> V_31 ;
V_2 -> V_9 . V_13 = V_4 -> V_31 ;
V_17 = F_1 ( V_2 ) ;
if ( V_17 < 0 )
F_11 ( & V_4 -> V_5 , L_2 ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_2 ( & V_4 -> V_5 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
V_2 -> V_9 . V_12 = V_32 ;
F_1 ( V_2 ) ;
F_13 ( V_2 ) ;
F_10 ( V_15 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
int V_17 ;
struct V_14 * V_15 = F_2 ( & V_4 -> V_5 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( V_4 -> V_33 == V_34 )
return 0 ;
V_17 = F_15 ( V_4 ) ;
if ( V_17 )
goto V_35;
if ( V_4 -> V_36 ) {
V_17 = V_4 -> V_36 ( V_4 ) ;
if ( V_17 )
goto V_37;
}
V_17 = F_1 ( V_2 ) ;
if ( V_17 < 0 )
F_11 ( & V_4 -> V_5 , L_2 ) ;
return 0 ;
V_37:
F_16 ( V_4 ) ;
V_35:
return V_17 ;
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_2 ( & V_4 -> V_5 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( V_4 -> V_33 != V_34 )
return;
V_2 -> V_9 . V_13 = 0 ;
F_1 ( V_2 ) ;
if ( V_4 -> V_38 )
V_4 -> V_38 ( V_4 ) ;
F_16 ( V_4 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
int V_17 ;
V_17 = F_14 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_33 = V_34 ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
V_4 -> V_33 = V_39 ;
}
static int F_20 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
V_4 -> V_33 = V_40 ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
int V_17 ;
V_17 = F_14 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_33 = V_34 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 )
{
return 16 ;
}
static int F_23 ( struct V_41 * V_42 , unsigned char V_43 ,
unsigned char V_44 )
{
int V_45 = 0 ;
unsigned int V_46 = 0 , V_47 = 0 ;
V_46 = 0x0000 | V_43 ;
V_47 = 0x0100 | V_44 ;
V_47 = ( V_46 << 16 ) | V_47 ;
V_45 = F_24 ( V_42 , ( unsigned char * ) & V_47 , 4 ) ;
if ( V_45 )
F_25 ( L_3 , V_47 ) ;
return V_45 ;
}
static int F_26 ( struct V_41 * V_42 )
{
unsigned int V_48 ;
for ( V_48 = 0 ; V_48 < ( F_27 ( V_49 ) - 1 ) ; V_48 ++ )
F_23 ( V_42 , V_49 [ V_48 ] . V_50 ,
V_49 [ V_48 ] . V_51 ) ;
F_28 ( 20 ) ;
F_23 ( V_42 , V_49 [ V_48 ] . V_50 ,
V_49 [ V_48 ] . V_51 ) ;
return 0 ;
}
static int F_29 ( struct V_41 * V_42 )
{
V_42 -> V_52 = V_53 ;
V_42 -> V_54 = 32 ;
F_30 ( V_42 ) ;
F_26 ( V_42 ) ;
return F_31 ( & V_55 ) ;
}
static int F_32 ( struct V_41 * V_42 )
{
F_33 ( & V_55 ) ;
return 0 ;
}
static int F_34 ( struct V_41 * V_42 , T_1 V_56 )
{
F_23 ( V_42 , 2 , 0x01 ) ;
F_35 ( 40 ) ;
return 0 ;
}
static int F_36 ( struct V_41 * V_42 )
{
F_30 ( V_42 ) ;
F_23 ( V_42 , 2 , 0x00 ) ;
F_26 ( V_42 ) ;
return 0 ;
}
