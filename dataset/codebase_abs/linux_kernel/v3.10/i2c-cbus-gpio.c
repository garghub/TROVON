static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
F_2 ( V_2 -> V_4 , V_3 ? 1 : 0 ) ;
F_2 ( V_2 -> V_5 , 1 ) ;
F_2 ( V_2 -> V_5 , 0 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_6 , unsigned V_7 )
{
int V_8 ;
for ( V_8 = V_7 ; V_8 > 0 ; V_8 -- )
F_1 ( V_2 , V_6 & ( 1 << ( V_8 - 1 ) ) ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 ;
F_2 ( V_2 -> V_5 , 1 ) ;
V_9 = F_5 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 , 0 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
int V_8 ;
for ( V_8 = 16 ; V_8 > 0 ; V_8 -- ) {
int V_3 = F_4 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 )
V_9 |= 1 << ( V_8 - 1 ) ;
}
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , char V_10 , unsigned V_11 ,
unsigned V_12 , unsigned V_6 )
{
unsigned long V_13 ;
int V_9 ;
F_8 ( & V_2 -> V_14 , V_13 ) ;
F_2 ( V_2 -> V_15 , 0 ) ;
F_9 ( V_2 -> V_4 , 1 ) ;
F_3 ( V_2 , V_11 , V_16 ) ;
F_1 ( V_2 , V_10 == V_17 ) ;
F_3 ( V_2 , V_12 , V_18 ) ;
if ( V_10 == V_19 ) {
F_3 ( V_2 , V_6 , 16 ) ;
V_9 = 0 ;
} else {
V_9 = F_10 ( V_2 -> V_4 ) ;
if ( V_9 ) {
F_11 ( V_2 -> V_11 , L_1 ) ;
goto V_20;
}
F_2 ( V_2 -> V_5 , 1 ) ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 ) {
F_11 ( V_2 -> V_11 , L_2 ) ;
goto V_20;
}
}
F_2 ( V_2 -> V_15 , 1 ) ;
F_2 ( V_2 -> V_5 , 1 ) ;
F_2 ( V_2 -> V_5 , 0 ) ;
V_20:
F_12 ( & V_2 -> V_14 , V_13 ) ;
return V_9 ;
}
static int F_13 ( struct V_21 * V_22 ,
T_1 V_23 ,
unsigned short V_13 ,
char V_24 ,
T_2 V_25 ,
int V_26 ,
union V_27 * V_6 )
{
struct V_1 * V_28 = F_14 ( V_22 ) ;
int V_9 ;
if ( V_26 != V_29 )
return - V_30 ;
V_9 = F_7 ( V_28 , V_24 == V_17 , V_23 ,
V_25 , V_6 -> V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_24 == V_17 )
V_6 -> V_31 = V_9 ;
return 0 ;
}
static T_3 F_15 ( struct V_21 * V_22 )
{
return V_32 | V_33 ;
}
static int F_16 ( struct V_34 * V_35 )
{
struct V_21 * V_22 = F_17 ( V_35 ) ;
F_18 ( V_22 ) ;
return 0 ;
}
static int F_19 ( struct V_34 * V_35 )
{
struct V_21 * V_22 ;
struct V_1 * V_28 ;
int V_9 ;
V_22 = F_20 ( & V_35 -> V_11 , sizeof( struct V_21 ) ,
V_36 ) ;
if ( ! V_22 )
return - V_37 ;
V_28 = F_20 ( & V_35 -> V_11 , sizeof( * V_28 ) , V_36 ) ;
if ( ! V_28 )
return - V_37 ;
if ( V_35 -> V_11 . V_38 ) {
struct V_39 * V_40 = V_35 -> V_11 . V_38 ;
if ( F_21 ( V_40 ) != 3 )
return - V_41 ;
V_28 -> V_5 = F_22 ( V_40 , 0 ) ;
V_28 -> V_4 = F_22 ( V_40 , 1 ) ;
V_28 -> V_15 = F_22 ( V_40 , 2 ) ;
} else if ( V_35 -> V_11 . V_42 ) {
struct V_43 * V_44 = V_35 -> V_11 . V_42 ;
V_28 -> V_5 = V_44 -> V_5 ;
V_28 -> V_4 = V_44 -> V_4 ;
V_28 -> V_15 = V_44 -> V_15 ;
} else {
return - V_41 ;
}
V_22 -> V_45 = V_46 ;
V_22 -> V_47 = V_48 ;
V_22 -> V_11 . V_49 = & V_35 -> V_11 ;
V_22 -> V_50 = V_35 -> V_51 ;
V_22 -> V_52 = V_53 ;
V_22 -> V_54 = & V_55 ;
F_23 ( V_22 -> V_56 , L_3 , sizeof( V_22 -> V_56 ) ) ;
F_24 ( & V_28 -> V_14 ) ;
V_28 -> V_11 = & V_35 -> V_11 ;
V_9 = F_25 ( & V_35 -> V_11 , V_28 -> V_5 ,
V_57 , L_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_25 ( & V_35 -> V_11 , V_28 -> V_4 , V_58 ,
L_5 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_25 ( & V_35 -> V_11 , V_28 -> V_15 ,
V_59 , L_6 ) ;
if ( V_9 )
return V_9 ;
F_26 ( V_22 , V_28 ) ;
F_27 ( V_35 , V_22 ) ;
return F_28 ( V_22 ) ;
}
