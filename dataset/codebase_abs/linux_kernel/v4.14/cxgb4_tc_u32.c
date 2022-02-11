static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 ,
bool V_9 )
{
unsigned int V_10 , V_11 ;
T_1 V_12 , V_13 ;
int V_14 , V_15 ;
bool V_16 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_17 . V_18 -> V_19 ; V_10 ++ ) {
V_14 = V_6 -> V_17 . V_18 -> V_20 [ V_10 ] . V_14 ;
V_12 = V_6 -> V_17 . V_18 -> V_20 [ V_10 ] . V_12 ;
V_13 = V_6 -> V_17 . V_18 -> V_20 [ V_10 ] . V_13 ;
if ( V_9 ) {
if ( ! V_6 -> V_17 . V_18 -> V_20 [ V_10 ] . V_21 )
continue;
} else {
if ( V_6 -> V_17 . V_18 -> V_20 [ V_10 ] . V_21 )
continue;
}
V_16 = false ;
for ( V_11 = 0 ; V_8 [ V_11 ] . V_12 ; V_11 ++ ) {
if ( V_14 == V_8 [ V_11 ] . V_14 ) {
V_16 = true ;
V_15 = V_8 [ V_11 ] . V_12 ( V_4 , V_12 , V_13 ) ;
if ( V_15 )
return V_15 ;
break;
}
}
if ( ! V_16 )
return - V_22 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned int V_23 = 0 ;
const struct V_24 * V_25 ;
struct V_26 * V_27 ;
F_3 ( V_28 ) ;
V_27 = V_6 -> V_17 . V_27 ;
if ( ! F_4 ( V_27 ) )
return - V_22 ;
F_5 ( V_27 , & V_28 ) ;
F_6 (a, &actions, list) {
if ( V_23 )
return - V_22 ;
if ( F_7 ( V_25 ) ) {
V_4 -> V_29 = V_30 ;
V_23 ++ ;
continue;
}
if ( F_8 ( V_25 ) ) {
struct V_31 * V_32 ;
unsigned int V_10 , V_33 ;
bool V_16 = false ;
V_33 = F_9 ( V_25 ) ;
F_10 (adap, i) {
V_32 = V_2 -> V_34 [ V_10 ] ;
if ( V_33 == V_32 -> V_35 ) {
V_4 -> V_29 = V_36 ;
V_4 -> V_37 = V_10 ;
V_16 = true ;
break;
}
}
if ( ! V_16 )
return - V_22 ;
V_23 ++ ;
continue;
}
return - V_22 ;
}
return 0 ;
}
int F_11 ( struct V_31 * V_38 , struct V_5 * V_6 )
{
const struct V_7 * V_39 , * V_40 = NULL ;
struct V_1 * V_1 = F_12 ( V_38 ) ;
T_2 V_41 = V_6 -> V_42 . V_41 ;
struct V_3 V_4 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
unsigned int V_47 ;
T_1 V_48 , V_49 ;
bool V_50 = false ;
int V_51 ;
if ( ! F_13 ( V_38 ) )
return - V_52 ;
if ( V_41 != F_14 ( V_53 ) && V_41 != F_14 ( V_54 ) )
return - V_52 ;
V_47 = V_6 -> V_17 . V_55 & 0xFFFFF ;
if ( V_47 > V_1 -> V_56 . V_57 ) {
F_15 ( V_1 -> V_58 ,
L_1 ,
V_47 , V_1 -> V_56 . V_57 ) ;
return - V_59 ;
}
V_44 = V_1 -> V_60 ;
V_48 = F_16 ( V_6 -> V_17 . V_55 ) ;
V_49 = F_16 ( V_6 -> V_17 . V_61 ) ;
if ( V_48 != 0x800 && V_48 >= V_44 -> V_62 )
return - V_22 ;
if ( V_49 >= V_44 -> V_62 )
return - V_22 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
if ( V_41 == F_14 ( V_54 ) ) {
V_39 = V_63 ;
V_50 = true ;
} else {
V_39 = V_64 ;
V_50 = false ;
}
if ( V_48 != 0x800 ) {
if ( ! V_44 -> V_65 [ V_48 - 1 ] . V_61 )
return - V_22 ;
V_40 = V_44 -> V_65 [ V_48 - 1 ] . V_66 ;
if ( ! V_40 )
return - V_22 ;
}
if ( V_49 ) {
const struct V_67 * V_68 ;
bool V_16 = false ;
unsigned int V_10 , V_11 ;
T_1 V_12 , V_13 ;
int V_14 ;
if ( V_44 -> V_65 [ V_49 - 1 ] . V_61 ) {
F_15 ( V_1 -> V_58 ,
L_2 ,
V_49 ) ;
return - V_22 ;
}
V_68 = V_50 ? V_69 : V_70 ;
for ( V_10 = 0 ; V_68 [ V_10 ] . V_71 ; V_10 ++ ) {
if ( V_68 [ V_10 ] . V_72 != V_6 -> V_17 . V_18 -> V_72 ||
V_68 [ V_10 ] . V_73 != V_6 -> V_17 . V_18 -> V_74 ||
V_68 [ V_10 ] . V_13 != V_6 -> V_17 . V_18 -> V_21 ||
V_68 [ V_10 ] . V_75 != V_6 -> V_17 . V_18 -> V_14 )
continue;
for ( V_11 = 0 ; V_11 < V_6 -> V_17 . V_18 -> V_19 ; V_11 ++ ) {
V_14 = V_6 -> V_17 . V_18 -> V_20 [ V_11 ] . V_14 ;
V_12 = V_6 -> V_17 . V_18 -> V_20 [ V_11 ] . V_12 ;
V_13 = V_6 -> V_17 . V_18 -> V_20 [ V_11 ] . V_13 ;
if ( V_68 [ V_10 ] . V_76 == V_14 &&
V_68 [ V_10 ] . V_77 == V_12 &&
V_68 [ V_10 ] . V_78 == V_13 ) {
V_16 = true ;
break;
}
}
if ( ! V_16 )
continue;
V_51 = F_1 ( V_1 , & V_4 , V_6 ,
V_39 , false ) ;
if ( V_51 )
goto V_79;
V_46 = & V_44 -> V_65 [ V_49 - 1 ] ;
V_46 -> V_66 = V_68 [ V_10 ] . V_71 ;
V_46 -> V_61 = V_6 -> V_17 . V_55 ;
memcpy ( & V_46 -> V_4 , & V_4 , sizeof( V_4 ) ) ;
break;
}
if ( ! V_16 )
return - V_22 ;
return 0 ;
}
if ( V_48 != 0x800 && V_44 -> V_65 [ V_48 - 1 ] . V_61 ) {
memcpy ( & V_4 , & V_44 -> V_65 [ V_48 - 1 ] . V_4 , sizeof( V_4 ) ) ;
V_51 = F_1 ( V_1 , & V_4 , V_6 ,
V_40 , true ) ;
if ( V_51 )
goto V_79;
}
V_51 = F_1 ( V_1 , & V_4 , V_6 , V_39 , false ) ;
if ( V_51 )
goto V_79;
V_51 = F_2 ( V_1 , & V_4 , V_6 ) ;
if ( V_51 )
goto V_79;
V_4 . V_12 . V_80 = F_17 ( V_38 ) -> V_81 ;
V_4 . V_13 . V_80 = ~ 0 ;
V_4 . V_82 = 1 ;
V_4 . type = V_50 ? 1 : 0 ;
V_51 = F_18 ( V_38 , V_47 , & V_4 ) ;
if ( V_51 )
goto V_79;
if ( V_48 != 0x800 && V_44 -> V_65 [ V_48 - 1 ] . V_61 )
F_19 ( V_47 , V_44 -> V_65 [ V_48 - 1 ] . V_83 ) ;
V_79:
return V_51 ;
}
int F_20 ( struct V_31 * V_38 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_12 ( V_38 ) ;
unsigned int V_47 , V_84 , V_10 , V_11 ;
struct V_45 * V_46 = NULL ;
struct V_43 * V_44 ;
T_1 V_55 , V_48 ;
int V_51 ;
if ( ! F_13 ( V_38 ) )
return - V_52 ;
V_47 = V_6 -> V_17 . V_55 & 0xFFFFF ;
if ( V_47 > V_1 -> V_56 . V_57 ) {
F_15 ( V_1 -> V_58 ,
L_3 ,
V_47 , V_1 -> V_56 . V_57 ) ;
return - V_59 ;
}
V_44 = V_1 -> V_60 ;
V_55 = V_6 -> V_17 . V_55 ;
V_48 = F_16 ( V_6 -> V_17 . V_55 ) ;
if ( V_48 != 0x800 && V_48 >= V_44 -> V_62 )
return - V_22 ;
if ( V_48 != 0x800 ) {
V_46 = & V_44 -> V_65 [ V_48 - 1 ] ;
if ( ! V_46 -> V_61 )
return - V_22 ;
if ( ! F_21 ( V_47 , V_46 -> V_83 ) )
return - V_22 ;
}
V_51 = F_22 ( V_38 , V_47 ) ;
if ( V_51 )
goto V_79;
if ( V_46 )
F_23 ( V_47 , V_46 -> V_83 ) ;
V_84 = V_1 -> V_56 . V_57 ;
for ( V_10 = 0 ; V_10 < V_44 -> V_62 ; V_10 ++ ) {
V_46 = & V_44 -> V_65 [ V_10 ] ;
if ( V_46 -> V_61 == V_55 ) {
for ( V_11 = 0 ; V_11 < V_84 ; V_11 ++ ) {
if ( ! F_21 ( V_11 , V_46 -> V_83 ) )
continue;
V_51 = F_24 ( V_38 , V_11 , NULL ) ;
if ( V_51 )
goto V_79;
F_23 ( V_11 , V_46 -> V_83 ) ;
}
V_46 -> V_66 = NULL ;
V_46 -> V_61 = 0 ;
memset ( & V_46 -> V_4 , 0 , sizeof( V_46 -> V_4 ) ) ;
break;
}
}
V_79:
return V_51 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
unsigned int V_10 ;
if ( ! V_2 -> V_60 )
return;
V_44 = V_2 -> V_60 ;
for ( V_10 = 0 ; V_10 < V_44 -> V_62 ; V_10 ++ ) {
struct V_45 * V_46 = & V_44 -> V_65 [ V_10 ] ;
F_26 ( V_46 -> V_83 ) ;
}
F_26 ( V_2 -> V_60 ) ;
}
struct V_43 * F_27 ( struct V_1 * V_2 )
{
unsigned int V_84 = V_2 -> V_56 . V_57 ;
struct V_43 * V_44 ;
unsigned int V_10 ;
if ( ! V_84 )
return NULL ;
V_44 = F_28 ( sizeof( * V_44 ) +
( V_84 * sizeof( struct V_45 ) ) , V_85 ) ;
if ( ! V_44 )
return NULL ;
V_44 -> V_62 = V_84 ;
for ( V_10 = 0 ; V_10 < V_44 -> V_62 ; V_10 ++ ) {
struct V_45 * V_46 = & V_44 -> V_65 [ V_10 ] ;
unsigned int V_86 ;
V_86 = F_29 ( V_84 ) ;
V_46 -> V_83 = F_28 ( sizeof( unsigned long ) * V_86 , V_85 ) ;
if ( ! V_46 -> V_83 )
goto V_87;
F_30 ( V_46 -> V_83 , V_84 ) ;
}
return V_44 ;
V_87:
for ( V_10 = 0 ; V_10 < V_44 -> V_62 ; V_10 ++ ) {
struct V_45 * V_46 = & V_44 -> V_65 [ V_10 ] ;
if ( V_46 -> V_83 )
F_26 ( V_46 -> V_83 ) ;
}
if ( V_44 )
F_26 ( V_44 ) ;
return NULL ;
}
