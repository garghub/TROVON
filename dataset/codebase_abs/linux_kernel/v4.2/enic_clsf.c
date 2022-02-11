int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 V_7 ;
switch ( V_3 -> V_8 . V_9 ) {
case V_10 :
V_7 . V_11 . V_12 . V_13 = V_14 ;
break;
case V_15 :
V_7 . V_11 . V_12 . V_13 = V_16 ;
break;
default:
return - V_17 ;
} ;
V_7 . type = V_18 ;
V_7 . V_11 . V_12 . V_19 = F_2 ( V_3 -> V_20 . V_21 . V_22 ) ;
V_7 . V_11 . V_12 . V_23 = F_2 ( V_3 -> V_20 . V_21 . V_24 ) ;
V_7 . V_11 . V_12 . V_25 = F_3 ( V_3 -> V_26 . V_22 ) ;
V_7 . V_11 . V_12 . V_27 = F_3 ( V_3 -> V_26 . V_24 ) ;
V_7 . V_11 . V_12 . V_28 = V_29 ;
F_4 ( & V_1 -> V_30 ) ;
V_5 = F_5 ( V_1 -> V_31 , V_32 , & V_4 , & V_7 ) ;
F_6 ( & V_1 -> V_30 ) ;
V_5 = ( V_5 == 0 ) ? V_4 : V_5 ;
return V_5 ;
}
int F_7 ( struct V_1 * V_1 , T_1 V_33 )
{
int V_34 ;
F_4 ( & V_1 -> V_30 ) ;
V_34 = F_5 ( V_1 -> V_31 , V_35 , & V_33 , NULL ) ;
F_6 ( & V_1 -> V_30 ) ;
return V_34 ;
}
void F_8 ( struct V_1 * V_1 )
{
int V_36 ;
F_9 ( & V_1 -> V_37 . V_38 ) ;
for ( V_36 = 0 ; V_36 <= V_39 ; V_36 ++ )
F_10 ( & V_1 -> V_37 . V_40 [ V_36 ] ) ;
V_1 -> V_37 . V_41 = V_1 -> V_42 . V_43 ;
V_1 -> V_37 . free = V_1 -> V_37 . V_41 ;
V_1 -> V_37 . V_44 = 0 ;
F_11 ( V_1 ) ;
}
void F_12 ( struct V_1 * V_1 )
{
int V_36 ;
F_13 ( V_1 ) ;
F_4 ( & V_1 -> V_37 . V_38 ) ;
V_1 -> V_37 . free = 0 ;
for ( V_36 = 0 ; V_36 < ( 1 << V_45 ) ; V_36 ++ ) {
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
V_47 = & V_1 -> V_37 . V_40 [ V_36 ] ;
F_14 (n, tmp, hhead, node) {
F_7 ( V_1 , V_51 -> V_52 ) ;
F_15 ( & V_51 -> V_53 ) ;
F_16 ( V_51 ) ;
}
}
F_6 ( & V_1 -> V_37 . V_38 ) ;
}
struct V_50 * F_17 ( struct V_1 * V_1 , T_1 V_52 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < ( 1 << V_45 ) ; V_36 ++ ) {
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
V_47 = & V_1 -> V_37 . V_40 [ V_36 ] ;
F_14 (n, tmp, hhead, node)
if ( V_51 -> V_52 == V_52 )
return V_51 ;
}
return NULL ;
}
void F_18 ( unsigned long V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
bool V_5 ;
int V_54 ;
F_4 ( & V_1 -> V_37 . V_38 ) ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
V_47 = & V_1 -> V_37 . V_40 [ V_1 -> V_37 . V_44 ++ ] ;
F_14 (n, tmp, hhead, node) {
V_5 = F_19 ( V_1 -> V_56 , V_51 -> V_57 ,
V_51 -> V_58 , V_51 -> V_52 ) ;
if ( V_5 ) {
V_5 = F_7 ( V_1 , V_51 -> V_52 ) ;
if ( F_20 ( V_5 ) )
continue;
F_15 ( & V_51 -> V_53 ) ;
F_16 ( V_51 ) ;
V_1 -> V_37 . free ++ ;
}
}
}
F_6 ( & V_1 -> V_37 . V_38 ) ;
F_21 ( & V_1 -> V_37 . V_59 , V_60 + V_61 / 4 ) ;
}
static struct V_50 * F_22 ( struct V_46 * V_62 ,
struct V_2 * V_63 )
{
struct V_50 * V_64 ;
F_23 (tpos, h, node)
if ( V_64 -> V_3 . V_20 . V_21 . V_22 == V_63 -> V_20 . V_21 . V_22 &&
V_64 -> V_3 . V_20 . V_21 . V_24 == V_63 -> V_20 . V_21 . V_24 &&
V_64 -> V_3 . V_26 . V_26 == V_63 -> V_26 . V_26 &&
V_64 -> V_3 . V_8 . V_9 == V_63 -> V_8 . V_9 &&
V_64 -> V_3 . V_8 . V_65 == V_63 -> V_8 . V_65 )
return V_64 ;
return NULL ;
}
int F_24 ( struct V_66 * V_67 , const struct V_68 * V_69 ,
T_1 V_70 , T_2 V_58 )
{
struct V_2 V_3 ;
struct V_50 * V_51 ;
struct V_1 * V_1 ;
T_1 V_71 ;
int V_5 , V_36 ;
V_1 = F_25 ( V_67 ) ;
V_5 = F_26 ( V_69 , & V_3 ) ;
if ( ! V_5 || V_3 . V_8 . V_65 != F_27 ( V_72 ) ||
( V_3 . V_8 . V_9 != V_10 &&
V_3 . V_8 . V_9 != V_15 ) )
return - V_17 ;
V_71 = F_28 ( V_69 ) & V_39 ;
F_4 ( & V_1 -> V_37 . V_38 ) ;
V_51 = F_22 ( & V_1 -> V_37 . V_40 [ V_71 ] , & V_3 ) ;
if ( V_51 ) {
if ( V_70 == V_51 -> V_57 ) {
V_5 = - V_73 ;
goto V_74;
}
V_36 = -- V_1 -> V_37 . free ;
if ( F_20 ( V_36 < 0 ) ) {
V_1 -> V_37 . free ++ ;
V_5 = F_7 ( V_1 , V_51 -> V_52 ) ;
if ( F_20 ( V_5 < 0 ) )
goto V_74;
V_5 = F_1 ( V_1 , & V_3 , V_70 ) ;
if ( V_5 < 0 ) {
F_15 ( & V_51 -> V_53 ) ;
V_1 -> V_37 . free ++ ;
goto V_74;
}
} else {
int V_34 ;
V_5 = F_1 ( V_1 , & V_3 , V_70 ) ;
if ( V_5 < 0 ) {
V_1 -> V_37 . free ++ ;
goto V_74;
}
V_34 = F_7 ( V_1 , V_51 -> V_52 ) ;
if ( F_20 ( V_34 < 0 ) ) {
struct V_50 * V_75 ;
struct V_46 * V_76 ;
V_76 = & V_1 -> V_37 . V_40 [ V_71 ] ;
V_75 = F_29 ( sizeof( * V_75 ) , V_77 ) ;
if ( V_75 ) {
V_75 -> V_52 = V_51 -> V_52 ;
F_30 ( & V_75 -> V_53 ) ;
F_31 ( & V_75 -> V_53 , V_76 ) ;
}
} else {
V_1 -> V_37 . free ++ ;
}
}
V_51 -> V_57 = V_70 ;
V_51 -> V_52 = V_5 ;
V_51 -> V_58 = V_58 ;
} else {
V_36 = -- V_1 -> V_37 . free ;
if ( V_36 <= 0 ) {
V_1 -> V_37 . free ++ ;
V_5 = - V_78 ;
goto V_74;
}
V_51 = F_29 ( sizeof( * V_51 ) , V_77 ) ;
if ( ! V_51 ) {
V_5 = - V_79 ;
V_1 -> V_37 . free ++ ;
goto V_74;
}
V_5 = F_1 ( V_1 , & V_3 , V_70 ) ;
if ( V_5 < 0 ) {
F_16 ( V_51 ) ;
V_1 -> V_37 . free ++ ;
goto V_74;
}
V_51 -> V_57 = V_70 ;
V_51 -> V_52 = V_5 ;
V_51 -> V_58 = V_58 ;
V_51 -> V_3 = V_3 ;
F_30 ( & V_51 -> V_53 ) ;
F_31 ( & V_51 -> V_53 , & V_1 -> V_37 . V_40 [ V_71 ] ) ;
}
V_74:
F_6 ( & V_1 -> V_37 . V_38 ) ;
return V_5 ;
}
