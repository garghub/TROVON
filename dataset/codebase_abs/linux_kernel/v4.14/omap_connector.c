static void F_1 ( void * V_1 ,
enum V_2 V_3 )
{
struct V_4 * V_4 = V_1 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
enum V_2 V_10 ;
F_2 ( & V_9 -> V_11 . V_12 ) ;
V_10 = V_6 -> V_3 ;
V_6 -> V_3 = V_3 ;
F_3 ( & V_9 -> V_11 . V_12 ) ;
if ( V_10 != V_3 )
F_4 ( V_9 ) ;
}
bool F_5 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
return V_4 -> V_13 ;
}
static enum V_2 F_7 (
struct V_5 * V_6 , bool V_14 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
enum V_2 V_20 ;
if ( V_18 -> V_21 ) {
if ( V_18 -> V_21 ( V_16 ) )
V_20 = V_22 ;
else
V_20 = V_23 ;
} else if ( V_16 -> type == V_24 ||
V_16 -> type == V_25 ||
V_16 -> type == V_26 ||
V_16 -> type == V_27 ) {
V_20 = V_22 ;
} else {
V_20 = V_28 ;
}
F_8 ( L_1 , V_4 -> V_16 -> V_29 , V_20 , V_14 ) ;
return V_20 ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
F_10 ( L_2 , V_4 -> V_16 -> V_29 ) ;
if ( V_6 -> V_30 == V_31 &&
V_16 -> V_19 -> V_32 ) {
V_16 -> V_19 -> V_32 ( V_16 ) ;
}
F_11 ( V_6 ) ;
F_12 ( V_6 ) ;
F_13 ( V_4 ) ;
F_14 ( V_16 ) ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_33 = 0 ;
F_10 ( L_2 , V_4 -> V_16 -> V_29 ) ;
if ( V_18 -> V_34 ) {
void * V_35 = F_16 ( V_36 , V_37 ) ;
if ( ( V_18 -> V_34 ( V_16 , V_35 , V_36 ) > 0 ) &&
F_17 ( V_35 ) ) {
F_18 (
V_6 , V_35 ) ;
V_33 = F_19 ( V_6 , V_35 ) ;
V_4 -> V_13 =
F_20 ( V_35 ) ;
} else {
F_18 (
V_6 , NULL ) ;
}
F_13 ( V_35 ) ;
} else {
struct V_38 * V_39 = F_21 ( V_9 ) ;
struct V_40 V_41 = { 0 } ;
V_18 -> V_42 ( V_16 , & V_41 ) ;
F_22 ( & V_41 , V_39 ) ;
V_39 -> type = V_43 | V_44 ;
F_23 ( V_39 ) ;
F_24 ( V_6 , V_39 ) ;
V_33 = 1 ;
}
return V_33 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_38 * V_39 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_40 V_41 = { 0 } ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_38 * V_45 ;
int V_46 , V_20 = V_47 ;
F_26 ( V_39 , & V_41 ) ;
V_39 -> V_48 = F_27 ( V_39 ) ;
if ( V_18 -> V_49 ) {
V_46 = V_18 -> V_49 ( V_16 , & V_41 ) ;
} else {
struct V_40 V_50 = { 0 } ;
V_18 -> V_42 ( V_16 , & V_50 ) ;
V_50 . V_51 = 0 ;
if ( memcmp ( & V_41 , & V_50 , sizeof( V_41 ) ) )
V_46 = - V_52 ;
else
V_46 = 0 ;
}
if ( ! V_46 ) {
V_45 = F_28 ( V_9 , V_39 ) ;
V_45 -> clock = V_41 . V_53 / 1000 ;
V_45 -> V_48 = 0 ;
if ( V_39 -> V_48 == F_27 ( V_45 ) )
V_20 = V_54 ;
F_29 ( V_9 , V_45 ) ;
}
F_10 ( L_3
L_4 ,
( V_20 == V_54 ) ? L_5 : L_6 ,
V_39 -> V_7 . V_55 , V_39 -> V_29 , V_39 -> V_48 , V_39 -> clock ,
V_39 -> V_56 , V_39 -> V_57 ,
V_39 -> V_58 , V_39 -> V_59 ,
V_39 -> V_60 , V_39 -> V_61 ,
V_39 -> V_62 , V_39 -> V_63 , V_39 -> type , V_39 -> V_51 ) ;
return V_20 ;
}
struct V_5 * F_30 ( struct V_8 * V_9 ,
int V_64 , struct V_15 * V_16 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = NULL ;
struct V_4 * V_4 ;
bool V_67 = false ;
F_10 ( L_2 , V_16 -> V_29 ) ;
F_31 ( V_16 ) ;
V_4 = F_16 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 )
goto V_68;
V_4 -> V_16 = V_16 ;
V_6 = & V_4 -> V_7 ;
F_32 ( V_9 , V_6 , & V_69 ,
V_64 ) ;
F_33 ( V_6 , & V_70 ) ;
if ( V_16 -> V_19 -> V_71 ) {
int V_20 = V_16 -> V_19 -> V_71 ( V_16 ,
F_1 ,
V_4 ) ;
if ( ! V_20 )
V_67 = true ;
else if ( V_20 != - V_72 )
F_10 ( L_7 ,
V_16 -> V_29 , V_20 ) ;
}
if ( V_67 )
V_6 -> V_30 = V_31 ;
else if ( V_16 -> V_19 -> V_21 )
V_6 -> V_30 = V_73 |
V_74 ;
else
V_6 -> V_30 = 0 ;
V_6 -> V_75 = 1 ;
V_6 -> V_76 = 0 ;
return V_6 ;
V_68:
if ( V_6 )
F_9 ( V_6 ) ;
return NULL ;
}
