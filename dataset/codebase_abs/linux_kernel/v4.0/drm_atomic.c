static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
F_2 ( V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
}
struct V_1 *
F_3 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_12 = true ;
V_2 -> V_13 = F_5 ( V_10 -> V_14 . V_13 ) ;
V_2 -> V_5 = F_6 ( V_10 -> V_14 . V_15 ,
sizeof( * V_2 -> V_5 ) , V_11 ) ;
if ( ! V_2 -> V_5 )
goto V_16;
V_2 -> V_6 = F_6 ( V_10 -> V_14 . V_15 ,
sizeof( * V_2 -> V_6 ) , V_11 ) ;
if ( ! V_2 -> V_6 )
goto V_16;
V_2 -> V_7 = F_6 ( V_10 -> V_14 . V_17 ,
sizeof( * V_2 -> V_7 ) , V_11 ) ;
if ( ! V_2 -> V_7 )
goto V_16;
V_2 -> V_8 = F_6 ( V_10 -> V_14 . V_17 ,
sizeof( * V_2 -> V_8 ) , V_11 ) ;
if ( ! V_2 -> V_8 )
goto V_16;
V_2 -> V_3 = F_6 ( V_2 -> V_13 ,
sizeof( * V_2 -> V_3 ) ,
V_11 ) ;
if ( ! V_2 -> V_3 )
goto V_16;
V_2 -> V_4 = F_6 ( V_2 -> V_13 ,
sizeof( * V_2 -> V_4 ) ,
V_11 ) ;
if ( ! V_2 -> V_4 )
goto V_16;
V_2 -> V_10 = V_10 ;
F_7 ( L_1 , V_2 ) ;
return V_2 ;
V_16:
F_1 ( V_2 ) ;
return NULL ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
int V_20 ;
F_7 ( L_2 , V_2 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_13 ; V_20 ++ ) {
struct V_21 * V_22 = V_2 -> V_3 [ V_20 ] ;
if ( ! V_22 )
continue;
F_9 ( ! F_10 ( & V_19 -> V_23 ) ) ;
V_22 -> V_24 -> V_25 ( V_22 ,
V_2 -> V_4 [ V_20 ] ) ;
V_2 -> V_4 [ V_20 ] = NULL ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_15 ; V_20 ++ ) {
struct V_26 * V_27 = V_2 -> V_5 [ V_20 ] ;
if ( ! V_27 )
continue;
V_27 -> V_24 -> V_25 ( V_27 ,
V_2 -> V_6 [ V_20 ] ) ;
V_2 -> V_6 [ V_20 ] = NULL ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_17 ; V_20 ++ ) {
struct V_28 * V_29 = V_2 -> V_7 [ V_20 ] ;
if ( ! V_29 )
continue;
V_29 -> V_24 -> V_25 ( V_29 ,
V_2 -> V_8 [ V_20 ] ) ;
V_2 -> V_8 [ V_20 ] = NULL ;
}
}
void F_11 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_7 ( L_3 , V_2 ) ;
F_1 ( V_2 ) ;
}
struct V_30 *
F_12 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
int V_31 , V_32 ;
struct V_30 * V_33 ;
V_32 = F_13 ( V_27 ) ;
if ( V_2 -> V_6 [ V_32 ] )
return V_2 -> V_6 [ V_32 ] ;
V_31 = F_14 ( & V_27 -> V_34 , V_2 -> V_35 ) ;
if ( V_31 )
return F_15 ( V_31 ) ;
V_33 = V_27 -> V_24 -> V_36 ( V_27 ) ;
if ( ! V_33 )
return F_15 ( - V_37 ) ;
V_2 -> V_6 [ V_32 ] = V_33 ;
V_2 -> V_5 [ V_32 ] = V_27 ;
V_33 -> V_2 = V_2 ;
F_7 ( L_4 ,
V_27 -> V_38 . V_39 , V_33 , V_2 ) ;
return V_33 ;
}
int F_16 ( struct V_26 * V_27 ,
struct V_30 * V_2 , struct V_40 * V_41 ,
T_1 V_42 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
if ( V_41 == V_19 -> V_43 ) {
V_2 -> V_44 = V_42 ;
} else if ( V_27 -> V_24 -> V_45 )
return V_27 -> V_24 -> V_45 ( V_27 , V_2 , V_41 , V_42 ) ;
return - V_46 ;
}
int F_17 ( struct V_26 * V_27 ,
const struct V_30 * V_2 ,
struct V_40 * V_41 , T_1 * V_42 )
{
if ( V_27 -> V_24 -> V_47 )
return V_27 -> V_24 -> V_47 ( V_27 , V_2 , V_41 , V_42 ) ;
return - V_46 ;
}
static int F_18 ( struct V_26 * V_27 ,
struct V_30 * V_2 )
{
if ( V_2 -> V_44 && ! V_2 -> V_48 ) {
F_7 ( L_5 ,
V_27 -> V_38 . V_39 ) ;
return - V_46 ;
}
return 0 ;
}
struct V_49 *
F_19 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_31 , V_32 ;
struct V_49 * V_50 ;
V_32 = F_20 ( V_29 ) ;
if ( V_2 -> V_8 [ V_32 ] )
return V_2 -> V_8 [ V_32 ] ;
V_31 = F_14 ( & V_29 -> V_34 , V_2 -> V_35 ) ;
if ( V_31 )
return F_15 ( V_31 ) ;
V_50 = V_29 -> V_24 -> V_36 ( V_29 ) ;
if ( ! V_50 )
return F_15 ( - V_37 ) ;
V_2 -> V_8 [ V_32 ] = V_50 ;
V_2 -> V_7 [ V_32 ] = V_29 ;
V_50 -> V_2 = V_2 ;
F_7 ( L_6 ,
V_29 -> V_38 . V_39 , V_50 , V_2 ) ;
if ( V_50 -> V_27 ) {
struct V_30 * V_33 ;
V_33 = F_12 ( V_2 ,
V_50 -> V_27 ) ;
if ( F_21 ( V_33 ) )
return F_22 ( V_33 ) ;
}
return V_50 ;
}
int F_23 ( struct V_28 * V_29 ,
struct V_49 * V_2 , struct V_40 * V_41 ,
T_1 V_42 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
if ( V_41 == V_19 -> V_51 ) {
struct V_52 * V_53 = F_24 ( V_10 , V_42 ) ;
F_25 ( V_2 , V_53 ) ;
if ( V_53 )
F_26 ( V_53 ) ;
} else if ( V_41 == V_19 -> V_54 ) {
struct V_26 * V_27 = F_27 ( V_10 , V_42 ) ;
return F_28 ( V_2 , V_27 ) ;
} else if ( V_41 == V_19 -> V_55 ) {
V_2 -> V_56 = F_29 ( V_42 ) ;
} else if ( V_41 == V_19 -> V_57 ) {
V_2 -> V_58 = F_29 ( V_42 ) ;
} else if ( V_41 == V_19 -> V_59 ) {
V_2 -> V_60 = V_42 ;
} else if ( V_41 == V_19 -> V_61 ) {
V_2 -> V_62 = V_42 ;
} else if ( V_41 == V_19 -> V_63 ) {
V_2 -> V_64 = V_42 ;
} else if ( V_41 == V_19 -> V_65 ) {
V_2 -> V_66 = V_42 ;
} else if ( V_41 == V_19 -> V_67 ) {
V_2 -> V_68 = V_42 ;
} else if ( V_41 == V_19 -> V_69 ) {
V_2 -> V_70 = V_42 ;
} else if ( V_41 == V_19 -> V_71 ) {
V_2 -> V_72 = V_42 ;
} else if ( V_29 -> V_24 -> V_45 ) {
return V_29 -> V_24 -> V_45 ( V_29 , V_2 ,
V_41 , V_42 ) ;
} else {
return - V_46 ;
}
return 0 ;
}
static int
F_30 ( struct V_28 * V_29 ,
const struct V_49 * V_2 ,
struct V_40 * V_41 , T_1 * V_42 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
if ( V_41 == V_19 -> V_51 ) {
* V_42 = ( V_2 -> V_53 ) ? V_2 -> V_53 -> V_38 . V_39 : 0 ;
} else if ( V_41 == V_19 -> V_54 ) {
* V_42 = ( V_2 -> V_27 ) ? V_2 -> V_27 -> V_38 . V_39 : 0 ;
} else if ( V_41 == V_19 -> V_55 ) {
* V_42 = F_31 ( V_2 -> V_56 ) ;
} else if ( V_41 == V_19 -> V_57 ) {
* V_42 = F_31 ( V_2 -> V_58 ) ;
} else if ( V_41 == V_19 -> V_59 ) {
* V_42 = V_2 -> V_60 ;
} else if ( V_41 == V_19 -> V_61 ) {
* V_42 = V_2 -> V_62 ;
} else if ( V_41 == V_19 -> V_63 ) {
* V_42 = V_2 -> V_64 ;
} else if ( V_41 == V_19 -> V_65 ) {
* V_42 = V_2 -> V_66 ;
} else if ( V_41 == V_19 -> V_67 ) {
* V_42 = V_2 -> V_68 ;
} else if ( V_41 == V_19 -> V_69 ) {
* V_42 = V_2 -> V_70 ;
} else if ( V_29 -> V_24 -> V_47 ) {
return V_29 -> V_24 -> V_47 ( V_29 , V_2 , V_41 , V_42 ) ;
} else {
return - V_46 ;
}
return 0 ;
}
static int F_32 ( struct V_28 * V_29 ,
struct V_49 * V_2 )
{
unsigned int V_73 , V_74 ;
unsigned int V_20 ;
if ( F_9 ( V_2 -> V_27 && ! V_2 -> V_53 ) ) {
F_7 ( L_7 ) ;
return - V_46 ;
} else if ( F_9 ( V_2 -> V_53 && ! V_2 -> V_27 ) ) {
F_7 ( L_8 ) ;
return - V_46 ;
}
if ( ! V_2 -> V_27 )
return 0 ;
if ( ! ( V_29 -> V_75 & F_33 ( V_2 -> V_27 ) ) ) {
F_7 ( L_9 ) ;
return - V_46 ;
}
for ( V_20 = 0 ; V_20 < V_29 -> V_76 ; V_20 ++ )
if ( V_2 -> V_53 -> V_77 == V_29 -> V_78 [ V_20 ] )
break;
if ( V_20 == V_29 -> V_76 ) {
F_7 ( L_10 ,
F_34 ( V_2 -> V_53 -> V_77 ) ) ;
return - V_46 ;
}
if ( V_2 -> V_60 > V_79 ||
V_2 -> V_56 > V_79 - ( V_80 ) V_2 -> V_60 ||
V_2 -> V_62 > V_79 ||
V_2 -> V_58 > V_79 - ( V_80 ) V_2 -> V_62 ) {
F_7 ( L_11 ,
V_2 -> V_60 , V_2 -> V_62 ,
V_2 -> V_56 , V_2 -> V_58 ) ;
return - V_81 ;
}
V_73 = V_2 -> V_53 -> V_82 << 16 ;
V_74 = V_2 -> V_53 -> V_83 << 16 ;
if ( V_2 -> V_68 > V_73 ||
V_2 -> V_64 > V_73 - V_2 -> V_68 ||
V_2 -> V_70 > V_74 ||
V_2 -> V_66 > V_74 - V_2 -> V_70 ) {
F_7 ( L_12
L_13 ,
V_2 -> V_68 >> 16 , ( ( V_2 -> V_68 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_70 >> 16 , ( ( V_2 -> V_70 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_64 >> 16 , ( ( V_2 -> V_64 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_66 >> 16 , ( ( V_2 -> V_66 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_84 ;
}
return 0 ;
}
struct V_85 *
F_35 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_31 , V_32 ;
struct V_18 * V_19 = & V_22 -> V_10 -> V_14 ;
struct V_85 * V_86 ;
V_31 = F_14 ( & V_19 -> V_23 , V_2 -> V_35 ) ;
if ( V_31 )
return F_15 ( V_31 ) ;
V_32 = F_36 ( V_22 ) ;
if ( V_32 >= V_2 -> V_13 ) {
F_7 ( L_14 ) ;
return F_15 ( - V_87 ) ;
}
if ( V_2 -> V_4 [ V_32 ] )
return V_2 -> V_4 [ V_32 ] ;
V_86 = V_22 -> V_24 -> V_36 ( V_22 ) ;
if ( ! V_86 )
return F_15 ( - V_37 ) ;
V_2 -> V_4 [ V_32 ] = V_86 ;
V_2 -> V_3 [ V_32 ] = V_22 ;
V_86 -> V_2 = V_2 ;
F_7 ( L_15 ,
V_22 -> V_38 . V_39 , V_86 , V_2 ) ;
if ( V_86 -> V_27 ) {
struct V_30 * V_33 ;
V_33 = F_12 ( V_2 ,
V_86 -> V_27 ) ;
if ( F_21 ( V_33 ) )
return F_22 ( V_33 ) ;
}
return V_86 ;
}
int F_37 ( struct V_21 * V_22 ,
struct V_85 * V_2 , struct V_40 * V_41 ,
T_1 V_42 )
{
struct V_9 * V_10 = V_22 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
if ( V_41 == V_19 -> V_54 ) {
struct V_26 * V_27 = F_27 ( V_10 , V_42 ) ;
return F_38 ( V_2 , V_27 ) ;
} else if ( V_41 == V_19 -> V_88 ) {
return - V_46 ;
} else if ( V_22 -> V_24 -> V_45 ) {
return V_22 -> V_24 -> V_45 ( V_22 ,
V_2 , V_41 , V_42 ) ;
} else {
return - V_46 ;
}
}
static int
F_39 ( struct V_21 * V_22 ,
const struct V_85 * V_2 ,
struct V_40 * V_41 , T_1 * V_42 )
{
struct V_9 * V_10 = V_22 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
if ( V_41 == V_19 -> V_54 ) {
* V_42 = ( V_2 -> V_27 ) ? V_2 -> V_27 -> V_38 . V_39 : 0 ;
} else if ( V_41 == V_19 -> V_88 ) {
* V_42 = V_22 -> V_89 ;
} else if ( V_22 -> V_24 -> V_47 ) {
return V_22 -> V_24 -> V_47 ( V_22 ,
V_2 , V_41 , V_42 ) ;
} else {
return - V_46 ;
}
return 0 ;
}
int F_40 ( struct V_90 * V_91 ,
struct V_40 * V_41 , T_1 * V_42 )
{
struct V_9 * V_10 = V_41 -> V_10 ;
int V_31 ;
switch ( V_91 -> type ) {
case V_92 : {
struct V_21 * V_22 = F_41 ( V_91 ) ;
F_9 ( ! F_10 ( & V_10 -> V_14 . V_23 ) ) ;
V_31 = F_39 ( V_22 ,
V_22 -> V_2 , V_41 , V_42 ) ;
break;
}
case V_93 : {
struct V_26 * V_27 = F_42 ( V_91 ) ;
F_9 ( ! F_10 ( & V_27 -> V_34 ) ) ;
V_31 = F_17 ( V_27 ,
V_27 -> V_2 , V_41 , V_42 ) ;
break;
}
case V_94 : {
struct V_28 * V_29 = F_43 ( V_91 ) ;
F_9 ( ! F_10 ( & V_29 -> V_34 ) ) ;
V_31 = F_30 ( V_29 ,
V_29 -> V_2 , V_41 , V_42 ) ;
break;
}
default:
V_31 = - V_46 ;
break;
}
return V_31 ;
}
int
F_28 ( struct V_49 * V_50 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_50 -> V_29 ;
struct V_30 * V_33 ;
if ( V_50 -> V_27 ) {
V_33 = F_12 ( V_50 -> V_2 ,
V_50 -> V_27 ) ;
if ( F_9 ( F_21 ( V_33 ) ) )
return F_44 ( V_33 ) ;
V_33 -> V_95 &= ~ ( 1 << F_20 ( V_29 ) ) ;
}
V_50 -> V_27 = V_27 ;
if ( V_27 ) {
V_33 = F_12 ( V_50 -> V_2 ,
V_27 ) ;
if ( F_21 ( V_33 ) )
return F_44 ( V_33 ) ;
V_33 -> V_95 |= ( 1 << F_20 ( V_29 ) ) ;
}
if ( V_27 )
F_7 ( L_16 ,
V_50 , V_27 -> V_38 . V_39 ) ;
else
F_7 ( L_17 , V_50 ) ;
return 0 ;
}
void
F_25 ( struct V_49 * V_50 ,
struct V_52 * V_53 )
{
if ( V_50 -> V_53 )
F_26 ( V_50 -> V_53 ) ;
if ( V_53 )
F_45 ( V_53 ) ;
V_50 -> V_53 = V_53 ;
if ( V_53 )
F_7 ( L_18 ,
V_53 -> V_38 . V_39 , V_50 ) ;
else
F_7 ( L_19 , V_50 ) ;
}
int
F_38 ( struct V_85 * V_96 ,
struct V_26 * V_27 )
{
struct V_30 * V_33 ;
if ( V_27 ) {
V_33 = F_12 ( V_96 -> V_2 , V_27 ) ;
if ( F_21 ( V_33 ) )
return F_44 ( V_33 ) ;
}
V_96 -> V_27 = V_27 ;
if ( V_27 )
F_7 ( L_20 ,
V_96 , V_27 -> V_38 . V_39 ) ;
else
F_7 ( L_21 ,
V_96 ) ;
return 0 ;
}
int
F_46 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_14 ;
struct V_21 * V_22 ;
struct V_85 * V_96 ;
int V_31 ;
V_31 = F_14 ( & V_19 -> V_23 , V_2 -> V_35 ) ;
if ( V_31 )
return V_31 ;
F_7 ( L_22 ,
V_27 -> V_38 . V_39 , V_2 ) ;
F_47 (connector, &config->connector_list, head) {
if ( V_22 -> V_2 -> V_27 != V_27 )
continue;
V_96 = F_35 ( V_2 , V_22 ) ;
if ( F_21 ( V_96 ) )
return F_44 ( V_96 ) ;
}
return 0 ;
}
int
F_48 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
int V_20 , V_97 = 0 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_13 ; V_20 ++ ) {
struct V_85 * V_96 ;
V_96 = V_2 -> V_4 [ V_20 ] ;
if ( V_96 && V_96 -> V_27 == V_27 )
V_97 ++ ;
}
F_7 ( L_23 ,
V_2 , V_97 , V_27 -> V_38 . V_39 ) ;
return V_97 ;
}
void F_49 ( struct V_1 * V_2 )
{
int V_31 ;
V_98:
F_50 ( V_2 -> V_35 ) ;
V_31 = F_14 ( & V_2 -> V_10 -> V_14 . V_23 ,
V_2 -> V_35 ) ;
if ( V_31 )
goto V_98;
V_31 = F_51 ( V_2 -> V_10 ,
V_2 -> V_35 ) ;
if ( V_31 )
goto V_98;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
int V_99 = V_19 -> V_17 ;
int V_100 = V_19 -> V_15 ;
int V_20 , V_31 = 0 ;
F_7 ( L_24 , V_2 ) ;
for ( V_20 = 0 ; V_20 < V_99 ; V_20 ++ ) {
struct V_28 * V_29 = V_2 -> V_7 [ V_20 ] ;
if ( ! V_29 )
continue;
V_31 = F_32 ( V_29 , V_2 -> V_8 [ V_20 ] ) ;
if ( V_31 ) {
F_7 ( L_25 ,
V_29 -> V_38 . V_39 ) ;
return V_31 ;
}
}
for ( V_20 = 0 ; V_20 < V_100 ; V_20 ++ ) {
struct V_26 * V_27 = V_2 -> V_5 [ V_20 ] ;
if ( ! V_27 )
continue;
V_31 = F_18 ( V_27 , V_2 -> V_6 [ V_20 ] ) ;
if ( V_31 ) {
F_7 ( L_26 ,
V_27 -> V_38 . V_39 ) ;
return V_31 ;
}
}
if ( V_19 -> V_24 -> V_101 )
V_31 = V_19 -> V_24 -> V_101 ( V_2 -> V_10 , V_2 ) ;
if ( ! V_2 -> V_12 ) {
for ( V_20 = 0 ; V_20 < V_100 ; V_20 ++ ) {
struct V_26 * V_27 = V_2 -> V_5 [ V_20 ] ;
struct V_30 * V_33 = V_2 -> V_6 [ V_20 ] ;
if ( ! V_27 )
continue;
if ( V_33 -> V_102 ||
V_33 -> V_103 ) {
F_7 ( L_27 ,
V_27 -> V_38 . V_39 ) ;
return - V_46 ;
}
}
}
return V_31 ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_14 ;
int V_31 ;
V_31 = F_52 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_7 ( L_28 , V_2 ) ;
return V_19 -> V_24 -> V_104 ( V_2 -> V_10 , V_2 , false ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_14 ;
int V_31 ;
V_31 = F_52 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_7 ( L_29 , V_2 ) ;
return V_19 -> V_24 -> V_104 ( V_2 -> V_10 , V_2 , true ) ;
}
static struct V_105 * F_55 (
struct V_9 * V_10 , struct V_106 * V_107 , T_1 V_108 )
{
struct V_105 * V_109 = NULL ;
unsigned long V_110 ;
F_56 ( & V_10 -> V_111 , V_110 ) ;
if ( V_107 -> V_112 < sizeof V_109 -> V_113 ) {
F_57 ( & V_10 -> V_111 , V_110 ) ;
goto V_114;
}
V_107 -> V_112 -= sizeof V_109 -> V_113 ;
F_57 ( & V_10 -> V_111 , V_110 ) ;
V_109 = F_4 ( sizeof *V_109 , V_11 ) ;
if ( V_109 == NULL ) {
F_56 ( & V_10 -> V_111 , V_110 ) ;
V_107 -> V_112 += sizeof V_109 -> V_113 ;
F_57 ( & V_10 -> V_111 , V_110 ) ;
goto V_114;
}
V_109 -> V_113 . V_38 . type = V_115 ;
V_109 -> V_113 . V_38 . V_116 = sizeof V_109 -> V_113 ;
V_109 -> V_113 . V_108 = V_108 ;
V_109 -> V_38 . V_113 = & V_109 -> V_113 . V_38 ;
V_109 -> V_38 . V_107 = V_107 ;
V_109 -> V_38 . V_117 = ( void ( * ) ( struct V_118 * ) ) F_2 ;
V_114:
return V_109 ;
}
static void F_58 ( struct V_9 * V_10 ,
struct V_106 * V_107 , struct V_105 * V_109 )
{
unsigned long V_110 ;
F_56 ( & V_10 -> V_111 , V_110 ) ;
V_107 -> V_112 += sizeof V_109 -> V_113 ;
F_57 ( & V_10 -> V_111 , V_110 ) ;
F_2 ( V_109 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_90 * V_91 , struct V_40 * V_119 ,
T_1 V_120 )
{
struct V_90 * V_121 ;
int V_31 ;
if ( ! F_60 ( V_119 , V_120 , & V_121 ) )
return - V_46 ;
switch ( V_91 -> type ) {
case V_92 : {
struct V_21 * V_22 = F_41 ( V_91 ) ;
struct V_85 * V_86 ;
V_86 = F_35 ( V_2 , V_22 ) ;
if ( F_21 ( V_86 ) ) {
V_31 = F_44 ( V_86 ) ;
break;
}
V_31 = F_37 ( V_22 ,
V_86 , V_119 , V_120 ) ;
break;
}
case V_93 : {
struct V_26 * V_27 = F_42 ( V_91 ) ;
struct V_30 * V_33 ;
V_33 = F_12 ( V_2 , V_27 ) ;
if ( F_21 ( V_33 ) ) {
V_31 = F_44 ( V_33 ) ;
break;
}
V_31 = F_16 ( V_27 ,
V_33 , V_119 , V_120 ) ;
break;
}
case V_94 : {
struct V_28 * V_29 = F_43 ( V_91 ) ;
struct V_49 * V_50 ;
V_50 = F_19 ( V_2 , V_29 ) ;
if ( F_21 ( V_50 ) ) {
V_31 = F_44 ( V_50 ) ;
break;
}
V_31 = F_23 ( V_29 ,
V_50 , V_119 , V_120 ) ;
break;
}
default:
V_31 = - V_46 ;
break;
}
F_61 ( V_119 , V_121 ) ;
return V_31 ;
}
int F_62 ( struct V_9 * V_10 ,
void * V_122 , struct V_106 * V_107 )
{
struct V_123 * V_124 = V_122 ;
T_2 T_3 * V_125 = ( T_2 T_3 * ) ( unsigned long ) ( V_124 -> V_125 ) ;
T_2 T_3 * V_126 = ( T_2 T_3 * ) ( unsigned long ) ( V_124 -> V_126 ) ;
T_2 T_3 * V_127 = ( T_2 T_3 * ) ( unsigned long ) ( V_124 -> V_127 ) ;
T_1 T_3 * V_128 = ( T_1 T_3 * ) ( unsigned long ) ( V_124 -> V_128 ) ;
unsigned int V_129 , V_130 ;
struct V_1 * V_2 ;
struct V_131 V_132 ;
struct V_28 * V_29 ;
unsigned V_95 = 0 ;
int V_31 = 0 ;
unsigned int V_20 , V_133 ;
if ( ! F_63 ( V_10 , V_134 ) )
return - V_46 ;
if ( ! V_107 -> V_135 )
return - V_46 ;
if ( V_124 -> V_110 & ~ V_136 )
return - V_46 ;
if ( V_124 -> V_137 )
return - V_46 ;
if ( ( V_124 -> V_110 & V_138 ) &&
! V_10 -> V_14 . V_139 )
return - V_46 ;
if ( ( V_124 -> V_110 & V_140 ) &&
( V_124 -> V_110 & V_141 ) )
return - V_46 ;
F_64 ( & V_132 , 0 ) ;
V_2 = F_3 ( V_10 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_35 = & V_132 ;
V_2 -> V_12 = ! ! ( V_124 -> V_110 & V_142 ) ;
V_98:
V_129 = 0 ;
V_130 = 0 ;
for ( V_20 = 0 ; V_20 < V_124 -> V_143 ; V_20 ++ ) {
T_2 V_144 , V_145 ;
struct V_90 * V_91 ;
if ( F_65 ( V_144 , V_125 + V_129 ) ) {
V_31 = - V_146 ;
goto V_16;
}
V_91 = F_66 ( V_10 , V_144 , V_147 ) ;
if ( ! V_91 || ! V_91 -> V_148 ) {
V_31 = - V_149 ;
goto V_16;
}
if ( V_91 -> type == V_94 ) {
V_29 = F_43 ( V_91 ) ;
V_95 |= ( 1 << F_20 ( V_29 ) ) ;
V_29 -> V_150 = V_29 -> V_53 ;
}
if ( F_65 ( V_145 , V_126 + V_129 ) ) {
V_31 = - V_146 ;
goto V_16;
}
V_129 ++ ;
for ( V_133 = 0 ; V_133 < V_145 ; V_133 ++ ) {
T_2 V_151 ;
T_1 V_120 ;
struct V_40 * V_119 ;
if ( F_65 ( V_151 , V_127 + V_130 ) ) {
V_31 = - V_146 ;
goto V_16;
}
V_119 = F_67 ( V_10 , V_151 ) ;
if ( ! V_119 ) {
V_31 = - V_149 ;
goto V_16;
}
if ( F_68 ( & V_120 ,
V_128 + V_130 ,
sizeof( V_120 ) ) ) {
V_31 = - V_146 ;
goto V_16;
}
V_31 = F_59 ( V_2 , V_91 , V_119 , V_120 ) ;
if ( V_31 )
goto V_16;
V_130 ++ ;
}
}
if ( V_124 -> V_110 & V_141 ) {
int V_100 = V_10 -> V_14 . V_15 ;
for ( V_20 = 0 ; V_20 < V_100 ; V_20 ++ ) {
struct V_30 * V_33 = V_2 -> V_6 [ V_20 ] ;
struct V_105 * V_109 ;
if ( ! V_33 )
continue;
V_109 = F_55 ( V_10 , V_107 , V_124 -> V_108 ) ;
if ( ! V_109 ) {
V_31 = - V_37 ;
goto V_16;
}
V_33 -> V_113 = V_109 ;
}
}
if ( V_124 -> V_110 & V_140 ) {
V_31 = F_52 ( V_2 ) ;
F_11 ( V_2 ) ;
} else if ( V_124 -> V_110 & V_152 ) {
V_31 = F_54 ( V_2 ) ;
} else {
V_31 = F_53 ( V_2 ) ;
}
F_69 (plane, dev, plane_mask) {
if ( V_31 == 0 ) {
struct V_52 * V_153 = V_29 -> V_2 -> V_53 ;
if ( V_153 )
F_45 ( V_153 ) ;
V_29 -> V_53 = V_153 ;
V_29 -> V_27 = V_29 -> V_2 -> V_27 ;
} else {
V_29 -> V_150 = NULL ;
}
if ( V_29 -> V_150 ) {
F_26 ( V_29 -> V_150 ) ;
V_29 -> V_150 = NULL ;
}
}
F_70 ( & V_132 ) ;
F_71 ( & V_132 ) ;
return V_31 ;
V_16:
if ( V_31 == - V_154 )
goto V_155;
if ( V_124 -> V_110 & V_141 ) {
int V_100 = V_10 -> V_14 . V_15 ;
for ( V_20 = 0 ; V_20 < V_100 ; V_20 ++ ) {
struct V_30 * V_33 = V_2 -> V_6 [ V_20 ] ;
if ( ! V_33 )
continue;
F_58 ( V_10 , V_107 , V_33 -> V_113 ) ;
V_33 -> V_113 = NULL ;
}
}
F_11 ( V_2 ) ;
F_70 ( & V_132 ) ;
F_71 ( & V_132 ) ;
return V_31 ;
V_155:
F_8 ( V_2 ) ;
F_50 ( & V_132 ) ;
goto V_98;
}
