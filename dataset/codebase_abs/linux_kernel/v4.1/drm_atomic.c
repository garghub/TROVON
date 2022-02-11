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
V_2 -> V_3 [ V_20 ] = NULL ;
V_2 -> V_4 [ V_20 ] = NULL ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_15 ; V_20 ++ ) {
struct V_26 * V_27 = V_2 -> V_5 [ V_20 ] ;
if ( ! V_27 )
continue;
V_27 -> V_24 -> V_25 ( V_27 ,
V_2 -> V_6 [ V_20 ] ) ;
V_2 -> V_5 [ V_20 ] = NULL ;
V_2 -> V_6 [ V_20 ] = NULL ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_17 ; V_20 ++ ) {
struct V_28 * V_29 = V_2 -> V_7 [ V_20 ] ;
if ( ! V_29 )
continue;
V_29 -> V_24 -> V_25 ( V_29 ,
V_2 -> V_8 [ V_20 ] ) ;
V_2 -> V_7 [ V_20 ] = NULL ;
V_2 -> V_8 [ V_20 ] = NULL ;
}
}
void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
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
if ( V_41 == V_19 -> V_43 )
V_2 -> V_44 = V_42 ;
else if ( V_27 -> V_24 -> V_45 )
return V_27 -> V_24 -> V_45 ( V_27 , V_2 , V_41 , V_42 ) ;
else
return - V_46 ;
return 0 ;
}
int F_17 ( struct V_26 * V_27 ,
const struct V_30 * V_2 ,
struct V_40 * V_41 , T_1 * V_42 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
if ( V_41 == V_19 -> V_43 )
* V_42 = V_2 -> V_44 ;
else if ( V_27 -> V_24 -> V_47 )
return V_27 -> V_24 -> V_47 ( V_27 , V_2 , V_41 , V_42 ) ;
else
return - V_46 ;
return 0 ;
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
} else if ( V_41 == V_19 -> V_71 ) {
* V_42 = V_2 -> V_72 ;
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
int V_31 ;
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
V_31 = F_34 ( V_29 , V_2 -> V_53 -> V_76 ) ;
if ( V_31 ) {
F_7 ( L_10 ,
F_35 ( V_2 -> V_53 -> V_76 ) ) ;
return V_31 ;
}
if ( V_2 -> V_60 > V_77 ||
V_2 -> V_56 > V_77 - ( V_78 ) V_2 -> V_60 ||
V_2 -> V_62 > V_77 ||
V_2 -> V_58 > V_77 - ( V_78 ) V_2 -> V_62 ) {
F_7 ( L_11 ,
V_2 -> V_60 , V_2 -> V_62 ,
V_2 -> V_56 , V_2 -> V_58 ) ;
return - V_79 ;
}
V_73 = V_2 -> V_53 -> V_80 << 16 ;
V_74 = V_2 -> V_53 -> V_81 << 16 ;
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
return - V_82 ;
}
return 0 ;
}
struct V_83 *
F_36 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_31 , V_32 ;
struct V_18 * V_19 = & V_22 -> V_10 -> V_14 ;
struct V_83 * V_84 ;
V_31 = F_14 ( & V_19 -> V_23 , V_2 -> V_35 ) ;
if ( V_31 )
return F_15 ( V_31 ) ;
V_32 = F_37 ( V_22 ) ;
if ( V_32 >= V_2 -> V_13 ) {
F_7 ( L_14 ) ;
return F_15 ( - V_85 ) ;
}
if ( V_2 -> V_4 [ V_32 ] )
return V_2 -> V_4 [ V_32 ] ;
V_84 = V_22 -> V_24 -> V_36 ( V_22 ) ;
if ( ! V_84 )
return F_15 ( - V_37 ) ;
V_2 -> V_4 [ V_32 ] = V_84 ;
V_2 -> V_3 [ V_32 ] = V_22 ;
V_84 -> V_2 = V_2 ;
F_7 ( L_15 ,
V_22 -> V_38 . V_39 , V_84 , V_2 ) ;
if ( V_84 -> V_27 ) {
struct V_30 * V_33 ;
V_33 = F_12 ( V_2 ,
V_84 -> V_27 ) ;
if ( F_21 ( V_33 ) )
return F_22 ( V_33 ) ;
}
return V_84 ;
}
int F_38 ( struct V_21 * V_22 ,
struct V_83 * V_2 , struct V_40 * V_41 ,
T_1 V_42 )
{
struct V_9 * V_10 = V_22 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
if ( V_41 == V_19 -> V_54 ) {
struct V_26 * V_27 = F_27 ( V_10 , V_42 ) ;
return F_39 ( V_2 , V_27 ) ;
} else if ( V_41 == V_19 -> V_86 ) {
return - V_46 ;
} else if ( V_22 -> V_24 -> V_45 ) {
return V_22 -> V_24 -> V_45 ( V_22 ,
V_2 , V_41 , V_42 ) ;
} else {
return - V_46 ;
}
}
static int
F_40 ( struct V_21 * V_22 ,
const struct V_83 * V_2 ,
struct V_40 * V_41 , T_1 * V_42 )
{
struct V_9 * V_10 = V_22 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
if ( V_41 == V_19 -> V_54 ) {
* V_42 = ( V_2 -> V_27 ) ? V_2 -> V_27 -> V_38 . V_39 : 0 ;
} else if ( V_41 == V_19 -> V_86 ) {
* V_42 = V_22 -> V_87 ;
} else if ( V_22 -> V_24 -> V_47 ) {
return V_22 -> V_24 -> V_47 ( V_22 ,
V_2 , V_41 , V_42 ) ;
} else {
return - V_46 ;
}
return 0 ;
}
int F_41 ( struct V_88 * V_89 ,
struct V_40 * V_41 , T_1 * V_42 )
{
struct V_9 * V_10 = V_41 -> V_10 ;
int V_31 ;
switch ( V_89 -> type ) {
case V_90 : {
struct V_21 * V_22 = F_42 ( V_89 ) ;
F_9 ( ! F_10 ( & V_10 -> V_14 . V_23 ) ) ;
V_31 = F_40 ( V_22 ,
V_22 -> V_2 , V_41 , V_42 ) ;
break;
}
case V_91 : {
struct V_26 * V_27 = F_43 ( V_89 ) ;
F_9 ( ! F_10 ( & V_27 -> V_34 ) ) ;
V_31 = F_17 ( V_27 ,
V_27 -> V_2 , V_41 , V_42 ) ;
break;
}
case V_92 : {
struct V_28 * V_29 = F_44 ( V_89 ) ;
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
return F_45 ( V_33 ) ;
V_33 -> V_93 &= ~ ( 1 << F_20 ( V_29 ) ) ;
}
V_50 -> V_27 = V_27 ;
if ( V_27 ) {
V_33 = F_12 ( V_50 -> V_2 ,
V_27 ) ;
if ( F_21 ( V_33 ) )
return F_45 ( V_33 ) ;
V_33 -> V_93 |= ( 1 << F_20 ( V_29 ) ) ;
}
if ( V_27 )
F_7 ( L_16 ,
V_50 , V_27 -> V_38 . V_39 ) ;
else
F_7 ( L_17 ,
V_50 ) ;
return 0 ;
}
void
F_25 ( struct V_49 * V_50 ,
struct V_52 * V_53 )
{
if ( V_50 -> V_53 )
F_26 ( V_50 -> V_53 ) ;
if ( V_53 )
F_46 ( V_53 ) ;
V_50 -> V_53 = V_53 ;
if ( V_53 )
F_7 ( L_18 ,
V_53 -> V_38 . V_39 , V_50 ) ;
else
F_7 ( L_19 ,
V_50 ) ;
}
int
F_39 ( struct V_83 * V_94 ,
struct V_26 * V_27 )
{
struct V_30 * V_33 ;
if ( V_27 ) {
V_33 = F_12 ( V_94 -> V_2 , V_27 ) ;
if ( F_21 ( V_33 ) )
return F_45 ( V_33 ) ;
}
V_94 -> V_27 = V_27 ;
if ( V_27 )
F_7 ( L_20 ,
V_94 , V_27 -> V_38 . V_39 ) ;
else
F_7 ( L_21 ,
V_94 ) ;
return 0 ;
}
int
F_47 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_14 ;
struct V_21 * V_22 ;
struct V_83 * V_94 ;
int V_31 ;
V_31 = F_14 ( & V_19 -> V_23 , V_2 -> V_35 ) ;
if ( V_31 )
return V_31 ;
F_7 ( L_22 ,
V_27 -> V_38 . V_39 , V_2 ) ;
F_48 (connector, &config->connector_list, head) {
if ( V_22 -> V_2 -> V_27 != V_27 )
continue;
V_94 = F_36 ( V_2 , V_22 ) ;
if ( F_21 ( V_94 ) )
return F_45 ( V_94 ) ;
}
return 0 ;
}
int
F_49 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_21 * V_22 ;
struct V_83 * V_94 ;
int V_20 , V_95 = 0 ;
F_50 (state, connector, conn_state, i) {
if ( V_94 -> V_27 == V_27 )
V_95 ++ ;
}
F_7 ( L_23 ,
V_2 , V_95 , V_27 -> V_38 . V_39 ) ;
return V_95 ;
}
void F_51 ( struct V_1 * V_2 )
{
int V_31 ;
V_96:
F_52 ( V_2 -> V_35 ) ;
V_31 = F_14 ( & V_2 -> V_10 -> V_14 . V_23 ,
V_2 -> V_35 ) ;
if ( V_31 )
goto V_96;
V_31 = F_53 ( V_2 -> V_10 ,
V_2 -> V_35 ) ;
if ( V_31 )
goto V_96;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_14 ;
struct V_28 * V_29 ;
struct V_49 * V_50 ;
struct V_26 * V_27 ;
struct V_30 * V_33 ;
int V_20 , V_31 = 0 ;
F_7 ( L_24 , V_2 ) ;
F_55 (state, plane, plane_state, i) {
V_31 = F_32 ( V_29 , V_50 ) ;
if ( V_31 ) {
F_7 ( L_25 ,
V_29 -> V_38 . V_39 ) ;
return V_31 ;
}
}
F_56 (state, crtc, crtc_state, i) {
V_31 = F_18 ( V_27 , V_33 ) ;
if ( V_31 ) {
F_7 ( L_26 ,
V_27 -> V_38 . V_39 ) ;
return V_31 ;
}
}
if ( V_19 -> V_24 -> V_97 )
V_31 = V_19 -> V_24 -> V_97 ( V_2 -> V_10 , V_2 ) ;
if ( ! V_2 -> V_12 ) {
F_56 (state, crtc, crtc_state, i) {
if ( V_33 -> V_98 ||
V_33 -> V_99 ) {
F_7 ( L_27 ,
V_27 -> V_38 . V_39 ) ;
return - V_46 ;
}
}
}
return V_31 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_14 ;
int V_31 ;
V_31 = F_54 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_7 ( L_28 , V_2 ) ;
return V_19 -> V_24 -> V_100 ( V_2 -> V_10 , V_2 , false ) ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_14 ;
int V_31 ;
V_31 = F_54 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_7 ( L_29 , V_2 ) ;
return V_19 -> V_24 -> V_100 ( V_2 -> V_10 , V_2 , true ) ;
}
static struct V_101 * F_59 (
struct V_9 * V_10 , struct V_102 * V_103 , T_1 V_104 )
{
struct V_101 * V_105 = NULL ;
unsigned long V_106 ;
F_60 ( & V_10 -> V_107 , V_106 ) ;
if ( V_103 -> V_108 < sizeof V_105 -> V_109 ) {
F_61 ( & V_10 -> V_107 , V_106 ) ;
goto V_110;
}
V_103 -> V_108 -= sizeof V_105 -> V_109 ;
F_61 ( & V_10 -> V_107 , V_106 ) ;
V_105 = F_4 ( sizeof *V_105 , V_11 ) ;
if ( V_105 == NULL ) {
F_60 ( & V_10 -> V_107 , V_106 ) ;
V_103 -> V_108 += sizeof V_105 -> V_109 ;
F_61 ( & V_10 -> V_107 , V_106 ) ;
goto V_110;
}
V_105 -> V_109 . V_38 . type = V_111 ;
V_105 -> V_109 . V_38 . V_112 = sizeof V_105 -> V_109 ;
V_105 -> V_109 . V_104 = V_104 ;
V_105 -> V_38 . V_109 = & V_105 -> V_109 . V_38 ;
V_105 -> V_38 . V_103 = V_103 ;
V_105 -> V_38 . V_113 = ( void ( * ) ( struct V_114 * ) ) F_2 ;
V_110:
return V_105 ;
}
static void F_62 ( struct V_9 * V_10 ,
struct V_102 * V_103 , struct V_101 * V_105 )
{
unsigned long V_106 ;
F_60 ( & V_10 -> V_107 , V_106 ) ;
V_103 -> V_108 += sizeof V_105 -> V_109 ;
F_61 ( & V_10 -> V_107 , V_106 ) ;
F_2 ( V_105 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_88 * V_89 , struct V_40 * V_115 ,
T_1 V_116 )
{
struct V_88 * V_117 ;
int V_31 ;
if ( ! F_64 ( V_115 , V_116 , & V_117 ) )
return - V_46 ;
switch ( V_89 -> type ) {
case V_90 : {
struct V_21 * V_22 = F_42 ( V_89 ) ;
struct V_83 * V_84 ;
V_84 = F_36 ( V_2 , V_22 ) ;
if ( F_21 ( V_84 ) ) {
V_31 = F_45 ( V_84 ) ;
break;
}
V_31 = F_38 ( V_22 ,
V_84 , V_115 , V_116 ) ;
break;
}
case V_91 : {
struct V_26 * V_27 = F_43 ( V_89 ) ;
struct V_30 * V_33 ;
V_33 = F_12 ( V_2 , V_27 ) ;
if ( F_21 ( V_33 ) ) {
V_31 = F_45 ( V_33 ) ;
break;
}
V_31 = F_16 ( V_27 ,
V_33 , V_115 , V_116 ) ;
break;
}
case V_92 : {
struct V_28 * V_29 = F_44 ( V_89 ) ;
struct V_49 * V_50 ;
V_50 = F_19 ( V_2 , V_29 ) ;
if ( F_21 ( V_50 ) ) {
V_31 = F_45 ( V_50 ) ;
break;
}
V_31 = F_23 ( V_29 ,
V_50 , V_115 , V_116 ) ;
break;
}
default:
V_31 = - V_46 ;
break;
}
F_65 ( V_115 , V_117 ) ;
return V_31 ;
}
int F_66 ( struct V_9 * V_10 ,
void * V_118 , struct V_102 * V_103 )
{
struct V_119 * V_120 = V_118 ;
T_2 T_3 * V_121 = ( T_2 T_3 * ) ( unsigned long ) ( V_120 -> V_121 ) ;
T_2 T_3 * V_122 = ( T_2 T_3 * ) ( unsigned long ) ( V_120 -> V_122 ) ;
T_2 T_3 * V_123 = ( T_2 T_3 * ) ( unsigned long ) ( V_120 -> V_123 ) ;
T_1 T_3 * V_124 = ( T_1 T_3 * ) ( unsigned long ) ( V_120 -> V_124 ) ;
unsigned int V_125 , V_126 ;
struct V_1 * V_2 ;
struct V_127 V_128 ;
struct V_28 * V_29 ;
struct V_26 * V_27 ;
struct V_30 * V_33 ;
unsigned V_93 = 0 ;
int V_31 = 0 ;
unsigned int V_20 , V_129 ;
if ( ! F_67 ( V_10 , V_130 ) )
return - V_46 ;
if ( ! V_103 -> V_131 )
return - V_46 ;
if ( V_120 -> V_106 & ~ V_132 )
return - V_46 ;
if ( V_120 -> V_133 )
return - V_46 ;
if ( ( V_120 -> V_106 & V_134 ) &&
! V_10 -> V_14 . V_135 )
return - V_46 ;
if ( ( V_120 -> V_106 & V_136 ) &&
( V_120 -> V_106 & V_137 ) )
return - V_46 ;
F_68 ( & V_128 , 0 ) ;
V_2 = F_3 ( V_10 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_35 = & V_128 ;
V_2 -> V_12 = ! ! ( V_120 -> V_106 & V_138 ) ;
V_96:
V_125 = 0 ;
V_126 = 0 ;
for ( V_20 = 0 ; V_20 < V_120 -> V_139 ; V_20 ++ ) {
T_2 V_140 , V_141 ;
struct V_88 * V_89 ;
if ( F_69 ( V_140 , V_121 + V_125 ) ) {
V_31 = - V_142 ;
goto V_16;
}
V_89 = F_70 ( V_10 , V_140 , V_143 ) ;
if ( ! V_89 || ! V_89 -> V_144 ) {
V_31 = - V_145 ;
goto V_16;
}
if ( V_89 -> type == V_92 ) {
V_29 = F_44 ( V_89 ) ;
V_93 |= ( 1 << F_20 ( V_29 ) ) ;
V_29 -> V_146 = V_29 -> V_53 ;
}
if ( F_69 ( V_141 , V_122 + V_125 ) ) {
V_31 = - V_142 ;
goto V_16;
}
V_125 ++ ;
for ( V_129 = 0 ; V_129 < V_141 ; V_129 ++ ) {
T_2 V_147 ;
T_1 V_116 ;
struct V_40 * V_115 ;
if ( F_69 ( V_147 , V_123 + V_126 ) ) {
V_31 = - V_142 ;
goto V_16;
}
V_115 = F_71 ( V_10 , V_147 ) ;
if ( ! V_115 ) {
V_31 = - V_145 ;
goto V_16;
}
if ( F_72 ( & V_116 ,
V_124 + V_126 ,
sizeof( V_116 ) ) ) {
V_31 = - V_142 ;
goto V_16;
}
V_31 = F_63 ( V_2 , V_89 , V_115 , V_116 ) ;
if ( V_31 )
goto V_16;
V_126 ++ ;
}
}
if ( V_120 -> V_106 & V_137 ) {
F_56 (state, crtc, crtc_state, i) {
struct V_101 * V_105 ;
V_105 = F_59 ( V_10 , V_103 , V_120 -> V_104 ) ;
if ( ! V_105 ) {
V_31 = - V_37 ;
goto V_16;
}
V_33 -> V_109 = V_105 ;
}
}
if ( V_120 -> V_106 & V_136 ) {
V_31 = F_54 ( V_2 ) ;
F_11 ( V_2 ) ;
} else if ( V_120 -> V_106 & V_148 ) {
V_31 = F_58 ( V_2 ) ;
} else {
V_31 = F_57 ( V_2 ) ;
}
F_73 (plane, dev, plane_mask) {
if ( V_31 == 0 ) {
struct V_52 * V_149 = V_29 -> V_2 -> V_53 ;
if ( V_149 )
F_46 ( V_149 ) ;
V_29 -> V_53 = V_149 ;
V_29 -> V_27 = V_29 -> V_2 -> V_27 ;
} else {
V_29 -> V_146 = NULL ;
}
if ( V_29 -> V_146 ) {
F_26 ( V_29 -> V_146 ) ;
V_29 -> V_146 = NULL ;
}
}
F_74 ( & V_128 ) ;
F_75 ( & V_128 ) ;
return V_31 ;
V_16:
if ( V_31 == - V_150 )
goto V_151;
if ( V_120 -> V_106 & V_137 ) {
F_56 (state, crtc, crtc_state, i) {
F_62 ( V_10 , V_103 , V_33 -> V_109 ) ;
V_33 -> V_109 = NULL ;
}
}
F_11 ( V_2 ) ;
F_74 ( & V_128 ) ;
F_75 ( & V_128 ) ;
return V_31 ;
V_151:
F_8 ( V_2 ) ;
F_52 ( & V_128 ) ;
goto V_96;
}
