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
V_4 -> V_18 . V_19 = V_20 ;
V_15 = F_5 ( sizeof( * V_15 ) , V_21 ) ;
if ( ! V_15 )
return - V_22 ;
F_6 ( & V_4 -> V_5 , V_15 ) ;
memset ( & V_9 , 0 , sizeof( struct V_16 ) ) ;
V_9 . V_23 = 255 ;
V_2 = F_7 ( L_1 , & V_4 -> V_5 , V_4 ,
& V_24 , & V_9 ) ;
if ( F_8 ( V_2 ) ) {
V_17 = F_9 ( V_2 ) ;
F_10 ( V_15 ) ;
return V_17 ;
}
V_15 -> V_2 = V_2 ;
V_2 -> V_9 . V_10 = V_11 ;
V_2 -> V_9 . V_12 = V_11 ;
V_2 -> V_9 . V_23 = V_4 -> V_25 ;
V_2 -> V_9 . V_13 = V_4 -> V_25 ;
V_17 = F_1 ( V_2 ) ;
if ( V_17 < 0 )
F_11 ( & V_4 -> V_5 , L_2 ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_2 ( & V_4 -> V_5 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
V_2 -> V_9 . V_12 = V_26 ;
F_1 ( V_2 ) ;
F_13 ( V_2 ) ;
F_10 ( V_15 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
int V_17 ;
struct V_14 * V_15 = F_2 ( & V_4 -> V_5 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( V_4 -> V_27 == V_28 )
return 0 ;
V_17 = F_15 ( V_4 ) ;
if ( V_17 )
goto V_29;
if ( V_4 -> V_30 ) {
V_17 = V_4 -> V_30 ( V_4 ) ;
if ( V_17 )
goto V_31;
}
V_17 = F_1 ( V_2 ) ;
if ( V_17 < 0 )
F_11 ( & V_4 -> V_5 , L_2 ) ;
return 0 ;
V_31:
F_16 ( V_4 ) ;
V_29:
return V_17 ;
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_2 ( & V_4 -> V_5 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( V_4 -> V_27 != V_28 )
return;
V_2 -> V_9 . V_13 = 0 ;
F_1 ( V_2 ) ;
if ( V_4 -> V_32 )
V_4 -> V_32 ( V_4 ) ;
F_16 ( V_4 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
int V_17 ;
V_17 = F_14 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_27 = V_28 ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
V_4 -> V_27 = V_33 ;
}
static int F_20 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
V_4 -> V_27 = V_34 ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
int V_17 ;
V_17 = F_14 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_27 = V_28 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 )
{
return 16 ;
}
static int F_23 ( struct V_35 * V_36 , unsigned char V_37 ,
unsigned char V_38 )
{
int V_39 = 0 ;
unsigned int V_40 = 0 , V_41 = 0 ;
V_40 = 0x0000 | V_37 ;
V_41 = 0x0100 | V_38 ;
V_41 = ( V_40 << 16 ) | V_41 ;
V_39 = F_24 ( V_36 , ( unsigned char * ) & V_41 , 4 ) ;
if ( V_39 )
F_25 ( L_3 , V_41 ) ;
return V_39 ;
}
static int F_26 ( struct V_35 * V_36 )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < ( F_27 ( V_43 ) - 1 ) ; V_42 ++ )
F_23 ( V_36 , V_43 [ V_42 ] . V_44 ,
V_43 [ V_42 ] . V_45 ) ;
F_28 ( 20 ) ;
F_23 ( V_36 , V_43 [ V_42 ] . V_44 ,
V_43 [ V_42 ] . V_45 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_36 )
{
V_36 -> V_46 = V_47 ;
V_36 -> V_48 = 32 ;
F_30 ( V_36 ) ;
F_26 ( V_36 ) ;
return F_31 ( & V_49 ) ;
}
static int F_32 ( struct V_35 * V_36 )
{
F_33 ( & V_49 ) ;
return 0 ;
}
static int F_34 ( struct V_35 * V_36 , T_1 V_50 )
{
F_23 ( V_36 , 2 , 0x01 ) ;
F_35 ( 40 ) ;
return 0 ;
}
static int F_36 ( struct V_35 * V_36 )
{
F_30 ( V_36 ) ;
F_23 ( V_36 , 2 , 0x00 ) ;
F_26 ( V_36 ) ;
return 0 ;
}
