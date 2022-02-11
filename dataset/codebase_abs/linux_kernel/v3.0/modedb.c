static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , unsigned int V_7 )
{
int V_8 = 0 ;
F_2 ( L_1 , V_6 -> V_9 ? V_6 -> V_9 : L_2 ,
V_6 -> V_10 , V_6 -> V_11 , V_7 , V_6 -> V_12 ) ;
V_2 -> V_10 = V_6 -> V_10 ;
V_2 -> V_11 = V_6 -> V_11 ;
V_2 -> V_13 = V_6 -> V_10 ;
V_2 -> V_14 = V_6 -> V_11 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = V_7 ;
V_2 -> V_18 |= V_19 ;
V_2 -> V_20 = V_6 -> V_20 ;
V_2 -> V_21 = V_6 -> V_21 ;
V_2 -> V_22 = V_6 -> V_22 ;
V_2 -> V_23 = V_6 -> V_23 ;
V_2 -> V_24 = V_6 -> V_24 ;
V_2 -> V_25 = V_6 -> V_25 ;
V_2 -> V_26 = V_6 -> V_26 ;
V_2 -> V_27 = V_6 -> V_27 ;
V_2 -> V_28 = V_6 -> V_28 ;
if ( V_4 -> V_29 -> V_30 )
V_8 = V_4 -> V_29 -> V_30 ( V_2 , V_4 ) ;
V_2 -> V_18 &= ~ V_19 ;
return V_8 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_31 ,
const struct V_5 * V_32 , unsigned int V_33 ,
const struct V_5 * V_34 ,
unsigned int V_35 )
{
int V_36 ;
if ( ! V_32 ) {
V_32 = V_37 ;
V_33 = F_4 ( V_37 ) ;
}
if ( ! V_34 )
V_34 = & V_32 [ 0 ] ;
if ( ! V_35 )
V_35 = 8 ;
if ( ! V_31 )
V_31 = V_38 ;
if ( V_31 ) {
const char * V_9 = V_31 ;
unsigned int V_39 = strlen ( V_9 ) ;
int V_40 = 0 , V_41 = 0 , V_42 = 0 ;
unsigned int V_10 = 0 , V_11 = 0 , V_7 = V_35 , V_12 = 0 ;
int V_43 = 0 , V_44 = 0 , V_45 = 0 , V_46 = 0 , V_47 = 0 ;
T_1 V_48 , V_49 , V_50 ;
for ( V_36 = V_39 - 1 ; V_36 >= 0 ; V_36 -- ) {
switch ( V_9 [ V_36 ] ) {
case '@' :
V_39 = V_36 ;
if ( ! V_42 && ! V_41 &&
! V_43 ) {
V_12 = F_5 ( & V_9 [ V_36 + 1 ] , NULL , 10 ) ;
V_42 = 1 ;
if ( V_44 || V_45 )
V_44 = 0 ;
} else
goto V_51;
break;
case '-' :
V_39 = V_36 ;
if ( ! V_41 && ! V_43 ) {
V_7 = F_5 ( & V_9 [ V_36 + 1 ] , NULL , 10 ) ;
V_41 = 1 ;
if ( V_44 || V_45 )
V_44 = 0 ;
} else
goto V_51;
break;
case 'x' :
if ( ! V_43 ) {
V_11 = F_5 ( & V_9 [ V_36 + 1 ] , NULL , 10 ) ;
V_43 = 1 ;
} else
goto V_51;
break;
case '0' ... '9' :
break;
case 'M' :
if ( ! V_43 )
V_44 = 1 ;
break;
case 'R' :
if ( ! V_44 )
V_45 = 1 ;
break;
case 'm' :
if ( ! V_44 )
V_47 = 1 ;
break;
case 'i' :
if ( ! V_44 )
V_46 = 1 ;
break;
default:
goto V_51;
}
}
if ( V_36 < 0 && V_43 ) {
V_10 = F_5 ( V_9 , NULL , 10 ) ;
V_40 = 1 ;
}
V_51:
if ( V_44 ) {
struct V_5 V_52 ;
int V_53 ;
F_2 ( L_3 , V_10 , V_11 ,
( V_12 ) ? V_12 : 60 , ( V_45 ) ? L_4 :
L_5 , ( V_47 ) ? L_6 : L_5 , ( V_46 ) ?
L_7 : L_5 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_10 = V_10 ;
V_52 . V_11 = V_11 ;
V_52 . V_12 = ( V_12 ) ? V_12 : 60 ;
if ( V_46 )
V_52 . V_28 |= V_54 ;
else
V_52 . V_28 &= ~ V_54 ;
V_53 = F_6 ( & V_52 , V_47 , V_45 ) ;
if ( ! V_53 && ! F_1 ( V_2 , V_4 , & V_52 , V_7 ) ) {
F_2 ( L_8 ) ;
return 1 ;
}
F_2 ( L_9 ) ;
}
F_2 ( L_10 ,
V_42 ? L_5 : L_11 , V_10 , V_11 ) ;
if ( ! V_42 ) {
if ( V_32 != V_37 &&
V_4 -> V_55 . V_56 && V_4 -> V_55 . V_57 &&
V_4 -> V_55 . V_58 && V_4 -> V_55 . V_59 &&
V_4 -> V_55 . V_60 ) {
V_12 = 1000 ;
} else {
V_12 = 60 ;
}
}
V_49 = - 1 ;
V_48 = - 1 ;
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ ) {
if ( ( F_7 ( V_32 [ V_36 ] , V_9 , V_39 ) ||
( V_40 && F_8 ( V_32 [ V_36 ] , V_10 , V_11 ) ) ) &&
! F_1 ( V_2 , V_4 , & V_32 [ V_36 ] , V_7 ) ) {
if ( V_42 && V_32 [ V_36 ] . V_12 == V_12 ) {
return 1 ;
} else {
if ( abs ( V_32 [ V_36 ] . V_12 - V_12 ) < V_49 ) {
V_49 = abs ( V_32 [ V_36 ] . V_12 - V_12 ) ;
V_48 = V_36 ;
}
}
}
}
if ( V_48 != - 1 ) {
F_1 ( V_2 , V_4 , & V_32 [ V_48 ] , V_7 ) ;
return ( V_42 ) ? 2 : 1 ;
}
V_49 = 2 * ( V_10 + V_11 ) ;
V_48 = - 1 ;
F_2 ( L_12 ) ;
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ ) {
F_2 ( L_13 , V_32 [ V_36 ] . V_10 , V_32 [ V_36 ] . V_11 ) ;
if ( ! F_1 ( V_2 , V_4 , & V_32 [ V_36 ] , V_7 ) ) {
V_50 = abs ( V_32 [ V_36 ] . V_10 - V_10 ) +
abs ( V_32 [ V_36 ] . V_11 - V_11 ) ;
if ( V_10 > V_32 [ V_36 ] . V_10 || V_11 > V_32 [ V_36 ] . V_11 )
V_50 += V_10 + V_11 ;
if ( V_49 > V_50 ) {
V_49 = V_50 ;
V_48 = V_36 ;
}
}
}
if ( V_48 != - 1 ) {
F_1 ( V_2 , V_4 , & V_32 [ V_48 ] , V_7 ) ;
return 5 ;
}
}
F_2 ( L_14 ) ;
if ( ! F_1 ( V_2 , V_4 , V_34 , V_35 ) )
return 3 ;
F_2 ( L_15 ) ;
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ )
if ( ! F_1 ( V_2 , V_4 , & V_32 [ V_36 ] , V_35 ) )
return 4 ;
F_2 ( L_16 ) ;
return 0 ;
}
void F_9 ( struct V_5 * V_6 ,
const struct V_1 * V_2 )
{
T_1 V_20 , V_61 , V_62 , V_63 ;
V_6 -> V_9 = NULL ;
V_6 -> V_10 = V_2 -> V_10 ;
V_6 -> V_11 = V_2 -> V_11 ;
V_6 -> V_20 = V_2 -> V_20 ;
V_6 -> V_25 = V_2 -> V_25 ;
V_6 -> V_26 = V_2 -> V_26 ;
V_6 -> V_21 = V_2 -> V_21 ;
V_6 -> V_22 = V_2 -> V_22 ;
V_6 -> V_23 = V_2 -> V_23 ;
V_6 -> V_24 = V_2 -> V_24 ;
V_6 -> V_27 = V_2 -> V_27 ;
V_6 -> V_28 = V_2 -> V_28 & V_64 ;
V_6 -> V_65 = V_66 ;
V_6 -> V_12 = 0 ;
if ( ! V_2 -> V_20 )
return;
V_20 = F_10 ( V_2 -> V_20 ) * 1000 ;
V_62 = V_2 -> V_10 + V_2 -> V_22 + V_2 -> V_25 +
V_2 -> V_21 ;
V_63 = V_2 -> V_11 + V_2 -> V_24 + V_2 -> V_26 +
V_2 -> V_23 ;
if ( V_2 -> V_28 & V_54 )
V_63 /= 2 ;
if ( V_2 -> V_28 & V_67 )
V_63 *= 2 ;
V_61 = V_20 / V_62 ;
V_6 -> V_12 = V_61 / V_63 ;
}
void F_11 ( struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
V_2 -> V_10 = V_6 -> V_10 ;
V_2 -> V_11 = V_6 -> V_11 ;
V_2 -> V_13 = V_6 -> V_10 ;
V_2 -> V_14 = V_6 -> V_11 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_20 = V_6 -> V_20 ;
V_2 -> V_21 = V_6 -> V_21 ;
V_2 -> V_22 = V_6 -> V_22 ;
V_2 -> V_23 = V_6 -> V_23 ;
V_2 -> V_24 = V_6 -> V_24 ;
V_2 -> V_25 = V_6 -> V_25 ;
V_2 -> V_26 = V_6 -> V_26 ;
V_2 -> V_27 = V_6 -> V_27 ;
V_2 -> V_28 = V_6 -> V_28 & V_64 ;
}
int F_12 ( const struct V_5 * V_68 ,
const struct V_5 * V_69 )
{
return ( V_68 -> V_10 == V_69 -> V_10 &&
V_68 -> V_11 == V_69 -> V_11 &&
V_68 -> V_20 == V_69 -> V_20 &&
V_68 -> V_25 == V_69 -> V_25 &&
V_68 -> V_26 == V_69 -> V_26 &&
V_68 -> V_21 == V_69 -> V_21 &&
V_68 -> V_22 == V_69 -> V_22 &&
V_68 -> V_23 == V_69 -> V_23 &&
V_68 -> V_24 == V_69 -> V_24 &&
V_68 -> V_27 == V_69 -> V_27 &&
V_68 -> V_28 == V_69 -> V_28 ) ;
}
const struct V_5 * F_13 ( const struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_70 * V_72 ;
struct V_73 * V_74 ;
struct V_5 * V_6 , * V_48 = NULL ;
T_1 V_49 = - 1 ;
F_14 (pos, head) {
T_1 V_75 ;
V_74 = F_15 ( V_72 , struct V_73 , V_76 ) ;
V_6 = & V_74 -> V_6 ;
if ( V_6 -> V_10 >= V_2 -> V_10 && V_6 -> V_11 >= V_2 -> V_11 ) {
V_75 = ( V_6 -> V_10 - V_2 -> V_10 ) +
( V_6 -> V_11 - V_2 -> V_11 ) ;
if ( V_49 > V_75 ) {
V_49 = V_75 ;
V_48 = V_6 ;
} else if ( V_49 == V_75 && V_48 &&
V_6 -> V_12 > V_48 -> V_12 )
V_48 = V_6 ;
}
}
return V_48 ;
}
const struct V_5 * F_16 ( const struct V_5 * V_6 ,
struct V_70 * V_71 )
{
struct V_70 * V_72 ;
struct V_73 * V_74 ;
struct V_5 * V_77 , * V_48 = NULL ;
T_1 V_49 = - 1 , V_78 = - 1 ;
F_14 (pos, head) {
T_1 V_75 ;
V_74 = F_15 ( V_72 , struct V_73 , V_76 ) ;
V_77 = & V_74 -> V_6 ;
V_75 = abs ( V_77 -> V_10 - V_6 -> V_10 ) +
abs ( V_77 -> V_11 - V_6 -> V_11 ) ;
if ( V_49 > V_75 ) {
V_49 = V_75 ;
V_78 = abs ( V_77 -> V_12 - V_6 -> V_12 ) ;
V_48 = V_77 ;
} else if ( V_49 == V_75 ) {
V_75 = abs ( V_77 -> V_12 - V_6 -> V_12 ) ;
if ( V_78 > V_75 ) {
V_78 = V_75 ;
V_48 = V_77 ;
}
}
}
return V_48 ;
}
const struct V_5 * F_17 ( const struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_70 * V_72 ;
struct V_73 * V_74 ;
struct V_5 * V_79 , V_6 ;
F_9 ( & V_6 , V_2 ) ;
F_14 (pos, head) {
V_74 = F_15 ( V_72 , struct V_73 , V_76 ) ;
V_79 = & V_74 -> V_6 ;
if ( F_12 ( V_79 , & V_6 ) )
return V_79 ;
}
return NULL ;
}
int F_18 ( const struct V_5 * V_6 , struct V_70 * V_71 )
{
struct V_70 * V_72 ;
struct V_73 * V_74 ;
struct V_5 * V_79 ;
int V_80 = 0 ;
F_14 (pos, head) {
V_74 = F_15 ( V_72 , struct V_73 , V_76 ) ;
V_79 = & V_74 -> V_6 ;
if ( F_12 ( V_79 , V_6 ) ) {
V_80 = 1 ;
break;
}
}
if ( ! V_80 ) {
V_74 = F_19 ( sizeof( struct V_73 ) ,
V_81 ) ;
if ( ! V_74 )
return - V_82 ;
V_74 -> V_6 = * V_6 ;
F_20 ( & V_74 -> V_76 , V_71 ) ;
}
return 0 ;
}
void F_21 ( const struct V_5 * V_6 ,
struct V_70 * V_71 )
{
struct V_70 * V_72 , * V_83 ;
struct V_73 * V_74 ;
struct V_5 * V_79 ;
F_22 (pos, n, head) {
V_74 = F_15 ( V_72 , struct V_73 , V_76 ) ;
V_79 = & V_74 -> V_6 ;
if ( F_12 ( V_79 , V_6 ) ) {
F_23 ( V_72 ) ;
F_24 ( V_72 ) ;
}
}
}
void F_25 ( struct V_70 * V_71 )
{
struct V_70 * V_72 , * V_83 ;
F_22 (pos, n, head) {
F_23 ( V_72 ) ;
F_24 ( V_72 ) ;
}
}
void F_26 ( const struct V_5 * V_37 , int V_84 ,
struct V_70 * V_71 )
{
int V_36 ;
F_27 ( V_71 ) ;
for ( V_36 = 0 ; V_36 < V_84 ; V_36 ++ ) {
if ( F_18 ( & V_37 [ V_36 ] , V_71 ) )
return;
}
}
const struct V_5 * F_28 ( const struct V_85 * V_86 ,
struct V_70 * V_71 )
{
struct V_70 * V_72 ;
struct V_73 * V_74 ;
const struct V_5 * V_79 , * V_87 = NULL , * V_88 = NULL , * V_48 = NULL ;
int V_89 = 0 ;
if ( ! V_71 -> V_90 || ! V_71 -> V_91 || F_29 ( V_71 ) )
goto V_92;
F_14 (pos, head) {
V_74 = F_15 ( V_72 , struct V_73 , V_76 ) ;
V_79 = & V_74 -> V_6 ;
if ( ! V_89 ) {
V_87 = V_79 ;
V_89 = 1 ;
}
if ( V_79 -> V_65 & V_93 ) {
V_88 = V_79 ;
break;
}
}
if ( V_86 -> V_94 & V_95 ) {
V_48 = V_88 ;
goto V_92;
}
if ( V_86 -> V_96 && V_86 -> V_97 ) {
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 . V_10 = ( V_86 -> V_96 * 7200 ) / 254 ;
V_2 . V_11 = ( V_86 -> V_97 * 7200 ) / 254 ;
V_79 = F_13 ( & V_2 , V_71 ) ;
if ( V_79 ) {
V_48 = V_79 ;
goto V_92;
}
}
if ( V_88 ) {
V_48 = V_88 ;
goto V_92;
}
V_48 = V_87 ;
V_92:
return V_48 ;
}
