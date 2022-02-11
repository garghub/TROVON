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
if ( F_4 ( V_27 ) )
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
int F_11 ( struct V_31 * V_38 , T_2 V_39 ,
struct V_5 * V_6 )
{
const struct V_7 * V_40 , * V_41 = NULL ;
struct V_1 * V_1 = F_12 ( V_38 ) ;
struct V_3 V_4 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
unsigned int V_46 ;
T_1 V_47 , V_48 ;
bool V_49 = false ;
int V_50 ;
if ( ! F_13 ( V_38 ) )
return - V_51 ;
if ( V_39 != F_14 ( V_52 ) && V_39 != F_14 ( V_53 ) )
return - V_51 ;
V_46 = V_6 -> V_17 . V_54 & 0xFFFFF ;
if ( V_46 > V_1 -> V_55 . V_56 ) {
F_15 ( V_1 -> V_57 ,
L_1 ,
V_46 , V_1 -> V_55 . V_56 ) ;
return - V_58 ;
}
V_43 = V_1 -> V_59 ;
V_47 = F_16 ( V_6 -> V_17 . V_54 ) ;
V_48 = F_16 ( V_6 -> V_17 . V_60 ) ;
if ( V_47 != 0x800 && V_47 >= V_43 -> V_61 )
return - V_22 ;
if ( V_48 >= V_43 -> V_61 )
return - V_22 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
if ( V_39 == F_14 ( V_53 ) ) {
V_40 = V_62 ;
V_49 = true ;
} else {
V_40 = V_63 ;
V_49 = false ;
}
if ( V_47 != 0x800 ) {
if ( ! V_43 -> V_64 [ V_47 - 1 ] . V_60 )
return - V_22 ;
V_41 = V_43 -> V_64 [ V_47 - 1 ] . V_65 ;
if ( ! V_41 )
return - V_22 ;
}
if ( V_48 ) {
const struct V_66 * V_67 ;
bool V_16 = false ;
unsigned int V_10 , V_11 ;
T_1 V_12 , V_13 ;
int V_14 ;
if ( V_43 -> V_64 [ V_48 - 1 ] . V_60 ) {
F_15 ( V_1 -> V_57 ,
L_2 ,
V_48 ) ;
return - V_22 ;
}
V_67 = V_49 ? V_68 : V_69 ;
for ( V_10 = 0 ; V_67 [ V_10 ] . V_70 ; V_10 ++ ) {
if ( V_67 [ V_10 ] . V_71 != V_6 -> V_17 . V_18 -> V_71 ||
V_67 [ V_10 ] . V_72 != V_6 -> V_17 . V_18 -> V_73 ||
V_67 [ V_10 ] . V_13 != V_6 -> V_17 . V_18 -> V_21 ||
V_67 [ V_10 ] . V_74 != V_6 -> V_17 . V_18 -> V_14 )
continue;
for ( V_11 = 0 ; V_11 < V_6 -> V_17 . V_18 -> V_19 ; V_11 ++ ) {
V_14 = V_6 -> V_17 . V_18 -> V_20 [ V_11 ] . V_14 ;
V_12 = V_6 -> V_17 . V_18 -> V_20 [ V_11 ] . V_12 ;
V_13 = V_6 -> V_17 . V_18 -> V_20 [ V_11 ] . V_13 ;
if ( V_67 [ V_10 ] . V_75 == V_14 &&
V_67 [ V_10 ] . V_76 == V_12 &&
V_67 [ V_10 ] . V_77 == V_13 ) {
V_16 = true ;
break;
}
}
if ( ! V_16 )
continue;
V_50 = F_1 ( V_1 , & V_4 , V_6 ,
V_40 , false ) ;
if ( V_50 )
goto V_78;
V_45 = & V_43 -> V_64 [ V_48 - 1 ] ;
V_45 -> V_65 = V_67 [ V_10 ] . V_70 ;
V_45 -> V_60 = V_6 -> V_17 . V_54 ;
memcpy ( & V_45 -> V_4 , & V_4 , sizeof( V_4 ) ) ;
break;
}
if ( ! V_16 )
return - V_22 ;
return 0 ;
}
if ( V_47 != 0x800 && V_43 -> V_64 [ V_47 - 1 ] . V_60 ) {
memcpy ( & V_4 , & V_43 -> V_64 [ V_47 - 1 ] . V_4 , sizeof( V_4 ) ) ;
V_50 = F_1 ( V_1 , & V_4 , V_6 ,
V_41 , true ) ;
if ( V_50 )
goto V_78;
}
V_50 = F_1 ( V_1 , & V_4 , V_6 , V_40 , false ) ;
if ( V_50 )
goto V_78;
V_50 = F_2 ( V_1 , & V_4 , V_6 ) ;
if ( V_50 )
goto V_78;
V_4 . V_12 . V_79 = F_17 ( V_38 ) -> V_80 ;
V_4 . V_13 . V_79 = ~ 0 ;
V_4 . V_81 = 1 ;
V_4 . type = V_49 ? 1 : 0 ;
V_50 = F_18 ( V_38 , V_46 , & V_4 ) ;
if ( V_50 )
goto V_78;
if ( V_47 != 0x800 && V_43 -> V_64 [ V_47 - 1 ] . V_60 )
F_19 ( V_46 , V_43 -> V_64 [ V_47 - 1 ] . V_82 ) ;
V_78:
return V_50 ;
}
int F_20 ( struct V_31 * V_38 , T_2 V_39 ,
struct V_5 * V_6 )
{
struct V_1 * V_1 = F_12 ( V_38 ) ;
unsigned int V_46 , V_83 , V_10 , V_11 ;
struct V_44 * V_45 = NULL ;
struct V_42 * V_43 ;
T_1 V_54 , V_47 ;
int V_50 ;
if ( ! F_13 ( V_38 ) )
return - V_51 ;
V_46 = V_6 -> V_17 . V_54 & 0xFFFFF ;
if ( V_46 > V_1 -> V_55 . V_56 ) {
F_15 ( V_1 -> V_57 ,
L_3 ,
V_46 , V_1 -> V_55 . V_56 ) ;
return - V_58 ;
}
V_43 = V_1 -> V_59 ;
V_54 = V_6 -> V_17 . V_54 ;
V_47 = F_16 ( V_6 -> V_17 . V_54 ) ;
if ( V_47 != 0x800 && V_47 >= V_43 -> V_61 )
return - V_22 ;
if ( V_47 != 0x800 ) {
V_45 = & V_43 -> V_64 [ V_47 - 1 ] ;
if ( ! V_45 -> V_60 )
return - V_22 ;
if ( ! F_21 ( V_46 , V_45 -> V_82 ) )
return - V_22 ;
}
V_50 = F_22 ( V_38 , V_46 ) ;
if ( V_50 )
goto V_78;
if ( V_45 )
F_23 ( V_46 , V_45 -> V_82 ) ;
V_83 = V_1 -> V_55 . V_56 ;
for ( V_10 = 0 ; V_10 < V_43 -> V_61 ; V_10 ++ ) {
V_45 = & V_43 -> V_64 [ V_10 ] ;
if ( V_45 -> V_60 == V_54 ) {
for ( V_11 = 0 ; V_11 < V_83 ; V_11 ++ ) {
if ( ! F_21 ( V_11 , V_45 -> V_82 ) )
continue;
V_50 = F_24 ( V_38 , V_11 , NULL ) ;
if ( V_50 )
goto V_78;
F_23 ( V_11 , V_45 -> V_82 ) ;
}
V_45 -> V_65 = NULL ;
V_45 -> V_60 = 0 ;
memset ( & V_45 -> V_4 , 0 , sizeof( V_45 -> V_4 ) ) ;
break;
}
}
V_78:
return V_50 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
unsigned int V_10 ;
if ( ! V_2 -> V_59 )
return;
V_43 = V_2 -> V_59 ;
for ( V_10 = 0 ; V_10 < V_43 -> V_61 ; V_10 ++ ) {
struct V_44 * V_45 = & V_43 -> V_64 [ V_10 ] ;
F_26 ( V_45 -> V_82 ) ;
}
F_26 ( V_2 -> V_59 ) ;
}
struct V_42 * F_27 ( struct V_1 * V_2 )
{
unsigned int V_83 = V_2 -> V_55 . V_56 ;
struct V_42 * V_43 ;
unsigned int V_10 ;
if ( ! V_83 )
return NULL ;
V_43 = F_28 ( sizeof( * V_43 ) +
( V_83 * sizeof( struct V_44 ) ) ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_61 = V_83 ;
for ( V_10 = 0 ; V_10 < V_43 -> V_61 ; V_10 ++ ) {
struct V_44 * V_45 = & V_43 -> V_64 [ V_10 ] ;
unsigned int V_84 ;
V_84 = F_29 ( V_83 ) ;
V_45 -> V_82 = F_28 ( sizeof( unsigned long ) * V_84 ) ;
if ( ! V_45 -> V_82 )
goto V_85;
F_30 ( V_45 -> V_82 , V_83 ) ;
}
return V_43 ;
V_85:
for ( V_10 = 0 ; V_10 < V_43 -> V_61 ; V_10 ++ ) {
struct V_44 * V_45 = & V_43 -> V_64 [ V_10 ] ;
if ( V_45 -> V_82 )
F_26 ( V_45 -> V_82 ) ;
}
if ( V_43 )
F_26 ( V_43 ) ;
return NULL ;
}
