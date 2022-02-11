int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_3 ( V_13 ) ; V_12 ++ ) {
F_4 ( V_2 , L_1 ,
V_13 [ V_12 ] . V_14 , V_13 [ V_12 ] . V_15 ,
F_5 ( V_13 [ V_12 ] . V_15 ) ) ;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
T_1 V_16 = F_5 ( V_17 ) ;
T_1 V_18 = F_7 ( V_16 , V_19 ) ;
T_1 V_20 = F_7 ( V_16 , V_21 ) ;
T_1 V_22 = F_7 ( V_16 , V_23 ) ;
F_4 ( V_2 , L_2 ,
F_7 ( V_16 , V_24 ) ) ;
F_4 ( V_2 , L_3 , V_18 ) ;
F_4 ( V_2 , L_4 , V_18 * V_20 ) ;
F_4 ( V_2 , L_5 , V_18 * V_22 ) ;
F_4 ( V_2 , L_6 ,
F_7 ( V_16 , V_25 ) ) ;
return 0 ;
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_2 ( V_8 ) ;
F_9 ( V_26 , 0 ) ;
}
int F_10 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_8 ;
unsigned long V_27 ;
int V_28 ;
T_2 V_29 = 0 ;
struct V_30 * V_31 ;
V_32:
F_11 ( & V_11 -> V_33 , V_27 ) ;
V_28 = F_12 ( ~ V_11 -> V_34 ) ;
if ( V_28 != 0 ) {
V_28 -- ;
V_11 -> V_34 |= F_13 ( V_28 ) ;
F_14 ( & V_11 -> V_33 , V_27 ) ;
return V_28 ;
}
V_31 = F_15 ( V_11 ) ;
if ( V_31 )
V_29 = V_31 -> V_29 ;
F_14 ( & V_11 -> V_33 , V_27 ) ;
if ( V_29 ) {
int V_35 = F_16 ( V_8 , V_29 , ~ 0ull , true ) ;
if ( V_35 == 0 )
goto V_32;
return V_35 ;
}
return - V_36 ;
}
int
F_17 ( struct V_7 * V_37 )
{
struct V_10 * V_11 = F_2 ( V_37 ) ;
struct V_38 * V_39 = V_11 -> V_39 ;
T_1 V_40 = 16 * 1024 * 1024 ;
int V_35 = 0 ;
struct V_41 V_42 ;
F_18 ( & V_42 ) ;
while ( true ) {
struct V_43 * V_44 = F_19 ( V_37 , V_40 , true ,
V_45 ) ;
if ( F_20 ( V_44 ) ) {
V_35 = F_21 ( V_44 ) ;
F_22 ( & V_39 -> V_46 -> V_8 ,
L_7
L_8
L_9 ,
V_35 ) ;
break;
}
if ( ( V_44 -> V_47 . V_48 & 0xf0000000 ) ==
( ( V_44 -> V_47 . V_48 + V_44 -> V_47 . V_47 . V_40 - 1 ) & 0xf0000000 ) ) {
V_11 -> V_49 = V_44 ;
V_11 -> V_50 = 512 * 1024 ;
V_11 -> V_34 = 0 ;
V_11 -> V_51 = 0 ;
F_23 ( sizeof( V_11 -> V_34 ) * 8 !=
V_44 -> V_47 . V_47 . V_40 / V_11 -> V_50 ) ;
break;
}
F_24 ( & V_44 -> V_52 , & V_42 ) ;
}
while ( ! F_25 ( & V_42 ) ) {
struct V_43 * V_44 = F_26 ( & V_42 ,
struct V_43 , V_52 ) ;
F_27 ( & V_44 -> V_52 ) ;
F_28 ( & V_44 -> V_47 . V_47 ) ;
}
return V_35 ;
}
static int F_29 ( struct V_53 * V_8 )
{
struct V_38 * V_39 = F_30 ( V_8 ) ;
struct V_10 * V_11 = V_39 -> V_11 ;
F_31 ( V_11 -> V_8 ) ;
F_28 ( & V_11 -> V_49 -> V_47 . V_47 ) ;
V_11 -> V_49 = NULL ;
F_32 ( V_39 -> V_54 ) ;
return 0 ;
}
static int F_33 ( struct V_53 * V_8 )
{
struct V_38 * V_39 = F_30 ( V_8 ) ;
struct V_10 * V_11 = V_39 -> V_11 ;
int V_35 ;
V_35 = F_17 ( V_11 -> V_8 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_34 ( V_39 -> V_54 ) ;
if ( V_35 != 0 )
return V_35 ;
F_8 ( V_11 -> V_8 ) ;
F_35 ( V_11 -> V_8 ) ;
return 0 ;
}
static int F_36 ( struct V_53 * V_8 , struct V_53 * V_55 , void * V_56 )
{
struct V_57 * V_46 = F_37 ( V_8 ) ;
struct V_7 * V_37 = F_30 ( V_55 ) ;
struct V_10 * V_11 = F_2 ( V_37 ) ;
struct V_38 * V_39 = NULL ;
int V_35 ;
V_39 = F_38 ( & V_46 -> V_8 , sizeof( * V_39 ) , V_58 ) ;
if ( ! V_39 )
return - V_36 ;
F_39 ( V_8 , V_39 ) ;
V_39 -> V_46 = V_46 ;
V_39 -> V_59 = F_40 ( V_46 , 0 ) ;
if ( F_20 ( V_39 -> V_59 ) )
return F_21 ( V_39 -> V_59 ) ;
V_11 -> V_39 = V_39 ;
V_39 -> V_11 = V_11 ;
V_39 -> V_54 = F_41 ( V_8 , NULL ) ;
if ( F_20 ( V_39 -> V_54 ) ) {
int V_35 = F_21 ( V_39 -> V_54 ) ;
if ( V_35 == - V_60 ) {
V_35 = 0 ;
V_39 -> V_54 = NULL ;
} else {
if ( V_35 != - V_61 )
F_22 ( V_8 , L_10 ,
V_35 ) ;
return V_35 ;
}
}
if ( F_5 ( V_62 ) != V_63 ) {
F_42 ( L_11 ,
F_5 ( V_62 ) , V_63 ) ;
return - V_64 ;
}
V_35 = F_34 ( V_39 -> V_54 ) ;
if ( V_35 != 0 )
return V_35 ;
V_35 = F_17 ( V_37 ) ;
if ( V_35 ) {
F_32 ( V_39 -> V_54 ) ;
return V_35 ;
}
F_9 ( V_65 , 0 ) ;
F_9 ( V_66 , 0 ) ;
F_8 ( V_37 ) ;
V_35 = F_43 ( V_37 , F_44 ( V_46 , 0 ) ) ;
if ( V_35 ) {
F_42 ( L_12 ) ;
return V_35 ;
}
F_45 ( V_8 ) ;
F_46 ( V_8 ) ;
F_47 ( V_8 , 40 ) ;
F_48 ( V_8 ) ;
return 0 ;
}
static void F_49 ( struct V_53 * V_8 , struct V_53 * V_55 ,
void * V_56 )
{
struct V_7 * V_37 = F_30 ( V_55 ) ;
struct V_10 * V_11 = F_2 ( V_37 ) ;
F_50 ( V_8 ) ;
F_51 ( V_37 ) ;
F_9 ( V_65 , 0 ) ;
F_9 ( V_66 , 0 ) ;
V_11 -> V_39 = NULL ;
}
static int F_52 ( struct V_57 * V_46 )
{
return F_53 ( & V_46 -> V_8 , & V_67 ) ;
}
static int F_54 ( struct V_57 * V_46 )
{
F_55 ( & V_46 -> V_8 , & V_67 ) ;
return 0 ;
}
