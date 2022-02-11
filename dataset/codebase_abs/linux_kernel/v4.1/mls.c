int F_1 ( struct V_1 * V_1 )
{
int V_2 , V_3 , V_4 , V_5 , V_6 ;
char * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( ! V_12 . V_13 )
return 0 ;
V_4 = 1 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
int V_14 = V_1 -> V_15 . V_16 [ V_3 ] . V_17 ;
V_4 += strlen ( F_2 ( & V_12 , V_18 , V_14 - 1 ) ) ;
V_5 = - 2 ;
V_6 = - 2 ;
V_9 = & V_1 -> V_15 . V_16 [ V_3 ] . V_19 ;
F_3 (e, node, i) {
if ( V_2 - V_6 > 1 ) {
if ( V_5 != V_6 ) {
V_7 = F_2 ( & V_12 , V_20 , V_6 ) ;
V_4 += strlen ( V_7 ) + 1 ;
}
V_7 = F_2 ( & V_12 , V_20 , V_2 ) ;
V_4 += strlen ( V_7 ) + 1 ;
V_5 = V_2 ;
}
V_6 = V_2 ;
}
if ( V_6 != V_5 ) {
V_7 = F_2 ( & V_12 , V_20 , V_6 ) ;
V_4 += strlen ( V_7 ) + 1 ;
}
if ( V_3 == 0 ) {
if ( F_4 ( & V_1 -> V_15 . V_16 [ 0 ] ,
& V_1 -> V_15 . V_16 [ 1 ] ) )
break;
else
V_4 ++ ;
}
}
return V_4 ;
}
void F_5 ( struct V_1 * V_1 ,
char * * V_21 )
{
char * V_22 , * V_7 ;
int V_2 , V_3 , V_5 , V_6 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( ! V_12 . V_13 )
return;
V_22 = * V_21 ;
* V_22 = ':' ;
V_22 ++ ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
strcpy ( V_22 , F_2 ( & V_12 , V_18 ,
V_1 -> V_15 . V_16 [ V_3 ] . V_17 - 1 ) ) ;
V_22 += strlen ( V_22 ) ;
V_5 = - 2 ;
V_6 = - 2 ;
V_9 = & V_1 -> V_15 . V_16 [ V_3 ] . V_19 ;
F_3 (e, node, i) {
if ( V_2 - V_6 > 1 ) {
if ( V_6 != V_5 ) {
if ( V_6 - V_5 > 1 )
* V_22 ++ = '.' ;
else
* V_22 ++ = ',' ;
V_7 = F_2 ( & V_12 , V_20 , V_6 ) ;
strcpy ( V_22 , V_7 ) ;
V_22 += strlen ( V_7 ) ;
}
if ( V_6 < 0 )
* V_22 ++ = ':' ;
else
* V_22 ++ = ',' ;
V_7 = F_2 ( & V_12 , V_20 , V_2 ) ;
strcpy ( V_22 , V_7 ) ;
V_22 += strlen ( V_7 ) ;
V_5 = V_2 ;
}
V_6 = V_2 ;
}
if ( V_6 != V_5 ) {
if ( V_6 - V_5 > 1 )
* V_22 ++ = '.' ;
else
* V_22 ++ = ',' ;
V_7 = F_2 ( & V_12 , V_20 , V_6 ) ;
strcpy ( V_22 , V_7 ) ;
V_22 += strlen ( V_7 ) ;
}
if ( V_3 == 0 ) {
if ( F_4 ( & V_1 -> V_15 . V_16 [ 0 ] ,
& V_1 -> V_15 . V_16 [ 1 ] ) )
break;
else
* V_22 ++ = '-' ;
}
}
* V_21 = V_22 ;
return;
}
int F_6 ( struct V_12 * V_23 , struct V_24 * V_3 )
{
struct V_25 * V_26 ;
if ( ! V_3 -> V_17 || V_3 -> V_17 > V_23 -> V_27 . V_28 )
return 0 ;
V_26 = F_7 ( V_23 -> V_27 . V_29 ,
F_2 ( V_23 , V_18 , V_3 -> V_17 - 1 ) ) ;
if ( ! V_26 )
return 0 ;
return F_8 ( & V_26 -> V_16 -> V_19 , & V_3 -> V_19 ,
V_23 -> V_30 . V_28 ) ;
}
int F_9 ( struct V_12 * V_23 , struct V_31 * V_32 )
{
return ( F_6 ( V_23 , & V_32 -> V_16 [ 0 ] ) &&
F_6 ( V_23 , & V_32 -> V_16 [ 1 ] ) &&
F_10 ( & V_32 -> V_16 [ 1 ] , & V_32 -> V_16 [ 0 ] ) ) ;
}
int F_11 ( struct V_12 * V_23 , struct V_1 * V_33 )
{
struct V_34 * V_35 ;
if ( ! V_23 -> V_13 )
return 1 ;
if ( ! F_9 ( V_23 , & V_33 -> V_15 ) )
return 0 ;
if ( V_33 -> V_36 == V_37 )
return 1 ;
if ( ! V_33 -> V_38 || V_33 -> V_38 > V_23 -> V_39 . V_28 )
return 0 ;
V_35 = V_23 -> V_40 [ V_33 -> V_38 - 1 ] ;
if ( ! F_12 ( V_35 -> V_15 , V_33 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_13 ( struct V_12 * V_41 ,
char V_42 ,
char * * V_21 ,
struct V_1 * V_1 ,
struct V_43 * V_44 ,
T_1 V_45 )
{
char V_46 ;
char * V_22 , * V_23 , * V_47 ;
struct V_25 * V_26 ;
struct V_48 * V_49 , * V_50 ;
int V_3 , V_51 = - V_52 ;
if ( ! V_41 -> V_13 ) {
if ( V_45 != V_53 && V_42 )
* V_21 += strlen ( * V_21 ) + 1 ;
return 0 ;
}
if ( ! V_42 ) {
struct V_1 * V_54 ;
if ( V_45 == V_53 )
goto V_55;
V_54 = F_14 ( V_44 , V_45 ) ;
if ( ! V_54 )
goto V_55;
V_51 = F_15 ( V_1 , V_54 ) ;
goto V_55;
}
V_22 = V_23 = * V_21 ;
while ( * V_23 && * V_23 != ':' && * V_23 != '-' )
V_23 ++ ;
V_46 = * V_23 ;
if ( V_46 != '\0' )
* V_23 ++ = '\0' ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_26 = F_7 ( V_41 -> V_27 . V_29 , V_22 ) ;
if ( ! V_26 ) {
V_51 = - V_52 ;
goto V_55;
}
V_1 -> V_15 . V_16 [ V_3 ] . V_17 = V_26 -> V_16 -> V_17 ;
if ( V_46 == ':' ) {
while ( 1 ) {
V_22 = V_23 ;
while ( * V_23 && * V_23 != ',' && * V_23 != '-' )
V_23 ++ ;
V_46 = * V_23 ;
if ( V_46 != '\0' )
* V_23 ++ = '\0' ;
V_47 = strchr ( V_22 , '.' ) ;
if ( V_47 != NULL ) {
* V_47 ++ = '\0' ;
}
V_49 = F_7 ( V_41 -> V_30 . V_29 ,
V_22 ) ;
if ( ! V_49 ) {
V_51 = - V_52 ;
goto V_55;
}
V_51 = F_16 ( & V_1 -> V_15 . V_16 [ V_3 ] . V_19 ,
V_49 -> V_56 - 1 , 1 ) ;
if ( V_51 )
goto V_55;
if ( V_47 ) {
int V_2 ;
V_50 = F_7 ( V_41 -> V_30 . V_29 , V_47 ) ;
if ( ! V_50 ) {
V_51 = - V_52 ;
goto V_55;
}
if ( V_49 -> V_56 >= V_50 -> V_56 ) {
V_51 = - V_52 ;
goto V_55;
}
for ( V_2 = V_49 -> V_56 ; V_2 < V_50 -> V_56 ; V_2 ++ ) {
V_51 = F_16 ( & V_1 -> V_15 . V_16 [ V_3 ] . V_19 , V_2 , 1 ) ;
if ( V_51 )
goto V_55;
}
}
if ( V_46 != ',' )
break;
}
}
if ( V_46 == '-' ) {
V_22 = V_23 ;
while ( * V_23 && * V_23 != ':' )
V_23 ++ ;
V_46 = * V_23 ;
if ( V_46 != '\0' )
* V_23 ++ = '\0' ;
} else
break;
}
if ( V_3 == 0 ) {
V_1 -> V_15 . V_16 [ 1 ] . V_17 = V_1 -> V_15 . V_16 [ 0 ] . V_17 ;
V_51 = F_17 ( & V_1 -> V_15 . V_16 [ 1 ] . V_19 ,
& V_1 -> V_15 . V_16 [ 0 ] . V_19 ) ;
if ( V_51 )
goto V_55;
}
* V_21 = ++ V_23 ;
V_51 = 0 ;
V_55:
return V_51 ;
}
int F_18 ( char * V_57 , struct V_1 * V_1 , T_2 V_58 )
{
char * V_59 , * V_60 ;
int V_51 ;
if ( ! V_12 . V_13 )
return - V_52 ;
V_59 = V_60 = F_19 ( V_57 , V_58 ) ;
if ( ! V_59 ) {
V_51 = - V_61 ;
} else {
V_51 = F_13 ( & V_12 , ':' , & V_59 , V_1 ,
NULL , V_53 ) ;
F_20 ( V_60 ) ;
}
return V_51 ;
}
int F_21 ( struct V_1 * V_1 ,
struct V_31 * V_15 )
{
int V_3 , V_51 = 0 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_1 -> V_15 . V_16 [ V_3 ] . V_17 = V_15 -> V_16 [ V_3 ] . V_17 ;
V_51 = F_17 ( & V_1 -> V_15 . V_16 [ V_3 ] . V_19 ,
& V_15 -> V_16 [ V_3 ] . V_19 ) ;
if ( V_51 )
break;
}
return V_51 ;
}
int F_22 ( struct V_1 * V_62 , struct V_34 * V_38 ,
struct V_1 * V_63 )
{
if ( V_12 . V_13 ) {
struct V_24 * V_64 = & ( V_62 -> V_15 . V_16 [ 0 ] ) ;
struct V_24 * V_65 = & ( V_62 -> V_15 . V_16 [ 1 ] ) ;
struct V_24 * V_66 = & ( V_38 -> V_15 . V_16 [ 0 ] ) ;
struct V_24 * V_67 = & ( V_38 -> V_15 . V_16 [ 1 ] ) ;
struct V_24 * V_68 = & ( V_38 -> V_69 ) ;
struct V_24 * V_70 = & ( V_63 -> V_15 . V_16 [ 0 ] ) ;
struct V_24 * V_71 = & ( V_63 -> V_15 . V_16 [ 1 ] ) ;
if ( F_23 ( V_68 , V_64 , V_65 ) )
* V_70 = * V_68 ;
else if ( F_23 ( V_64 , V_68 , V_67 ) )
* V_70 = * V_64 ;
else if ( F_23 ( V_65 , V_66 , V_68 ) )
* V_70 = * V_66 ;
else
return - V_52 ;
if ( F_10 ( V_67 , V_65 ) )
* V_71 = * V_65 ;
else if ( F_10 ( V_65 , V_67 ) )
* V_71 = * V_67 ;
else
return - V_52 ;
}
return 0 ;
}
int F_24 ( struct V_12 * V_72 ,
struct V_12 * V_73 ,
struct V_1 * V_33 )
{
struct V_25 * V_26 ;
struct V_48 * V_49 ;
struct V_8 V_74 ;
struct V_10 * V_11 ;
int V_3 , V_2 ;
if ( ! V_12 . V_13 )
return 0 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_26 = F_7 ( V_73 -> V_27 . V_29 ,
F_2 ( V_72 , V_18 ,
V_33 -> V_15 . V_16 [ V_3 ] . V_17 - 1 ) ) ;
if ( ! V_26 )
return - V_52 ;
V_33 -> V_15 . V_16 [ V_3 ] . V_17 = V_26 -> V_16 -> V_17 ;
F_25 ( & V_74 ) ;
F_3 (&c->range.level[l].cat, node, i) {
int V_51 ;
V_49 = F_7 ( V_73 -> V_30 . V_29 ,
F_2 ( V_72 , V_20 , V_2 ) ) ;
if ( ! V_49 )
return - V_52 ;
V_51 = F_16 ( & V_74 , V_49 -> V_56 - 1 , 1 ) ;
if ( V_51 )
return V_51 ;
F_26 () ;
}
F_27 ( & V_33 -> V_15 . V_16 [ V_3 ] . V_19 ) ;
V_33 -> V_15 . V_16 [ V_3 ] . V_19 = V_74 ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_21 ,
struct V_1 * V_75 ,
T_3 V_76 ,
T_1 V_77 ,
struct V_1 * V_78 ,
bool V_79 )
{
struct V_80 V_81 ;
struct V_31 * V_32 ;
struct V_82 * V_83 ;
int V_84 = 0 ;
if ( ! V_12 . V_13 )
return 0 ;
switch ( V_77 ) {
case V_85 :
V_81 . V_86 = V_21 -> type ;
V_81 . V_87 = V_75 -> type ;
V_81 . V_88 = V_76 ;
V_32 = F_7 ( V_12 . V_89 , & V_81 ) ;
if ( V_32 )
return F_21 ( V_78 , V_32 ) ;
if ( V_76 && V_76 <= V_12 . V_90 . V_28 ) {
V_83 = V_12 . V_91 [ V_76 - 1 ] ;
if ( V_83 )
V_84 = V_83 -> V_84 ;
}
switch ( V_84 ) {
case V_92 :
return F_29 ( V_78 , V_21 ) ;
case V_93 :
return F_30 ( V_78 , V_21 ) ;
case V_94 :
return F_15 ( V_78 , V_21 ) ;
case V_95 :
return F_29 ( V_78 , V_75 ) ;
case V_96 :
return F_30 ( V_78 , V_75 ) ;
case V_97 :
return F_15 ( V_78 , V_75 ) ;
}
case V_98 :
if ( ( V_76 == V_12 . V_99 ) || ( V_79 == true ) )
return F_15 ( V_78 , V_21 ) ;
else
return F_29 ( V_78 , V_21 ) ;
case V_100 :
return F_29 ( V_78 , V_21 ) ;
}
return - V_52 ;
}
void F_31 ( struct V_1 * V_1 ,
struct V_101 * V_102 )
{
if ( ! V_12 . V_13 )
return;
V_102 -> V_103 . V_104 . V_105 = V_1 -> V_15 . V_16 [ 0 ] . V_17 - 1 ;
V_102 -> V_106 |= V_107 ;
}
void F_32 ( struct V_1 * V_1 ,
struct V_101 * V_102 )
{
if ( ! V_12 . V_13 )
return;
V_1 -> V_15 . V_16 [ 0 ] . V_17 = V_102 -> V_103 . V_104 . V_105 + 1 ;
V_1 -> V_15 . V_16 [ 1 ] . V_17 = V_1 -> V_15 . V_16 [ 0 ] . V_17 ;
}
int F_33 ( struct V_1 * V_1 ,
struct V_101 * V_102 )
{
int V_51 ;
if ( ! V_12 . V_13 )
return 0 ;
V_51 = F_34 ( & V_1 -> V_15 . V_16 [ 0 ] . V_19 ,
& V_102 -> V_103 . V_104 . V_19 ) ;
if ( V_51 == 0 && V_102 -> V_103 . V_104 . V_19 != NULL )
V_102 -> V_106 |= V_108 ;
return V_51 ;
}
int F_35 ( struct V_1 * V_1 ,
struct V_101 * V_102 )
{
int V_51 ;
if ( ! V_12 . V_13 )
return 0 ;
V_51 = F_36 ( & V_1 -> V_15 . V_16 [ 0 ] . V_19 ,
V_102 -> V_103 . V_104 . V_19 ) ;
if ( V_51 )
goto V_109;
memcpy ( & V_1 -> V_15 . V_16 [ 1 ] . V_19 , & V_1 -> V_15 . V_16 [ 0 ] . V_19 ,
sizeof( V_1 -> V_15 . V_16 [ 0 ] . V_19 ) ) ;
return 0 ;
V_109:
F_27 ( & V_1 -> V_15 . V_16 [ 0 ] . V_19 ) ;
return V_51 ;
}
