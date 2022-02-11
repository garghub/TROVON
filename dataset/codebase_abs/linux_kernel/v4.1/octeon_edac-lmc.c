static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
bool V_5 = false ;
char V_6 [ 64 ] ;
V_4 . V_7 = F_2 ( F_3 ( V_2 -> V_8 ) ) ;
if ( V_4 . V_9 . V_10 || V_4 . V_9 . V_11 ) {
union V_12 V_13 ;
V_13 . V_7 = F_2 ( F_4 ( V_2 -> V_8 ) ) ;
snprintf ( V_6 , sizeof( V_6 ) ,
L_1 ,
V_13 . V_14 . V_15 , V_13 . V_14 . V_16 ,
V_13 . V_14 . V_17 , V_13 . V_14 . V_18 , V_13 . V_14 . V_19 ) ;
}
if ( V_4 . V_9 . V_10 ) {
F_5 ( V_20 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , V_6 , L_2 ) ;
V_4 . V_9 . V_10 = - 1 ;
V_5 = true ;
}
if ( V_4 . V_9 . V_11 ) {
F_5 ( V_21 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , V_6 , L_2 ) ;
V_4 . V_9 . V_11 = - 1 ;
V_5 = true ;
}
if ( V_5 )
F_6 ( F_3 ( V_2 -> V_8 ) , V_4 . V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_24 ;
union V_25 V_26 ;
bool V_5 = false ;
char V_6 [ 64 ] ;
if ( ! V_23 -> V_27 )
V_26 . V_7 = F_2 ( F_8 ( V_2 -> V_8 ) ) ;
else {
if ( V_23 -> V_28 == 1 )
V_26 . V_9 . V_10 = 1 ;
if ( V_23 -> V_28 == 2 )
V_26 . V_9 . V_11 = 1 ;
}
if ( V_26 . V_9 . V_10 || V_26 . V_9 . V_11 ) {
union V_12 V_13 ;
if ( F_9 ( ! V_23 -> V_27 ) )
V_13 . V_7 = F_2 ( F_4 ( V_2 -> V_8 ) ) ;
else {
V_13 . V_29 . V_15 = V_23 -> V_30 ;
V_13 . V_29 . V_16 = V_23 -> V_31 ;
V_13 . V_29 . V_17 = V_23 -> V_32 ;
V_13 . V_29 . V_18 = V_23 -> V_33 ;
V_13 . V_29 . V_19 = V_23 -> V_34 ;
}
snprintf ( V_6 , sizeof( V_6 ) ,
L_1 ,
V_13 . V_29 . V_15 , V_13 . V_29 . V_16 ,
V_13 . V_29 . V_17 , V_13 . V_29 . V_18 , V_13 . V_29 . V_19 ) ;
}
if ( V_26 . V_9 . V_10 ) {
F_5 ( V_20 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , V_6 , L_2 ) ;
V_26 . V_9 . V_10 = - 1 ;
V_5 = true ;
}
if ( V_26 . V_9 . V_11 ) {
F_5 ( V_21 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , V_6 , L_2 ) ;
V_26 . V_9 . V_11 = - 1 ;
V_5 = true ;
}
if ( V_5 ) {
if ( F_9 ( ! V_23 -> V_27 ) )
F_6 ( F_8 ( V_2 -> V_8 ) , V_26 . V_7 ) ;
else
V_23 -> V_27 = 0 ;
}
}
static T_1 F_10 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 ,
T_2 V_40 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
struct V_22 * V_23 = V_2 -> V_24 ;
if ( ! strncmp ( V_39 , L_3 , 6 ) )
V_23 -> V_28 = 1 ;
else if ( ! strncmp ( V_39 , L_4 , 6 ) )
V_23 -> V_28 = 2 ;
return V_40 ;
}
static T_1 F_12 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
struct V_22 * V_23 = V_2 -> V_24 ;
if ( V_23 -> V_28 == 1 )
return sprintf ( V_39 , L_3 ) ;
else if ( V_23 -> V_28 == 2 )
return sprintf ( V_39 , L_4 ) ;
return 0 ;
}
static int F_13 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_43 V_44 [ 1 ] ;
int V_45 = V_42 -> V_46 ;
F_14 () ;
V_44 [ 0 ] . type = V_47 ;
V_44 [ 0 ] . V_48 = 1 ;
V_44 [ 0 ] . V_49 = false ;
if ( F_15 ( V_50 ) ) {
union V_3 V_4 ;
V_4 . V_7 = F_2 ( F_3 ( 0 ) ) ;
if ( ! V_4 . V_9 . V_51 ) {
F_16 ( & V_42 -> V_36 , L_5 ) ;
return 0 ;
}
V_2 = F_17 ( V_45 , F_18 ( V_44 ) , V_44 , sizeof( struct V_22 ) ) ;
if ( ! V_2 )
return - V_52 ;
V_2 -> V_42 = & V_42 -> V_36 ;
V_2 -> V_53 = V_53 ( & V_42 -> V_36 ) ;
V_2 -> V_54 = L_6 ;
V_2 -> V_55 = L_7 ;
V_2 -> V_56 = F_1 ;
if ( F_19 ( V_2 , V_57 ) ) {
F_20 ( & V_42 -> V_36 , L_8 ) ;
F_21 ( V_2 ) ;
return - V_52 ;
}
V_4 . V_7 = F_2 ( F_3 ( V_45 ) ) ;
V_4 . V_9 . V_58 = 0 ;
V_4 . V_9 . V_59 = 0 ;
F_6 ( F_3 ( V_45 ) , V_4 . V_7 ) ;
} else {
union V_60 V_61 ;
union V_62 V_63 ;
V_63 . V_7 = F_2 ( F_22 ( 0 ) ) ;
if ( ! V_63 . V_9 . V_51 ) {
F_16 ( & V_42 -> V_36 , L_5 ) ;
return 0 ;
}
V_2 = F_17 ( V_45 , F_18 ( V_44 ) , V_44 , sizeof( struct V_22 ) ) ;
if ( ! V_2 )
return - V_52 ;
V_2 -> V_42 = & V_42 -> V_36 ;
V_2 -> V_53 = V_53 ( & V_42 -> V_36 ) ;
V_2 -> V_54 = L_6 ;
V_2 -> V_55 = L_9 ;
V_2 -> V_56 = F_7 ;
if ( F_19 ( V_2 , V_57 ) ) {
F_20 ( & V_42 -> V_36 , L_8 ) ;
F_21 ( V_2 ) ;
return - V_52 ;
}
V_61 . V_7 = F_2 ( F_3 ( V_45 ) ) ;
V_61 . V_9 . V_58 = 0 ;
V_61 . V_9 . V_59 = 0 ;
F_6 ( F_3 ( V_45 ) , V_61 . V_7 ) ;
}
F_23 ( V_42 , V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_25 ( V_42 ) ;
F_26 ( & V_42 -> V_36 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
