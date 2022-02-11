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
F_6 ( L_1 ) ;
return - V_12 ;
}
V_7 -> V_13 = - 1 ;
V_7 -> V_14 = V_9 -> type ;
V_7 -> V_15 = V_9 -> V_16 ;
V_7 -> V_17 = V_9 -> V_18 ;
V_7 -> V_19 = V_9 -> V_19 ;
V_7 -> V_20 = V_9 -> V_20 ;
V_7 -> V_21 = 0 ;
F_2 ( & V_7 -> V_2 ) ;
F_7 ( V_7 -> V_22 , V_4 -> V_22 , sizeof( V_7 -> V_22 ) ) ;
F_8 ( & V_23 , V_10 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
if ( V_25 [ V_5 ] == NULL )
break;
}
if ( V_5 >= V_24 ) {
if ( V_24 >= V_26 ) {
F_9 ( & V_23 , V_10 ) ;
F_6 ( L_2 ) ;
F_10 ( V_7 ) ;
return - V_12 ;
}
V_24 ++ ;
}
V_7 -> V_13 = V_5 ;
V_25 [ V_5 ] = V_7 ;
F_9 ( & V_23 , V_10 ) ;
V_4 -> V_27 = V_7 ;
#ifdef F_11
if ( V_5 < V_28 )
F_12 ( F_11 , V_5 , V_7 -> V_22 ) ;
#endif
return 0 ;
}
int
F_13 ( struct V_3 * V_4 )
{
int V_29 ;
struct V_6 * V_7 = V_4 -> V_27 ;
unsigned long V_10 ;
F_8 ( & V_23 , V_10 ) ;
for ( V_29 = 0 ; V_29 < V_24 ; V_29 ++ ) {
if ( V_25 [ V_29 ] == V_7 )
break;
}
if ( V_29 >= V_24 ) {
F_9 ( & V_23 , V_10 ) ;
F_6 ( L_3 ) ;
return - V_30 ;
}
V_25 [ V_29 ] = NULL ;
if ( V_29 == V_24 - 1 ) {
for ( V_29 -- ; V_29 >= 0 ; V_29 -- ) {
if ( V_25 [ V_29 ] )
break;
}
V_24 = V_29 + 1 ;
}
F_9 ( & V_23 , V_10 ) ;
#ifdef F_11
if ( V_7 -> V_13 < V_28 )
F_14 ( F_11 , V_7 -> V_13 ) ;
#endif
F_15 ( & V_7 -> V_2 ) ;
F_10 ( V_7 ) ;
return 0 ;
}
static struct V_6 *
F_16 ( int V_4 )
{
struct V_6 * V_7 ;
unsigned long V_10 ;
F_8 ( & V_23 , V_10 ) ;
V_7 = V_25 [ V_4 ] ;
if ( V_7 )
F_17 ( & V_7 -> V_2 ) ;
F_9 ( & V_23 , V_10 ) ;
return V_7 ;
}
void
F_18 ( struct V_31 * V_32 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
V_32 -> V_35 = V_24 ;
V_32 -> V_36 = 0 ;
memset ( V_32 -> V_37 , 0 , sizeof( V_32 -> V_37 ) ) ;
for ( V_5 = 0 ; V_5 < V_32 -> V_35 ; V_5 ++ ) {
V_7 = F_16 ( V_5 ) ;
if ( V_7 == NULL )
continue;
if ( V_7 -> V_19 . V_38 == NULL || V_7 -> V_19 . V_39 == NULL ) {
F_19 ( & V_7 -> V_2 ) ;
continue;
}
V_34 = & V_32 -> V_37 [ V_5 ] ;
V_34 -> V_40 . V_41 = V_32 -> V_42 ;
V_34 -> V_40 . V_43 = V_32 -> V_43 ;
V_34 -> V_40 . V_44 = V_32 -> V_44 ;
if ( V_32 -> V_44 == V_45 )
V_34 -> V_40 . V_46 = V_47 ;
else
V_34 -> V_40 . V_46 = V_48 ;
V_34 -> V_21 = 0 ;
if ( ! F_20 ( V_7 -> V_19 . V_49 ) ) {
F_19 ( & V_7 -> V_2 ) ;
continue;
}
if ( V_7 -> V_19 . V_38 ( & V_34 -> V_40 , V_7 -> V_20 ) < 0 ) {
F_21 ( V_7 -> V_19 . V_49 ) ;
F_19 ( & V_7 -> V_2 ) ;
continue;
}
V_34 -> V_17 = V_7 -> V_17 ;
if ( V_34 -> V_17 > 0 ) {
V_34 -> V_50 = F_22 ( V_34 -> V_17 , sizeof( struct V_51 ) , V_11 ) ;
if ( ! V_34 -> V_50 ) {
F_6 ( L_4 ) ;
V_7 -> V_19 . V_39 ( & V_34 -> V_40 ) ;
F_21 ( V_7 -> V_19 . V_49 ) ;
F_19 ( & V_7 -> V_2 ) ;
continue;
}
F_23 ( V_34 ) ;
}
V_34 -> V_21 ++ ;
V_7 -> V_21 ++ ;
V_32 -> V_36 ++ ;
F_19 ( & V_7 -> V_2 ) ;
}
}
void
F_24 ( struct V_31 * V_32 )
{
int V_5 ;
if ( V_32 -> V_35 >= V_26 )
return;
for ( V_5 = 0 ; V_5 < V_32 -> V_52 ; V_5 ++ ) {
struct V_33 * V_34 ;
V_34 = & V_32 -> V_37 [ V_32 -> V_35 ] ;
if ( F_25 ( V_32 , V_5 , V_32 -> V_43 ) < 0 )
continue;
V_34 -> V_40 . V_41 = V_32 -> V_42 ;
V_34 -> V_40 . V_43 = V_32 -> V_43 ;
V_34 -> V_40 . V_44 = V_32 -> V_44 ;
V_34 -> V_40 . V_20 = V_34 ;
V_34 -> V_53 = 1 ;
V_34 -> V_54 = V_5 ;
V_34 -> V_40 . V_46 = V_48 ;
F_26 ( V_32 , V_5 , & V_34 -> V_40 . V_55 ) ;
V_34 -> V_21 = 1 ;
V_1 . V_21 ++ ;
V_32 -> V_35 ++ ;
if ( V_32 -> V_35 >= V_26 )
break;
}
}
void
F_27 ( struct V_31 * V_32 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
if ( F_28 ( V_32 -> V_35 >= V_26 ) )
return;
for ( V_5 = 0 ; V_5 < V_32 -> V_35 ; V_5 ++ ) {
V_34 = & V_32 -> V_37 [ V_5 ] ;
if ( ! V_34 -> V_21 )
continue;
if ( V_34 -> V_53 ) {
if ( V_1 . V_21 > 0 ) {
F_29 ( V_32 , V_34 -> V_54 ) ;
V_1 . V_21 -- ;
}
} else {
V_7 = F_16 ( V_5 ) ;
if ( V_7 == NULL )
continue;
if ( V_7 -> V_21 > 0 ) {
V_7 -> V_19 . V_39 ( & V_34 -> V_40 ) ;
F_21 ( V_7 -> V_19 . V_49 ) ;
V_7 -> V_21 = 0 ;
}
F_19 ( & V_7 -> V_2 ) ;
}
F_10 ( V_34 -> V_56 ) ;
V_34 -> V_56 = NULL ;
F_10 ( V_34 -> V_50 ) ;
V_34 -> V_50 = NULL ;
}
V_32 -> V_36 = 0 ;
V_32 -> V_35 = 0 ;
}
static int
F_30 ( struct V_31 * V_32 , int V_4 )
{
if ( V_4 < 0 || V_4 >= V_32 -> V_35 )
return 0 ;
if ( V_32 -> V_37 [ V_4 ] . V_53 )
return 1 ;
return 0 ;
}
static struct V_6 *
F_31 ( struct V_31 * V_32 , int V_4 )
{
struct V_6 * V_7 ;
if ( V_4 < 0 || V_4 >= V_32 -> V_35 )
return NULL ;
if ( ! V_32 -> V_37 [ V_4 ] . V_21 )
return NULL ;
if ( V_32 -> V_37 [ V_4 ] . V_53 )
return & V_1 ;
if ( ( V_7 = F_16 ( V_4 ) ) == NULL )
return NULL ;
if ( ! V_7 -> V_21 ) {
F_19 ( & V_7 -> V_2 ) ;
return NULL ;
}
return V_7 ;
}
static void
F_23 ( struct V_33 * V_34 )
{
int V_5 ;
if ( V_34 -> V_50 == NULL || ! V_34 -> V_17 )
return;
for ( V_5 = 0 ; V_5 < V_34 -> V_17 ; V_5 ++ ) {
V_34 -> V_50 [ V_5 ] . V_57 = - 1 ;
V_34 -> V_50 [ V_5 ] . V_58 = 0 ;
}
}
void
F_32 ( struct V_31 * V_32 , int V_4 )
{
struct V_6 * V_7 ;
struct V_33 * V_34 ;
if ( F_28 ( V_4 < 0 || V_4 >= V_32 -> V_35 ) )
return;
V_34 = & V_32 -> V_37 [ V_4 ] ;
if ( ! V_34 -> V_21 )
return;
if ( V_34 -> V_56 )
V_34 -> V_56 -> V_59 = 0 ;
F_23 ( V_34 ) ;
if ( V_34 -> V_53 ) {
if ( V_1 . V_21 <= 0 )
return;
F_33 ( V_32 , V_34 -> V_54 ) ;
F_29 ( V_32 , V_4 ) ;
if ( F_25 ( V_32 , V_34 -> V_54 ,
V_32 -> V_43 ) < 0 ) {
V_1 . V_21 -- ;
V_34 -> V_21 = 0 ;
F_10 ( V_34 -> V_56 ) ;
V_34 -> V_56 = NULL ;
F_10 ( V_34 -> V_50 ) ;
V_34 -> V_50 = NULL ;
}
return;
}
V_7 = F_16 ( V_4 ) ;
if ( V_7 == NULL )
return;
if ( V_7 -> V_19 . V_60 ) {
V_7 -> V_19 . V_60 ( & V_34 -> V_40 ) ;
} else {
struct V_61 V_62 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
F_34 ( V_32 , & V_62 , V_34 -> V_40 . V_55 . V_63 ,
V_34 -> V_40 . V_55 . V_42 ) ;
V_62 . type = V_64 ;
F_35 ( V_32 , & V_62 , 0 , 0 ) ;
}
F_19 ( & V_7 -> V_2 ) ;
}
int
F_36 ( struct V_31 * V_32 , int V_4 , int V_65 ,
const char T_2 * V_66 , int V_67 , int V_68 )
{
struct V_6 * V_7 ;
int V_69 ;
if ( V_4 < 0 || V_4 >= V_32 -> V_35 )
return - V_70 ;
if ( F_30 ( V_32 , V_4 ) )
return 0 ;
if ( ( V_7 = F_31 ( V_32 , V_4 ) ) == NULL )
return - V_70 ;
if ( V_7 -> V_19 . V_71 == NULL )
V_69 = - V_70 ;
else
V_69 = V_7 -> V_19 . V_71 ( & V_32 -> V_37 [ V_4 ] . V_40 , V_65 , V_66 , V_67 , V_68 ) ;
F_19 ( & V_7 -> V_2 ) ;
return V_69 ;
}
int
F_37 ( struct V_31 * V_32 , int V_4 )
{
struct V_6 * V_7 ;
V_7 = F_31 ( V_32 , V_4 ) ;
if ( V_7 ) {
F_19 ( & V_7 -> V_2 ) ;
return 1 ;
}
return 0 ;
}
int
F_38 ( struct V_31 * V_32 , int V_4 , unsigned char * V_66 , struct V_61 * V_62 )
{
int V_5 , V_72 ;
unsigned char * V_73 ;
struct V_74 * V_56 ;
if ( ! F_37 ( V_32 , V_4 ) )
return - V_70 ;
V_56 = V_32 -> V_37 [ V_4 ] . V_56 ;
if ( V_56 == NULL ) {
V_56 = F_5 ( sizeof( * V_56 ) , V_11 ) ;
if ( V_56 == NULL )
return - V_12 ;
V_32 -> V_37 [ V_4 ] . V_56 = V_56 ;
}
V_72 = 0 ;
V_73 = V_56 -> V_66 + V_56 -> V_59 ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( V_66 [ V_5 ] == 0xff ) {
V_72 = 1 ;
break;
}
V_73 [ V_5 ] = V_66 [ V_5 ] ;
V_56 -> V_59 ++ ;
if ( V_56 -> V_59 >= V_75 ) {
V_56 -> V_59 = 0 ;
V_56 -> V_76 = 1 ;
break;
}
}
if ( V_56 -> V_59 && V_72 ) {
if ( V_56 -> V_76 ) {
V_56 -> V_76 = 0 ;
V_56 -> V_59 = 0 ;
return - V_30 ;
}
V_62 -> V_10 = V_77 ;
if ( F_39 ( V_32 , V_4 , V_62 ) )
return - V_30 ;
V_62 -> V_78 . V_79 . V_59 = V_56 -> V_59 ;
V_62 -> V_78 . V_79 . V_80 = V_56 -> V_66 ;
V_56 -> V_59 = 0 ;
return 0 ;
}
return - V_30 ;
}
int
F_39 ( struct V_31 * V_32 , int V_4 , struct V_61 * V_62 )
{
if ( ! F_37 ( V_32 , V_4 ) )
return - V_30 ;
F_34 ( V_32 , V_62 , V_32 -> V_37 [ V_4 ] . V_40 . V_55 . V_63 ,
V_32 -> V_37 [ V_4 ] . V_40 . V_55 . V_42 ) ;
return 0 ;
}
int
F_40 ( struct V_31 * V_32 , int V_4 , unsigned int V_81 , unsigned long V_55 )
{
struct V_6 * V_7 ;
int V_69 ;
if ( F_30 ( V_32 , V_4 ) )
return - V_70 ;
if ( ( V_7 = F_31 ( V_32 , V_4 ) ) == NULL )
return - V_70 ;
if ( V_7 -> V_19 . V_82 == NULL )
V_69 = - V_70 ;
else
V_69 = V_7 -> V_19 . V_82 ( & V_32 -> V_37 [ V_4 ] . V_40 , V_81 , V_55 ) ;
F_19 ( & V_7 -> V_2 ) ;
return V_69 ;
}
int
F_41 ( struct V_31 * V_32 , int V_4 , unsigned char * V_78 , struct V_61 * V_62 )
{
if ( ! F_37 ( V_32 , V_4 ) || F_30 ( V_32 , V_4 ) )
return - V_70 ;
V_62 -> type = V_83 ;
memcpy ( V_62 -> V_78 . V_84 . V_85 , V_78 , 8 ) ;
return F_39 ( V_32 , V_4 , V_62 ) ;
}
int
F_42 ( struct V_31 * V_32 , int V_4 , struct V_86 * V_87 )
{
struct V_6 * V_7 ;
if ( V_4 < 0 || V_4 >= V_32 -> V_35 )
return - V_70 ;
if ( V_32 -> V_37 [ V_4 ] . V_53 ) {
struct V_88 V_89 ;
F_43 ( V_32 , V_32 -> V_37 [ V_4 ] . V_54 , & V_89 ) ;
V_87 -> V_14 = V_90 ;
V_87 -> V_15 = 0 ;
V_87 -> V_17 = 16 ;
V_87 -> V_91 = V_4 ;
F_7 ( V_87 -> V_22 , V_89 . V_22 , sizeof( V_87 -> V_22 ) ) ;
} else {
if ( ( V_7 = F_31 ( V_32 , V_4 ) ) == NULL )
return - V_70 ;
V_87 -> V_14 = V_7 -> V_14 ;
V_87 -> V_15 = V_7 -> V_15 ;
V_87 -> V_17 = V_7 -> V_17 ;
V_87 -> V_91 = V_4 ;
F_7 ( V_87 -> V_22 , V_7 -> V_22 , sizeof( V_87 -> V_22 ) ) ;
F_19 ( & V_7 -> V_2 ) ;
}
return 0 ;
}
void
F_44 ( struct V_92 * V_66 )
{
int V_5 ;
struct V_6 * V_7 ;
F_45 ( V_66 , L_5 , V_24 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
F_45 ( V_66 , L_6 , V_5 ) ;
V_7 = F_16 ( V_5 ) ;
if ( V_7 == NULL ) {
F_45 ( V_66 , L_7 ) ;
continue;
}
F_45 ( V_66 , L_8 , V_7 -> V_22 ) ;
F_45 ( V_66 , L_9 ,
V_7 -> V_14 , V_7 -> V_15 ,
V_7 -> V_17 ) ;
F_45 ( V_66 , L_10 ,
F_46 ( ( long ) V_7 -> V_19 . V_82 ) ,
F_46 ( ( long ) V_7 -> V_19 . V_71 ) ) ;
F_19 ( & V_7 -> V_2 ) ;
}
}
