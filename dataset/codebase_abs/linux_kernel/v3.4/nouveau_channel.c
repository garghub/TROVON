static int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ? V_5 : V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
int V_12 ;
V_12 = F_2 ( V_8 , 65536 , 0 , V_3 , 0 , 0 , & V_2 -> V_13 ) ;
if ( V_12 )
goto V_14;
V_12 = F_3 ( V_2 -> V_13 , V_3 ) ;
if ( V_12 )
goto V_14;
V_12 = F_4 ( V_2 -> V_13 ) ;
if ( V_12 )
goto V_14;
V_2 -> V_15 = V_2 -> V_13 -> V_16 . V_17 ;
if ( V_10 -> V_18 >= V_19 ) {
V_12 = F_5 ( V_2 -> V_13 , V_2 -> V_20 ,
& V_2 -> V_21 ) ;
if ( V_12 )
goto V_14;
if ( V_10 -> V_18 < V_22 ) {
V_12 = F_6 ( V_2 ,
V_23 , 0 ,
( 1ULL << 40 ) ,
V_24 ,
V_25 ,
& V_2 -> V_26 ) ;
}
V_2 -> V_15 = V_2 -> V_21 . V_17 ;
} else
if ( V_2 -> V_13 -> V_16 . V_3 . V_27 == V_28 ) {
V_12 = F_6 ( V_2 , V_23 , 0 ,
V_10 -> V_29 . V_30 ,
V_24 ,
V_31 ,
& V_2 -> V_26 ) ;
} else
if ( V_10 -> V_18 != V_32 ) {
V_12 = F_6 ( V_2 , V_23 , 0 ,
V_10 -> V_33 ,
V_24 ,
V_34 ,
& V_2 -> V_26 ) ;
} else {
V_12 = F_6 ( V_2 , V_23 ,
F_7 ( V_8 -> V_35 , 1 ) ,
V_10 -> V_33 ,
V_24 ,
V_36 ,
& V_2 -> V_26 ) ;
}
V_14:
if ( V_12 ) {
F_8 ( V_8 , L_1 , V_12 ) ;
F_9 ( V_2 -> V_13 , & V_2 -> V_21 ) ;
F_10 ( NULL , & V_2 -> V_26 ) ;
if ( V_2 -> V_13 ) {
F_11 ( V_2 -> V_13 ) ;
F_12 ( NULL , & V_2 -> V_13 ) ;
}
}
return 0 ;
}
int
F_13 ( struct V_7 * V_8 , struct V_1 * * V_37 ,
struct V_38 * V_39 ,
T_2 V_40 , T_2 V_41 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_42 * V_43 = & V_10 -> V_44 . V_45 ;
struct V_46 * V_47 = V_46 ( V_39 ) ;
struct V_1 * V_2 ;
unsigned long V_48 ;
int V_12 , V_49 ;
V_2 = F_14 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_41 = V_41 ;
F_15 ( & V_2 -> V_52 ) ;
F_16 ( & V_2 -> V_53 , 1 ) ;
F_17 ( & V_2 -> V_54 ) ;
F_18 ( & V_2 -> V_54 ) ;
F_19 ( & V_10 -> V_55 . V_56 , V_48 ) ;
for ( V_2 -> V_57 = 0 ; V_2 -> V_57 < V_43 -> V_55 ; V_2 -> V_57 ++ ) {
if ( ! V_10 -> V_55 . V_58 [ V_2 -> V_57 ] ) {
F_20 ( V_2 , & V_10 -> V_55 . V_58 [ V_2 -> V_57 ] ) ;
break;
}
}
F_21 ( & V_10 -> V_55 . V_56 , V_48 ) ;
if ( V_2 -> V_57 == V_43 -> V_55 ) {
F_22 ( & V_2 -> V_54 ) ;
F_23 ( V_2 ) ;
return - V_59 ;
}
F_24 ( V_8 , L_2 , V_2 -> V_57 ) ;
F_25 ( & V_2 -> V_60 . V_61 ) ;
F_25 ( & V_2 -> V_60 . V_62 ) ;
F_25 ( & V_2 -> V_63 . V_64 ) ;
F_26 ( & V_2 -> V_63 . V_56 ) ;
V_12 = F_27 ( V_2 , V_40 , V_41 ) ;
if ( V_12 ) {
F_8 ( V_8 , L_3 , V_12 ) ;
F_28 ( & V_2 ) ;
return V_12 ;
}
V_12 = F_29 ( V_2 ) ;
if ( V_12 ) {
F_8 ( V_8 , L_4 , V_12 ) ;
F_28 ( & V_2 ) ;
return V_12 ;
}
V_12 = F_1 ( V_2 ) ;
if ( V_12 ) {
F_8 ( V_8 , L_5 , V_12 ) ;
F_28 ( & V_2 ) ;
return V_12 ;
}
F_30 ( V_2 ) ;
V_2 -> V_65 = 0x40 ;
V_2 -> V_66 = 0x44 ;
if ( V_10 -> V_18 >= V_19 )
V_2 -> V_67 = 0x60 ;
V_43 -> V_68 ( V_8 , false ) ;
V_12 = V_43 -> V_69 ( V_2 ) ;
if ( V_12 ) {
F_28 ( & V_2 ) ;
return V_12 ;
}
V_43 -> V_68 ( V_8 , true ) ;
V_12 = F_31 ( V_2 , V_70 ) ;
if ( V_12 ) {
F_28 ( & V_2 ) ;
return V_12 ;
}
for ( V_49 = 0 ; V_49 < V_70 ; V_49 ++ )
F_32 ( V_2 , 0x00000000 ) ;
F_33 ( V_2 ) ;
V_12 = F_34 ( V_2 ) ;
if ( V_12 ) {
F_28 ( & V_2 ) ;
return V_12 ;
}
F_35 ( V_2 ) ;
F_24 ( V_8 , L_6 , V_2 -> V_57 ) ;
if ( V_47 ) {
F_36 ( & V_47 -> V_56 ) ;
F_37 ( & V_2 -> V_71 , & V_47 -> V_55 ) ;
F_38 ( & V_47 -> V_56 ) ;
}
* V_37 = V_2 ;
return 0 ;
}
struct V_1 *
F_39 ( struct V_1 * V_52 )
{
struct V_1 * V_2 = NULL ;
if ( F_40 ( V_52 && F_41 ( & V_52 -> V_53 ) ) )
F_20 ( V_52 , & V_2 ) ;
return V_2 ;
}
struct V_1 *
F_42 ( struct V_38 * V_39 , int V_57 )
{
struct V_46 * V_47 = V_46 ( V_39 ) ;
struct V_1 * V_2 ;
F_36 ( & V_47 -> V_56 ) ;
F_43 (chan, &fpriv->channels, list) {
if ( V_2 -> V_57 == V_57 ) {
V_2 = F_39 ( V_2 ) ;
F_38 ( & V_47 -> V_56 ) ;
F_18 ( & V_2 -> V_54 ) ;
return V_2 ;
}
}
F_38 ( & V_47 -> V_56 ) ;
return F_44 ( - V_72 ) ;
}
void
F_45 ( struct V_1 * * V_73 )
{
struct V_1 * V_2 = * V_73 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_42 * V_43 = & V_10 -> V_44 . V_45 ;
unsigned long V_48 ;
int V_49 ;
if ( F_40 ( ! F_46 ( & V_2 -> V_53 ) ) ) {
F_20 ( NULL , V_73 ) ;
return;
}
F_24 ( V_8 , L_7 , V_2 -> V_57 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
V_43 -> V_68 ( V_8 , false ) ;
V_43 -> V_74 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_75 ; V_49 ++ ) {
if ( V_2 -> V_76 [ V_49 ] )
V_10 -> V_77 [ V_49 ] -> F_50 ( V_2 , V_49 ) ;
}
V_43 -> V_68 ( V_8 , true ) ;
F_19 ( & V_10 -> V_55 . V_56 , V_48 ) ;
F_20 ( NULL , & V_10 -> V_55 . V_58 [ V_2 -> V_57 ] ) ;
F_21 ( & V_10 -> V_55 . V_56 , V_48 ) ;
F_10 ( NULL , & V_2 -> V_26 ) ;
if ( V_2 -> V_13 ) {
F_9 ( V_2 -> V_13 , & V_2 -> V_21 ) ;
F_11 ( V_2 -> V_13 ) ;
F_51 ( V_2 -> V_13 ) ;
F_12 ( NULL , & V_2 -> V_13 ) ;
}
F_52 ( NULL , & V_2 -> V_78 , V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_20 ( NULL , V_73 ) ;
}
void
F_28 ( struct V_1 * * V_73 )
{
F_22 ( & ( * V_73 ) -> V_54 ) ;
F_45 ( V_73 ) ;
}
static void
F_55 ( struct V_79 * V_52 )
{
struct V_1 * V_2 =
F_56 ( V_52 , struct V_1 , V_52 ) ;
F_23 ( V_2 ) ;
}
void
F_20 ( struct V_1 * V_2 ,
struct V_1 * * V_73 )
{
if ( V_2 )
F_57 ( & V_2 -> V_52 ) ;
if ( * V_73 )
F_58 ( & ( * V_73 ) -> V_52 , F_55 ) ;
* V_73 = V_2 ;
}
void
F_48 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_80 * V_63 = NULL ;
int V_12 ;
F_59 ( V_2 ) ;
if ( V_2 -> V_63 . V_81 != V_2 -> V_63 . V_82 ) {
V_12 = F_60 ( V_2 , & V_63 , true ) ;
if ( ! V_12 ) {
V_12 = F_61 ( V_63 , false , false ) ;
F_62 ( & V_63 ) ;
}
if ( V_12 )
F_8 ( V_8 , L_8 , V_2 -> V_57 ) ;
}
}
void
F_63 ( struct V_7 * V_8 , struct V_38 * V_39 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_83 * V_44 = & V_10 -> V_44 ;
struct V_1 * V_2 ;
int V_49 ;
F_24 ( V_8 , L_9 ) ;
for ( V_49 = 0 ; V_49 < V_44 -> V_45 . V_55 ; V_49 ++ ) {
V_2 = F_42 ( V_39 , V_49 ) ;
if ( F_64 ( V_2 ) )
continue;
F_65 ( & V_2 -> V_71 ) ;
F_66 ( & V_2 -> V_53 ) ;
F_28 ( & V_2 ) ;
}
}
static int
F_67 ( struct V_7 * V_8 , void * V_84 ,
struct V_38 * V_39 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_85 * V_86 = V_84 ;
struct V_1 * V_2 ;
int V_12 ;
if ( ! V_10 -> V_77 [ V_87 ] )
return - V_59 ;
if ( V_86 -> V_88 == ~ 0 || V_86 -> V_89 == ~ 0 )
return - V_72 ;
V_12 = F_13 ( V_8 , & V_2 , V_39 ,
V_86 -> V_88 ,
V_86 -> V_89 ) ;
if ( V_12 )
return V_12 ;
V_86 -> V_90 = V_2 -> V_57 ;
if ( V_4 == 0 ) {
if ( V_2 -> V_91 . V_92 )
V_86 -> V_93 = V_94 |
V_95 ;
else if ( V_2 -> V_13 -> V_16 . V_3 . V_27 == V_96 )
V_86 -> V_93 = V_94 ;
else
V_86 -> V_93 = V_95 ;
} else {
V_86 -> V_93 = V_94 ;
}
if ( V_10 -> V_18 < V_22 ) {
V_86 -> V_97 [ 0 ] . V_98 = 0x00000000 ;
V_86 -> V_97 [ 0 ] . V_99 = 0x0000 ;
V_86 -> V_97 [ 1 ] . V_98 = V_100 ;
V_86 -> V_97 [ 1 ] . V_99 = V_101 ;
V_86 -> V_102 = 2 ;
}
V_12 = F_68 ( V_39 , V_2 -> V_103 -> V_104 ,
& V_86 -> V_105 ) ;
if ( V_12 == 0 )
F_69 ( & V_2 -> V_53 ) ;
F_28 ( & V_2 ) ;
return V_12 ;
}
static int
F_70 ( struct V_7 * V_8 , void * V_84 ,
struct V_38 * V_39 )
{
struct V_106 * V_107 = V_84 ;
struct V_1 * V_2 ;
V_2 = F_42 ( V_39 , V_107 -> V_90 ) ;
if ( F_64 ( V_2 ) )
return F_71 ( V_2 ) ;
F_65 ( & V_2 -> V_71 ) ;
F_66 ( & V_2 -> V_53 ) ;
F_28 ( & V_2 ) ;
return 0 ;
}
