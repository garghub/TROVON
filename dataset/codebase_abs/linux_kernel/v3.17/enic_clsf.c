int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 V_7 ;
switch ( V_3 -> V_8 ) {
case V_9 :
V_7 . V_10 . V_11 . V_12 = V_13 ;
break;
case V_14 :
V_7 . V_10 . V_11 . V_12 = V_15 ;
break;
default:
return - V_16 ;
} ;
V_7 . type = V_17 ;
V_7 . V_10 . V_11 . V_18 = F_2 ( V_3 -> V_19 ) ;
V_7 . V_10 . V_11 . V_20 = F_2 ( V_3 -> V_21 ) ;
V_7 . V_10 . V_11 . V_22 = F_3 ( V_3 -> V_23 [ 0 ] ) ;
V_7 . V_10 . V_11 . V_24 = F_3 ( V_3 -> V_23 [ 1 ] ) ;
V_7 . V_10 . V_11 . V_25 = V_26 ;
F_4 ( & V_1 -> V_27 ) ;
V_5 = F_5 ( V_1 -> V_28 , V_29 , & V_4 , & V_7 ) ;
F_6 ( & V_1 -> V_27 ) ;
V_5 = ( V_5 == 0 ) ? V_4 : V_5 ;
return V_5 ;
}
int F_7 ( struct V_1 * V_1 , T_1 V_30 )
{
int V_31 ;
F_4 ( & V_1 -> V_27 ) ;
V_31 = F_5 ( V_1 -> V_28 , V_32 , & V_30 , NULL ) ;
F_6 ( & V_1 -> V_27 ) ;
return V_31 ;
}
void F_8 ( struct V_1 * V_1 )
{
int V_33 ;
F_9 ( & V_1 -> V_34 . V_35 ) ;
for ( V_33 = 0 ; V_33 <= V_36 ; V_33 ++ )
F_10 ( & V_1 -> V_34 . V_37 [ V_33 ] ) ;
V_1 -> V_34 . V_38 = V_1 -> V_39 . V_40 ;
V_1 -> V_34 . free = V_1 -> V_34 . V_38 ;
V_1 -> V_34 . V_41 = 0 ;
F_11 ( V_1 ) ;
}
void F_12 ( struct V_1 * V_1 )
{
int V_33 ;
F_13 ( V_1 ) ;
F_14 ( & V_1 -> V_34 . V_35 ) ;
V_1 -> V_34 . free = 0 ;
for ( V_33 = 0 ; V_33 < ( 1 << V_42 ) ; V_33 ++ ) {
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
V_44 = & V_1 -> V_34 . V_37 [ V_33 ] ;
F_15 (n, tmp, hhead, node) {
F_7 ( V_1 , V_48 -> V_49 ) ;
F_16 ( & V_48 -> V_50 ) ;
F_17 ( V_48 ) ;
}
}
F_18 ( & V_1 -> V_34 . V_35 ) ;
}
struct V_47 * F_19 ( struct V_1 * V_1 , T_1 V_49 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < ( 1 << V_42 ) ; V_33 ++ ) {
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
V_44 = & V_1 -> V_34 . V_37 [ V_33 ] ;
F_15 (n, tmp, hhead, node)
if ( V_48 -> V_49 == V_49 )
return V_48 ;
}
return NULL ;
}
void F_20 ( unsigned long V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
bool V_5 ;
int V_51 ;
F_14 ( & V_1 -> V_34 . V_35 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
V_44 = & V_1 -> V_34 . V_37 [ V_1 -> V_34 . V_41 ++ ] ;
F_15 (n, tmp, hhead, node) {
V_5 = F_21 ( V_1 -> V_53 , V_48 -> V_54 ,
V_48 -> V_55 , V_48 -> V_49 ) ;
if ( V_5 ) {
V_5 = F_7 ( V_1 , V_48 -> V_49 ) ;
if ( F_22 ( V_5 ) )
continue;
F_16 ( & V_48 -> V_50 ) ;
F_17 ( V_48 ) ;
V_1 -> V_34 . free ++ ;
}
}
}
F_18 ( & V_1 -> V_34 . V_35 ) ;
F_23 ( & V_1 -> V_34 . V_56 , V_57 + V_58 / 4 ) ;
}
static struct V_47 * F_24 ( struct V_43 * V_59 ,
struct V_2 * V_60 )
{
struct V_47 * V_61 ;
F_25 (tpos, h, node)
if ( V_61 -> V_3 . V_19 == V_60 -> V_19 &&
V_61 -> V_3 . V_21 == V_60 -> V_21 &&
V_61 -> V_3 . V_62 == V_60 -> V_62 &&
V_61 -> V_3 . V_8 == V_60 -> V_8 &&
V_61 -> V_3 . V_63 == V_60 -> V_63 )
return V_61 ;
return NULL ;
}
int F_26 ( struct V_64 * V_65 , const struct V_66 * V_67 ,
T_1 V_68 , T_2 V_55 )
{
struct V_2 V_3 ;
struct V_47 * V_48 ;
struct V_1 * V_1 ;
T_1 V_69 ;
int V_5 , V_33 ;
V_1 = F_27 ( V_65 ) ;
V_5 = F_28 ( V_67 , & V_3 ) ;
if ( ! V_5 || V_3 . V_63 != F_29 ( V_70 ) ||
( V_3 . V_8 != V_9 && V_3 . V_8 != V_14 ) )
return - V_16 ;
V_69 = F_30 ( V_67 ) & V_36 ;
F_14 ( & V_1 -> V_34 . V_35 ) ;
V_48 = F_24 ( & V_1 -> V_34 . V_37 [ V_69 ] , & V_3 ) ;
if ( V_48 ) {
if ( V_68 == V_48 -> V_54 ) {
V_5 = - V_71 ;
goto V_72;
}
V_33 = -- V_1 -> V_34 . free ;
if ( F_22 ( V_33 < 0 ) ) {
V_1 -> V_34 . free ++ ;
V_5 = F_7 ( V_1 , V_48 -> V_49 ) ;
if ( F_22 ( V_5 < 0 ) )
goto V_72;
V_5 = F_1 ( V_1 , & V_3 , V_68 ) ;
if ( V_5 < 0 ) {
F_16 ( & V_48 -> V_50 ) ;
V_1 -> V_34 . free ++ ;
goto V_72;
}
} else {
int V_31 ;
V_5 = F_1 ( V_1 , & V_3 , V_68 ) ;
if ( V_5 < 0 ) {
V_1 -> V_34 . free ++ ;
goto V_72;
}
V_31 = F_7 ( V_1 , V_48 -> V_49 ) ;
if ( F_22 ( V_31 < 0 ) ) {
struct V_47 * V_73 ;
struct V_43 * V_74 ;
V_74 = & V_1 -> V_34 . V_37 [ V_69 ] ;
V_73 = F_31 ( sizeof( * V_73 ) , V_75 ) ;
if ( V_73 ) {
V_73 -> V_49 = V_48 -> V_49 ;
F_32 ( & V_73 -> V_50 ) ;
F_33 ( & V_73 -> V_50 , V_74 ) ;
}
} else {
V_1 -> V_34 . free ++ ;
}
}
V_48 -> V_54 = V_68 ;
V_48 -> V_49 = V_5 ;
V_48 -> V_55 = V_55 ;
} else {
V_33 = -- V_1 -> V_34 . free ;
if ( V_33 <= 0 ) {
V_1 -> V_34 . free ++ ;
V_5 = - V_76 ;
goto V_72;
}
V_48 = F_31 ( sizeof( * V_48 ) , V_75 ) ;
if ( ! V_48 ) {
V_5 = - V_77 ;
V_1 -> V_34 . free ++ ;
goto V_72;
}
V_5 = F_1 ( V_1 , & V_3 , V_68 ) ;
if ( V_5 < 0 ) {
F_17 ( V_48 ) ;
V_1 -> V_34 . free ++ ;
goto V_72;
}
V_48 -> V_54 = V_68 ;
V_48 -> V_49 = V_5 ;
V_48 -> V_55 = V_55 ;
V_48 -> V_3 = V_3 ;
F_32 ( & V_48 -> V_50 ) ;
F_33 ( & V_48 -> V_50 , & V_1 -> V_34 . V_37 [ V_69 ] ) ;
}
V_72:
F_18 ( & V_1 -> V_34 . V_35 ) ;
return V_5 ;
}
