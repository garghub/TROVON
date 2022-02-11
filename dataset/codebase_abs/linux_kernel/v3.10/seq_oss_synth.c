void T_1
F_1 ( void )
{
F_2 ( & V_1 . V_2 ) ;
}
int
F_3 ( struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = F_4 ( V_4 ) ;
unsigned long V_10 ;
if ( ( V_7 = F_5 ( sizeof( * V_7 ) , V_11 ) ) == NULL ) {
F_6 ( V_12 L_1 ) ;
return - V_13 ;
}
V_7 -> V_14 = - 1 ;
V_7 -> V_15 = V_9 -> type ;
V_7 -> V_16 = V_9 -> V_17 ;
V_7 -> V_18 = V_9 -> V_19 ;
V_7 -> V_20 = V_9 -> V_20 ;
V_7 -> V_21 = V_9 -> V_21 ;
V_7 -> V_22 = 0 ;
F_2 ( & V_7 -> V_2 ) ;
F_7 ( V_7 -> V_23 , V_4 -> V_23 , sizeof( V_7 -> V_23 ) ) ;
F_8 ( & V_24 , V_10 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
if ( V_26 [ V_5 ] == NULL )
break;
}
if ( V_5 >= V_25 ) {
if ( V_25 >= V_27 ) {
F_9 ( & V_24 , V_10 ) ;
F_6 ( V_12 L_2 ) ;
F_10 ( V_7 ) ;
return - V_13 ;
}
V_25 ++ ;
}
V_7 -> V_14 = V_5 ;
V_26 [ V_5 ] = V_7 ;
F_11 ( ( L_3 , V_7 -> V_23 , V_5 ) ) ;
F_9 ( & V_24 , V_10 ) ;
V_4 -> V_28 = V_7 ;
#ifdef F_12
if ( V_5 < V_29 )
F_13 ( F_12 , V_5 , V_7 -> V_23 ) ;
#endif
return 0 ;
}
int
F_14 ( struct V_3 * V_4 )
{
int V_30 ;
struct V_6 * V_7 = V_4 -> V_28 ;
unsigned long V_10 ;
F_8 ( & V_24 , V_10 ) ;
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ ) {
if ( V_26 [ V_30 ] == V_7 )
break;
}
if ( V_30 >= V_25 ) {
F_9 ( & V_24 , V_10 ) ;
F_6 ( V_12 L_4 ) ;
return - V_31 ;
}
V_26 [ V_30 ] = NULL ;
if ( V_30 == V_25 - 1 ) {
for ( V_30 -- ; V_30 >= 0 ; V_30 -- ) {
if ( V_26 [ V_30 ] )
break;
}
V_25 = V_30 + 1 ;
}
F_9 ( & V_24 , V_10 ) ;
#ifdef F_12
if ( V_7 -> V_14 < V_29 )
F_15 ( F_12 , V_7 -> V_14 ) ;
#endif
F_16 ( & V_7 -> V_2 ) ;
F_10 ( V_7 ) ;
return 0 ;
}
static struct V_6 *
F_17 ( int V_4 )
{
struct V_6 * V_7 ;
unsigned long V_10 ;
F_8 ( & V_24 , V_10 ) ;
V_7 = V_26 [ V_4 ] ;
if ( V_7 )
F_18 ( & V_7 -> V_2 ) ;
F_9 ( & V_24 , V_10 ) ;
return V_7 ;
}
void
F_19 ( struct V_32 * V_33 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_34 * V_35 ;
V_33 -> V_36 = V_25 ;
V_33 -> V_37 = 0 ;
memset ( V_33 -> V_38 , 0 , sizeof( V_33 -> V_38 ) ) ;
for ( V_5 = 0 ; V_5 < V_33 -> V_36 ; V_5 ++ ) {
V_7 = F_17 ( V_5 ) ;
if ( V_7 == NULL )
continue;
if ( V_7 -> V_20 . V_39 == NULL || V_7 -> V_20 . V_40 == NULL ) {
F_20 ( & V_7 -> V_2 ) ;
continue;
}
V_35 = & V_33 -> V_38 [ V_5 ] ;
V_35 -> V_41 . V_42 = V_33 -> V_43 ;
V_35 -> V_41 . V_44 = V_33 -> V_44 ;
V_35 -> V_41 . V_45 = V_33 -> V_45 ;
if ( V_33 -> V_45 == V_46 )
V_35 -> V_41 . V_47 = V_48 ;
else
V_35 -> V_41 . V_47 = V_49 ;
V_35 -> V_22 = 0 ;
if ( ! F_21 ( V_7 -> V_20 . V_50 ) ) {
F_20 ( & V_7 -> V_2 ) ;
continue;
}
if ( V_7 -> V_20 . V_39 ( & V_35 -> V_41 , V_7 -> V_21 ) < 0 ) {
F_22 ( V_7 -> V_20 . V_50 ) ;
F_20 ( & V_7 -> V_2 ) ;
continue;
}
V_35 -> V_18 = V_7 -> V_18 ;
if ( V_35 -> V_18 > 0 ) {
V_35 -> V_51 = F_23 ( V_35 -> V_18 , sizeof( struct V_52 ) , V_11 ) ;
if ( ! V_35 -> V_51 ) {
F_6 ( V_12 L_5 ) ;
V_7 -> V_20 . V_40 ( & V_35 -> V_41 ) ;
F_22 ( V_7 -> V_20 . V_50 ) ;
F_20 ( & V_7 -> V_2 ) ;
continue;
}
F_24 ( V_35 ) ;
}
F_11 ( ( L_6 , V_5 ) ) ;
V_35 -> V_22 ++ ;
V_7 -> V_22 ++ ;
V_33 -> V_37 ++ ;
F_20 ( & V_7 -> V_2 ) ;
}
}
void
F_25 ( struct V_32 * V_33 )
{
int V_5 ;
if ( V_33 -> V_36 >= V_27 )
return;
for ( V_5 = 0 ; V_5 < V_33 -> V_53 ; V_5 ++ ) {
struct V_34 * V_35 ;
V_35 = & V_33 -> V_38 [ V_33 -> V_36 ] ;
if ( F_26 ( V_33 , V_5 , V_33 -> V_44 ) < 0 )
continue;
V_35 -> V_41 . V_42 = V_33 -> V_43 ;
V_35 -> V_41 . V_44 = V_33 -> V_44 ;
V_35 -> V_41 . V_45 = V_33 -> V_45 ;
V_35 -> V_41 . V_21 = V_35 ;
V_35 -> V_54 = 1 ;
V_35 -> V_55 = V_5 ;
V_35 -> V_41 . V_47 = V_49 ;
F_27 ( V_33 , V_5 , & V_35 -> V_41 . V_56 ) ;
V_35 -> V_22 = 1 ;
V_1 . V_22 ++ ;
V_33 -> V_36 ++ ;
if ( V_33 -> V_36 >= V_27 )
break;
}
}
void
F_28 ( struct V_32 * V_33 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_34 * V_35 ;
if ( F_29 ( V_33 -> V_36 >= V_27 ) )
return;
for ( V_5 = 0 ; V_5 < V_33 -> V_36 ; V_5 ++ ) {
V_35 = & V_33 -> V_38 [ V_5 ] ;
if ( ! V_35 -> V_22 )
continue;
if ( V_35 -> V_54 ) {
if ( V_1 . V_22 > 0 ) {
F_30 ( V_33 , V_35 -> V_55 ) ;
V_1 . V_22 -- ;
}
} else {
V_7 = F_17 ( V_5 ) ;
if ( V_7 == NULL )
continue;
if ( V_7 -> V_22 > 0 ) {
F_11 ( ( L_7 , V_5 ) ) ;
V_7 -> V_20 . V_40 ( & V_35 -> V_41 ) ;
F_22 ( V_7 -> V_20 . V_50 ) ;
V_7 -> V_22 = 0 ;
}
F_20 ( & V_7 -> V_2 ) ;
}
F_10 ( V_35 -> V_57 ) ;
V_35 -> V_57 = NULL ;
F_10 ( V_35 -> V_51 ) ;
V_35 -> V_51 = NULL ;
}
V_33 -> V_37 = 0 ;
V_33 -> V_36 = 0 ;
}
static int
F_31 ( struct V_32 * V_33 , int V_4 )
{
if ( V_4 < 0 || V_4 >= V_33 -> V_36 )
return 0 ;
if ( V_33 -> V_38 [ V_4 ] . V_54 )
return 1 ;
return 0 ;
}
static struct V_6 *
F_32 ( struct V_32 * V_33 , int V_4 )
{
struct V_6 * V_7 ;
if ( V_4 < 0 || V_4 >= V_33 -> V_36 )
return NULL ;
if ( ! V_33 -> V_38 [ V_4 ] . V_22 )
return NULL ;
if ( V_33 -> V_38 [ V_4 ] . V_54 )
return & V_1 ;
if ( ( V_7 = F_17 ( V_4 ) ) == NULL )
return NULL ;
if ( ! V_7 -> V_22 ) {
F_20 ( & V_7 -> V_2 ) ;
return NULL ;
}
return V_7 ;
}
static void
F_24 ( struct V_34 * V_35 )
{
int V_5 ;
if ( V_35 -> V_51 == NULL || ! V_35 -> V_18 )
return;
for ( V_5 = 0 ; V_5 < V_35 -> V_18 ; V_5 ++ ) {
V_35 -> V_51 [ V_5 ] . V_58 = - 1 ;
V_35 -> V_51 [ V_5 ] . V_59 = 0 ;
}
}
void
F_33 ( struct V_32 * V_33 , int V_4 )
{
struct V_6 * V_7 ;
struct V_34 * V_35 ;
if ( F_29 ( V_4 < 0 || V_4 >= V_33 -> V_36 ) )
return;
V_35 = & V_33 -> V_38 [ V_4 ] ;
if ( ! V_35 -> V_22 )
return;
if ( V_35 -> V_57 )
V_35 -> V_57 -> V_60 = 0 ;
F_24 ( V_35 ) ;
if ( V_35 -> V_54 ) {
if ( V_1 . V_22 <= 0 )
return;
F_34 ( V_33 , V_35 -> V_55 ) ;
F_30 ( V_33 , V_4 ) ;
if ( F_26 ( V_33 , V_35 -> V_55 ,
V_33 -> V_44 ) < 0 ) {
V_1 . V_22 -- ;
V_35 -> V_22 = 0 ;
F_10 ( V_35 -> V_57 ) ;
V_35 -> V_57 = NULL ;
F_10 ( V_35 -> V_51 ) ;
V_35 -> V_51 = NULL ;
}
return;
}
V_7 = F_17 ( V_4 ) ;
if ( V_7 == NULL )
return;
if ( V_7 -> V_20 . V_61 ) {
V_7 -> V_20 . V_61 ( & V_35 -> V_41 ) ;
} else {
struct V_62 V_63 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
F_35 ( V_33 , & V_63 , V_35 -> V_41 . V_56 . V_64 ,
V_35 -> V_41 . V_56 . V_43 ) ;
V_63 . type = V_65 ;
F_36 ( V_33 , & V_63 , 0 , 0 ) ;
}
F_20 ( & V_7 -> V_2 ) ;
}
int
F_37 ( struct V_32 * V_33 , int V_4 , int V_66 ,
const char T_2 * V_67 , int V_68 , int V_69 )
{
struct V_6 * V_7 ;
int V_70 ;
if ( V_4 < 0 || V_4 >= V_33 -> V_36 )
return - V_71 ;
if ( F_31 ( V_33 , V_4 ) )
return 0 ;
if ( ( V_7 = F_32 ( V_33 , V_4 ) ) == NULL )
return - V_71 ;
if ( V_7 -> V_20 . V_72 == NULL )
V_70 = - V_71 ;
else
V_70 = V_7 -> V_20 . V_72 ( & V_33 -> V_38 [ V_4 ] . V_41 , V_66 , V_67 , V_68 , V_69 ) ;
F_20 ( & V_7 -> V_2 ) ;
return V_70 ;
}
int
F_38 ( struct V_32 * V_33 , int V_4 )
{
struct V_6 * V_7 ;
V_7 = F_32 ( V_33 , V_4 ) ;
if ( V_7 ) {
F_20 ( & V_7 -> V_2 ) ;
return 1 ;
}
return 0 ;
}
int
F_39 ( struct V_32 * V_33 , int V_4 , unsigned char * V_67 , struct V_62 * V_63 )
{
int V_5 , V_73 ;
unsigned char * V_74 ;
struct V_75 * V_57 ;
if ( ! F_38 ( V_33 , V_4 ) )
return - V_71 ;
V_57 = V_33 -> V_38 [ V_4 ] . V_57 ;
if ( V_57 == NULL ) {
V_57 = F_5 ( sizeof( * V_57 ) , V_11 ) ;
if ( V_57 == NULL )
return - V_13 ;
V_33 -> V_38 [ V_4 ] . V_57 = V_57 ;
}
V_73 = 0 ;
V_74 = V_57 -> V_67 + V_57 -> V_60 ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( V_67 [ V_5 ] == 0xff ) {
V_73 = 1 ;
break;
}
V_74 [ V_5 ] = V_67 [ V_5 ] ;
V_57 -> V_60 ++ ;
if ( V_57 -> V_60 >= V_76 ) {
V_57 -> V_60 = 0 ;
V_57 -> V_77 = 1 ;
break;
}
}
if ( V_57 -> V_60 && V_73 ) {
if ( V_57 -> V_77 ) {
V_57 -> V_77 = 0 ;
V_57 -> V_60 = 0 ;
return - V_31 ;
}
V_63 -> V_10 = V_78 ;
if ( F_40 ( V_33 , V_4 , V_63 ) )
return - V_31 ;
V_63 -> V_79 . V_80 . V_60 = V_57 -> V_60 ;
V_63 -> V_79 . V_80 . V_81 = V_57 -> V_67 ;
V_57 -> V_60 = 0 ;
return 0 ;
}
return - V_31 ;
}
int
F_40 ( struct V_32 * V_33 , int V_4 , struct V_62 * V_63 )
{
if ( ! F_38 ( V_33 , V_4 ) )
return - V_31 ;
F_35 ( V_33 , V_63 , V_33 -> V_38 [ V_4 ] . V_41 . V_56 . V_64 ,
V_33 -> V_38 [ V_4 ] . V_41 . V_56 . V_43 ) ;
return 0 ;
}
int
F_41 ( struct V_32 * V_33 , int V_4 , unsigned int V_82 , unsigned long V_56 )
{
struct V_6 * V_7 ;
int V_70 ;
if ( F_31 ( V_33 , V_4 ) )
return - V_71 ;
if ( ( V_7 = F_32 ( V_33 , V_4 ) ) == NULL )
return - V_71 ;
if ( V_7 -> V_20 . V_83 == NULL )
V_70 = - V_71 ;
else
V_70 = V_7 -> V_20 . V_83 ( & V_33 -> V_38 [ V_4 ] . V_41 , V_82 , V_56 ) ;
F_20 ( & V_7 -> V_2 ) ;
return V_70 ;
}
int
F_42 ( struct V_32 * V_33 , int V_4 , unsigned char * V_79 , struct V_62 * V_63 )
{
if ( ! F_38 ( V_33 , V_4 ) || F_31 ( V_33 , V_4 ) )
return - V_71 ;
V_63 -> type = V_84 ;
memcpy ( V_63 -> V_79 . V_85 . V_86 , V_79 , 8 ) ;
return F_40 ( V_33 , V_4 , V_63 ) ;
}
int
F_43 ( struct V_32 * V_33 , int V_4 , struct V_87 * V_88 )
{
struct V_6 * V_7 ;
if ( V_4 < 0 || V_4 >= V_33 -> V_36 )
return - V_71 ;
if ( V_33 -> V_38 [ V_4 ] . V_54 ) {
struct V_89 V_90 ;
F_44 ( V_33 , V_33 -> V_38 [ V_4 ] . V_55 , & V_90 ) ;
V_88 -> V_15 = V_91 ;
V_88 -> V_16 = 0 ;
V_88 -> V_18 = 16 ;
V_88 -> V_92 = V_4 ;
F_7 ( V_88 -> V_23 , V_90 . V_23 , sizeof( V_88 -> V_23 ) ) ;
} else {
if ( ( V_7 = F_32 ( V_33 , V_4 ) ) == NULL )
return - V_71 ;
V_88 -> V_15 = V_7 -> V_15 ;
V_88 -> V_16 = V_7 -> V_16 ;
V_88 -> V_18 = V_7 -> V_18 ;
V_88 -> V_92 = V_4 ;
F_7 ( V_88 -> V_23 , V_7 -> V_23 , sizeof( V_88 -> V_23 ) ) ;
F_20 ( & V_7 -> V_2 ) ;
}
return 0 ;
}
void
F_45 ( struct V_93 * V_67 )
{
int V_5 ;
struct V_6 * V_7 ;
F_46 ( V_67 , L_8 , V_25 ) ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
F_46 ( V_67 , L_9 , V_5 ) ;
V_7 = F_17 ( V_5 ) ;
if ( V_7 == NULL ) {
F_46 ( V_67 , L_10 ) ;
continue;
}
F_46 ( V_67 , L_11 , V_7 -> V_23 ) ;
F_46 ( V_67 , L_12 ,
V_7 -> V_15 , V_7 -> V_16 ,
V_7 -> V_18 ) ;
F_46 ( V_67 , L_13 ,
F_47 ( ( long ) V_7 -> V_20 . V_83 ) ,
F_47 ( ( long ) V_7 -> V_20 . V_72 ) ) ;
F_20 ( & V_7 -> V_2 ) ;
}
}
