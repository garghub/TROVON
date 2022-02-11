static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_4 = & V_3 -> V_5 . V_2 ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
F_3 ( V_4 , V_2 ) ;
F_3 ( V_6 , V_2 ) ;
V_8 . V_9 ( V_4 ) ;
V_8 . V_9 ( V_6 ) ;
F_4 ( L_1 , F_5 ( V_2 -> V_10 ) ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
F_3 ( V_6 , V_2 ) ;
V_8 . V_11 ( V_6 ) ;
F_4 ( L_2 , F_5 ( V_2 -> V_10 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
F_3 ( V_6 , V_2 ) ;
if ( ! V_8 . V_12 ( V_6 ) )
return 0 ;
return 1 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_13 = & V_3 -> V_14 . V_2 ;
F_3 ( V_13 , V_2 ) ;
return V_15 . V_16 ( V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_13 = & V_3 -> V_14 . V_2 ;
F_3 ( V_13 , V_2 ) ;
return V_15 . V_18 ( V_13 , V_17 ) ;
}
static inline unsigned long
F_10 ( unsigned long V_19 , unsigned long V_20 )
{
return V_19 / V_20 + ( ( V_20 > ( 2 * ( V_19 % V_20 ) ) ) ? 0 : 1 ) ;
}
static long F_11 ( struct V_1 * V_2 , unsigned long V_20 ,
unsigned long * V_21 )
{
unsigned long div ;
div = F_10 ( * V_21 , V_20 ) ;
if ( F_12 ( V_2 -> V_10 ) & V_22 ) {
* V_21 = V_20 * div ;
return V_20 ;
}
return * V_21 / div ;
}
unsigned long F_13 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_23 = & V_3 -> V_24 . V_2 ;
struct V_1 * V_25 = & V_3 -> V_26 . V_2 ;
unsigned long V_27 ;
F_3 ( V_23 , V_2 ) ;
F_3 ( V_25 , V_2 ) ;
V_27 = V_28 . V_29 ( V_23 , V_19 ) ;
return V_28 . V_29 ( V_25 , V_27 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_20 ,
unsigned long V_19 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_23 = & V_3 -> V_24 . V_2 ;
struct V_1 * V_25 = & V_3 -> V_26 . V_2 ;
unsigned long div = 0 ;
int V_30 = 0 ;
F_3 ( V_23 , V_2 ) ;
F_3 ( V_25 , V_2 ) ;
div = F_10 ( V_19 , V_20 ) ;
if ( div <= 64 ) {
V_28 . V_31 ( V_23 , V_19 , V_19 ) ;
V_30 = V_28 . V_31 ( V_25 , V_20 , V_20 * div ) ;
} else {
V_28 . V_31 ( V_25 , V_19 , V_19 ) ;
V_30 = V_28 . V_31 ( V_23 , V_20 , V_20 * div ) ;
}
return V_30 ;
}
struct V_10 * F_15 ( const char * V_32 ,
const char * * V_33 , T_1 V_34 ,
void T_2 * V_35 , T_3 * V_36 , T_4 V_37 ,
unsigned long V_38 ) {
struct V_3 * V_39 ;
struct V_10 * V_10 ;
struct V_40 V_41 ;
T_4 V_42 ;
void T_2 * V_43 , * V_44 ;
V_39 = F_16 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_39 )
return F_17 ( - V_46 ) ;
V_41 . V_32 = V_32 ;
V_41 . V_47 = & V_48 ;
V_41 . V_49 = V_50 | V_38 ;
V_41 . V_33 = V_33 ;
V_41 . V_34 = V_34 ;
V_43 = V_35 + 0x18 + ( V_37 & ~ 0x3 ) ;
V_42 = ( V_37 % 4 ) * 0x8 ;
V_44 = V_35 + 0x164 + V_37 * 4 ;
V_39 -> V_14 . V_36 = V_36 ;
V_39 -> V_14 . V_51 = F_18 ( 6 ) - 1 ;
V_39 -> V_14 . V_35 = V_43 ;
V_39 -> V_14 . V_52 = V_42 ;
V_39 -> V_14 . V_53 = NULL ;
V_39 -> V_5 . V_36 = V_36 ;
V_39 -> V_5 . V_35 = V_43 ;
V_39 -> V_5 . V_54 = V_42 + 6 ;
V_39 -> V_24 . V_36 = V_36 ;
V_39 -> V_24 . V_35 = V_35 + 0x58 + V_37 * 4 ;
V_39 -> V_24 . V_55 = 10 ;
V_39 -> V_7 . V_36 = V_36 ;
V_39 -> V_7 . V_35 = V_44 ;
V_39 -> V_7 . V_54 = 6 ;
V_39 -> V_26 . V_36 = V_36 ;
V_39 -> V_26 . V_35 = V_44 ;
V_39 -> V_26 . V_55 = 6 ;
V_39 -> V_2 . V_41 = & V_41 ;
V_10 = F_19 ( NULL , & V_39 -> V_2 ) ;
if ( F_20 ( V_10 ) )
F_21 ( V_39 ) ;
else
F_4 ( L_3 ,
F_5 ( V_10 ) ,
F_5 ( F_22 ( V_10 ) ) ,
( unsigned int ) F_23 ( V_10 ) ) ;
return V_10 ;
}
static const char * * T_5 F_24 ( struct V_56 * V_57 ,
int * V_34 )
{
const char * * V_58 ;
int V_59 , V_60 ;
V_59 = F_25 ( V_57 , L_4 , L_5 ) ;
if ( F_26 ( V_59 <= 0 ) )
return NULL ;
V_58 = F_27 ( V_59 , sizeof( const char * ) , V_45 ) ;
if ( ! V_58 )
return NULL ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ )
V_58 [ V_60 ] = F_28 ( V_57 , V_60 ) ;
* V_34 = V_59 ;
return V_58 ;
}
void T_5 F_29 ( struct V_56 * V_57 )
{
struct V_56 * V_61 ;
void T_2 * V_35 ;
struct V_62 * V_63 ;
const char * * V_58 ;
int V_34 , V_60 ;
T_3 * V_64 = NULL ;
unsigned long V_65 = 0 ;
V_61 = F_30 ( V_57 ) ;
if ( ! V_61 )
return;
V_35 = F_31 ( V_61 , 0 ) ;
if ( ! V_35 )
return;
V_58 = F_24 ( V_57 , & V_34 ) ;
if ( ! V_58 )
return;
V_63 = F_16 ( sizeof( * V_63 ) , V_45 ) ;
if ( ! V_63 )
goto V_66;
V_63 -> V_67 = F_32 ( V_57 ,
L_6 ) ;
if ( V_63 -> V_67 <= 0 ) {
F_33 ( L_7 ,
V_68 , V_63 -> V_67 ) ;
goto V_66;
}
V_63 -> V_69 = F_27 ( V_63 -> V_67 , sizeof( struct V_10 * ) ,
V_45 ) ;
if ( ! V_63 -> V_69 )
goto V_66;
V_64 = F_16 ( sizeof( T_3 ) , V_45 ) ;
if ( ! V_64 )
goto V_66;
for ( V_60 = 0 ; V_60 < V_63 -> V_67 ; V_60 ++ ) {
struct V_10 * V_10 ;
const char * V_70 ;
if ( F_34 ( V_57 , L_6 ,
V_60 , & V_70 ) ) {
break;
}
if ( * V_70 == '\0' )
continue;
V_10 = F_15 ( V_70 , V_58 , V_34 ,
V_35 , V_64 , V_60 , V_65 ) ;
if ( F_20 ( V_10 ) )
goto V_66;
V_63 -> V_69 [ V_60 ] = V_10 ;
}
F_21 ( V_58 ) ;
F_35 ( V_57 , V_71 , V_63 ) ;
return;
V_66:
if ( V_63 )
F_21 ( V_63 -> V_69 ) ;
F_21 ( V_63 ) ;
F_21 ( V_58 ) ;
F_21 ( V_64 ) ;
}
