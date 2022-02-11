void T_1
F_1 ( void )
{
F_2 ( & V_1 . V_2 ) ;
}
int
F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_4 ) ;
int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = F_5 ( V_6 ) ;
unsigned long V_12 ;
V_9 = F_6 ( sizeof( * V_9 ) , V_13 ) ;
if ( ! V_9 )
return - V_14 ;
V_9 -> V_15 = - 1 ;
V_9 -> V_16 = V_11 -> type ;
V_9 -> V_17 = V_11 -> V_18 ;
V_9 -> V_19 = V_11 -> V_20 ;
V_9 -> V_21 = V_11 -> V_21 ;
V_9 -> V_22 = V_11 -> V_22 ;
V_9 -> V_23 = 0 ;
F_2 ( & V_9 -> V_2 ) ;
F_7 ( V_9 -> V_24 , V_6 -> V_24 , sizeof( V_9 -> V_24 ) ) ;
F_8 ( & V_25 , V_12 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
if ( V_27 [ V_7 ] == NULL )
break;
}
if ( V_7 >= V_26 ) {
if ( V_26 >= V_28 ) {
F_9 ( & V_25 , V_12 ) ;
F_10 ( L_1 ) ;
F_11 ( V_9 ) ;
return - V_14 ;
}
V_26 ++ ;
}
V_9 -> V_15 = V_7 ;
V_27 [ V_7 ] = V_9 ;
F_9 ( & V_25 , V_12 ) ;
V_6 -> V_29 = V_9 ;
#ifdef F_12
if ( V_7 < V_30 )
F_13 ( F_12 , V_7 , V_9 -> V_24 ) ;
#endif
return 0 ;
}
int
F_14 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_4 ) ;
int V_31 ;
struct V_8 * V_9 = V_6 -> V_29 ;
unsigned long V_12 ;
F_8 ( & V_25 , V_12 ) ;
for ( V_31 = 0 ; V_31 < V_26 ; V_31 ++ ) {
if ( V_27 [ V_31 ] == V_9 )
break;
}
if ( V_31 >= V_26 ) {
F_9 ( & V_25 , V_12 ) ;
F_10 ( L_2 ) ;
return - V_32 ;
}
V_27 [ V_31 ] = NULL ;
if ( V_31 == V_26 - 1 ) {
for ( V_31 -- ; V_31 >= 0 ; V_31 -- ) {
if ( V_27 [ V_31 ] )
break;
}
V_26 = V_31 + 1 ;
}
F_9 ( & V_25 , V_12 ) ;
#ifdef F_12
if ( V_9 -> V_15 < V_30 )
F_15 ( F_12 , V_9 -> V_15 ) ;
#endif
F_16 ( & V_9 -> V_2 ) ;
F_11 ( V_9 ) ;
return 0 ;
}
static struct V_8 *
F_17 ( int V_6 )
{
struct V_8 * V_9 ;
unsigned long V_12 ;
F_8 ( & V_25 , V_12 ) ;
V_9 = V_27 [ V_6 ] ;
if ( V_9 )
F_18 ( & V_9 -> V_2 ) ;
F_9 ( & V_25 , V_12 ) ;
return V_9 ;
}
void
F_19 ( struct V_33 * V_34 )
{
int V_7 ;
struct V_8 * V_9 ;
struct V_35 * V_36 ;
V_34 -> V_37 = V_26 ;
V_34 -> V_38 = 0 ;
memset ( V_34 -> V_39 , 0 , sizeof( V_34 -> V_39 ) ) ;
for ( V_7 = 0 ; V_7 < V_34 -> V_37 ; V_7 ++ ) {
V_9 = F_17 ( V_7 ) ;
if ( V_9 == NULL )
continue;
if ( V_9 -> V_21 . V_40 == NULL || V_9 -> V_21 . V_41 == NULL ) {
F_20 ( & V_9 -> V_2 ) ;
continue;
}
V_36 = & V_34 -> V_39 [ V_7 ] ;
V_36 -> V_42 . V_43 = V_34 -> V_44 ;
V_36 -> V_42 . V_45 = V_34 -> V_45 ;
V_36 -> V_42 . V_46 = V_34 -> V_46 ;
if ( V_34 -> V_46 == V_47 )
V_36 -> V_42 . V_48 = V_49 ;
else
V_36 -> V_42 . V_48 = V_50 ;
V_36 -> V_23 = 0 ;
if ( ! F_21 ( V_9 -> V_21 . V_51 ) ) {
F_20 ( & V_9 -> V_2 ) ;
continue;
}
if ( V_9 -> V_21 . V_40 ( & V_36 -> V_42 , V_9 -> V_22 ) < 0 ) {
F_22 ( V_9 -> V_21 . V_51 ) ;
F_20 ( & V_9 -> V_2 ) ;
continue;
}
V_36 -> V_19 = V_9 -> V_19 ;
if ( V_36 -> V_19 > 0 ) {
V_36 -> V_52 = F_23 ( V_36 -> V_19 , sizeof( struct V_53 ) , V_13 ) ;
if ( ! V_36 -> V_52 ) {
V_9 -> V_21 . V_41 ( & V_36 -> V_42 ) ;
F_22 ( V_9 -> V_21 . V_51 ) ;
F_20 ( & V_9 -> V_2 ) ;
continue;
}
F_24 ( V_36 ) ;
}
V_36 -> V_23 ++ ;
V_9 -> V_23 ++ ;
V_34 -> V_38 ++ ;
F_20 ( & V_9 -> V_2 ) ;
}
}
void
F_25 ( struct V_33 * V_34 )
{
int V_7 ;
if ( V_34 -> V_37 >= V_28 )
return;
for ( V_7 = 0 ; V_7 < V_34 -> V_54 ; V_7 ++ ) {
struct V_35 * V_36 ;
V_36 = & V_34 -> V_39 [ V_34 -> V_37 ] ;
if ( F_26 ( V_34 , V_7 , V_34 -> V_45 ) < 0 )
continue;
V_36 -> V_42 . V_43 = V_34 -> V_44 ;
V_36 -> V_42 . V_45 = V_34 -> V_45 ;
V_36 -> V_42 . V_46 = V_34 -> V_46 ;
V_36 -> V_42 . V_22 = V_36 ;
V_36 -> V_55 = 1 ;
V_36 -> V_56 = V_7 ;
V_36 -> V_42 . V_48 = V_50 ;
F_27 ( V_34 , V_7 , & V_36 -> V_42 . V_57 ) ;
V_36 -> V_23 = 1 ;
V_1 . V_23 ++ ;
V_34 -> V_37 ++ ;
if ( V_34 -> V_37 >= V_28 )
break;
}
}
void
F_28 ( struct V_33 * V_34 )
{
int V_7 ;
struct V_8 * V_9 ;
struct V_35 * V_36 ;
if ( F_29 ( V_34 -> V_37 >= V_28 ) )
return;
for ( V_7 = 0 ; V_7 < V_34 -> V_37 ; V_7 ++ ) {
V_36 = & V_34 -> V_39 [ V_7 ] ;
if ( ! V_36 -> V_23 )
continue;
if ( V_36 -> V_55 ) {
if ( V_1 . V_23 > 0 ) {
F_30 ( V_34 , V_36 -> V_56 ) ;
V_1 . V_23 -- ;
}
} else {
V_9 = F_17 ( V_7 ) ;
if ( V_9 == NULL )
continue;
if ( V_9 -> V_23 > 0 ) {
V_9 -> V_21 . V_41 ( & V_36 -> V_42 ) ;
F_22 ( V_9 -> V_21 . V_51 ) ;
V_9 -> V_23 = 0 ;
}
F_20 ( & V_9 -> V_2 ) ;
}
F_11 ( V_36 -> V_58 ) ;
V_36 -> V_58 = NULL ;
F_11 ( V_36 -> V_52 ) ;
V_36 -> V_52 = NULL ;
}
V_34 -> V_38 = 0 ;
V_34 -> V_37 = 0 ;
}
static int
F_31 ( struct V_33 * V_34 , int V_6 )
{
if ( V_6 < 0 || V_6 >= V_34 -> V_37 )
return 0 ;
if ( V_34 -> V_39 [ V_6 ] . V_55 )
return 1 ;
return 0 ;
}
static struct V_8 *
F_32 ( struct V_33 * V_34 , int V_6 )
{
struct V_8 * V_9 ;
if ( V_6 < 0 || V_6 >= V_34 -> V_37 )
return NULL ;
if ( ! V_34 -> V_39 [ V_6 ] . V_23 )
return NULL ;
if ( V_34 -> V_39 [ V_6 ] . V_55 )
return & V_1 ;
if ( ( V_9 = F_17 ( V_6 ) ) == NULL )
return NULL ;
if ( ! V_9 -> V_23 ) {
F_20 ( & V_9 -> V_2 ) ;
return NULL ;
}
return V_9 ;
}
static void
F_24 ( struct V_35 * V_36 )
{
int V_7 ;
if ( V_36 -> V_52 == NULL || ! V_36 -> V_19 )
return;
for ( V_7 = 0 ; V_7 < V_36 -> V_19 ; V_7 ++ ) {
V_36 -> V_52 [ V_7 ] . V_59 = - 1 ;
V_36 -> V_52 [ V_7 ] . V_60 = 0 ;
}
}
void
F_33 ( struct V_33 * V_34 , int V_6 )
{
struct V_8 * V_9 ;
struct V_35 * V_36 ;
if ( F_29 ( V_6 < 0 || V_6 >= V_34 -> V_37 ) )
return;
V_36 = & V_34 -> V_39 [ V_6 ] ;
if ( ! V_36 -> V_23 )
return;
if ( V_36 -> V_58 )
V_36 -> V_58 -> V_61 = 0 ;
F_24 ( V_36 ) ;
if ( V_36 -> V_55 ) {
if ( V_1 . V_23 <= 0 )
return;
F_34 ( V_34 , V_36 -> V_56 ) ;
F_30 ( V_34 , V_6 ) ;
if ( F_26 ( V_34 , V_36 -> V_56 ,
V_34 -> V_45 ) < 0 ) {
V_1 . V_23 -- ;
V_36 -> V_23 = 0 ;
F_11 ( V_36 -> V_58 ) ;
V_36 -> V_58 = NULL ;
F_11 ( V_36 -> V_52 ) ;
V_36 -> V_52 = NULL ;
}
return;
}
V_9 = F_17 ( V_6 ) ;
if ( V_9 == NULL )
return;
if ( V_9 -> V_21 . V_62 ) {
V_9 -> V_21 . V_62 ( & V_36 -> V_42 ) ;
} else {
struct V_63 V_64 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
F_35 ( V_34 , & V_64 , V_36 -> V_42 . V_57 . V_65 ,
V_36 -> V_42 . V_57 . V_44 ) ;
V_64 . type = V_66 ;
F_36 ( V_34 , & V_64 , 0 , 0 ) ;
}
F_20 ( & V_9 -> V_2 ) ;
}
int
F_37 ( struct V_33 * V_34 , int V_6 , int V_67 ,
const char T_2 * V_68 , int V_69 , int V_70 )
{
struct V_8 * V_9 ;
int V_71 ;
if ( V_6 < 0 || V_6 >= V_34 -> V_37 )
return - V_72 ;
if ( F_31 ( V_34 , V_6 ) )
return 0 ;
if ( ( V_9 = F_32 ( V_34 , V_6 ) ) == NULL )
return - V_72 ;
if ( V_9 -> V_21 . V_73 == NULL )
V_71 = - V_72 ;
else
V_71 = V_9 -> V_21 . V_73 ( & V_34 -> V_39 [ V_6 ] . V_42 , V_67 , V_68 , V_69 , V_70 ) ;
F_20 ( & V_9 -> V_2 ) ;
return V_71 ;
}
int
F_38 ( struct V_33 * V_34 , int V_6 )
{
struct V_8 * V_9 ;
V_9 = F_32 ( V_34 , V_6 ) ;
if ( V_9 ) {
F_20 ( & V_9 -> V_2 ) ;
return 1 ;
}
return 0 ;
}
int
F_39 ( struct V_33 * V_34 , int V_6 , unsigned char * V_68 , struct V_63 * V_64 )
{
int V_7 , V_74 ;
unsigned char * V_75 ;
struct V_76 * V_58 ;
if ( ! F_38 ( V_34 , V_6 ) )
return - V_72 ;
V_58 = V_34 -> V_39 [ V_6 ] . V_58 ;
if ( V_58 == NULL ) {
V_58 = F_6 ( sizeof( * V_58 ) , V_13 ) ;
if ( V_58 == NULL )
return - V_14 ;
V_34 -> V_39 [ V_6 ] . V_58 = V_58 ;
}
V_74 = 0 ;
V_75 = V_58 -> V_68 + V_58 -> V_61 ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ ) {
if ( V_68 [ V_7 ] == 0xff ) {
V_74 = 1 ;
break;
}
V_75 [ V_7 ] = V_68 [ V_7 ] ;
V_58 -> V_61 ++ ;
if ( V_58 -> V_61 >= V_77 ) {
V_58 -> V_61 = 0 ;
V_58 -> V_78 = 1 ;
break;
}
}
if ( V_58 -> V_61 && V_74 ) {
if ( V_58 -> V_78 ) {
V_58 -> V_78 = 0 ;
V_58 -> V_61 = 0 ;
return - V_32 ;
}
V_64 -> V_12 = V_79 ;
if ( F_40 ( V_34 , V_6 , V_64 ) )
return - V_32 ;
V_64 -> V_80 . V_81 . V_61 = V_58 -> V_61 ;
V_64 -> V_80 . V_81 . V_82 = V_58 -> V_68 ;
V_58 -> V_61 = 0 ;
return 0 ;
}
return - V_32 ;
}
int
F_40 ( struct V_33 * V_34 , int V_6 , struct V_63 * V_64 )
{
if ( ! F_38 ( V_34 , V_6 ) )
return - V_32 ;
F_35 ( V_34 , V_64 , V_34 -> V_39 [ V_6 ] . V_42 . V_57 . V_65 ,
V_34 -> V_39 [ V_6 ] . V_42 . V_57 . V_44 ) ;
return 0 ;
}
int
F_41 ( struct V_33 * V_34 , int V_6 , unsigned int V_83 , unsigned long V_57 )
{
struct V_8 * V_9 ;
int V_71 ;
if ( F_31 ( V_34 , V_6 ) )
return - V_72 ;
if ( ( V_9 = F_32 ( V_34 , V_6 ) ) == NULL )
return - V_72 ;
if ( V_9 -> V_21 . V_84 == NULL )
V_71 = - V_72 ;
else
V_71 = V_9 -> V_21 . V_84 ( & V_34 -> V_39 [ V_6 ] . V_42 , V_83 , V_57 ) ;
F_20 ( & V_9 -> V_2 ) ;
return V_71 ;
}
int
F_42 ( struct V_33 * V_34 , int V_6 , unsigned char * V_80 , struct V_63 * V_64 )
{
if ( ! F_38 ( V_34 , V_6 ) || F_31 ( V_34 , V_6 ) )
return - V_72 ;
V_64 -> type = V_85 ;
memcpy ( V_64 -> V_80 . V_86 . V_87 , V_80 , 8 ) ;
return F_40 ( V_34 , V_6 , V_64 ) ;
}
int
F_43 ( struct V_33 * V_34 , int V_6 , struct V_88 * V_89 )
{
struct V_8 * V_9 ;
if ( V_6 < 0 || V_6 >= V_34 -> V_37 )
return - V_72 ;
if ( V_34 -> V_39 [ V_6 ] . V_55 ) {
struct V_90 V_91 ;
F_44 ( V_34 , V_34 -> V_39 [ V_6 ] . V_56 , & V_91 ) ;
V_89 -> V_16 = V_92 ;
V_89 -> V_17 = 0 ;
V_89 -> V_19 = 16 ;
V_89 -> V_3 = V_6 ;
F_7 ( V_89 -> V_24 , V_91 . V_24 , sizeof( V_89 -> V_24 ) ) ;
} else {
if ( ( V_9 = F_32 ( V_34 , V_6 ) ) == NULL )
return - V_72 ;
V_89 -> V_16 = V_9 -> V_16 ;
V_89 -> V_17 = V_9 -> V_17 ;
V_89 -> V_19 = V_9 -> V_19 ;
V_89 -> V_3 = V_6 ;
F_7 ( V_89 -> V_24 , V_9 -> V_24 , sizeof( V_89 -> V_24 ) ) ;
F_20 ( & V_9 -> V_2 ) ;
}
return 0 ;
}
void
F_45 ( struct V_93 * V_68 )
{
int V_7 ;
struct V_8 * V_9 ;
F_46 ( V_68 , L_3 , V_26 ) ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
F_46 ( V_68 , L_4 , V_7 ) ;
V_9 = F_17 ( V_7 ) ;
if ( V_9 == NULL ) {
F_46 ( V_68 , L_5 ) ;
continue;
}
F_46 ( V_68 , L_6 , V_9 -> V_24 ) ;
F_46 ( V_68 , L_7 ,
V_9 -> V_16 , V_9 -> V_17 ,
V_9 -> V_19 ) ;
F_46 ( V_68 , L_8 ,
F_47 ( ( long ) V_9 -> V_21 . V_84 ) ,
F_47 ( ( long ) V_9 -> V_21 . V_73 ) ) ;
F_20 ( & V_9 -> V_2 ) ;
}
}
