static void T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_4 = 0 ;
F_2 ( V_2 , V_3 ) ;
V_2 -> V_5 = NULL ;
F_3 ( & V_2 -> V_6 ) ;
}
void T_1 F_4 ( struct V_7 * V_8 )
{
V_8 -> V_9 = NULL ;
}
struct V_1 * F_5 ( struct V_10 * V_10 )
{
unsigned long V_11 = F_6 ( V_10 ) ;
unsigned long V_12 ;
struct V_1 * V_13 ;
V_13 = F_7 ( F_8 ( V_10 ) ) -> V_9 ;
if ( F_9 ( ! V_13 ) )
return NULL ;
V_12 = V_11 - F_7 ( F_8 ( V_10 ) ) -> V_14 ;
return V_13 + V_12 ;
}
struct V_10 * F_10 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
struct V_10 * V_10 ;
T_2 * V_8 ;
V_8 = F_7 ( F_11 ( V_2 ) ) ;
V_11 = V_2 - V_8 -> V_9 + V_8 -> V_14 ;
V_10 = F_12 ( V_11 ) ;
F_13 ( V_2 != F_5 ( V_10 ) ) ;
return V_10 ;
}
static int T_3 F_14 ( int V_15 )
{
struct V_1 * V_13 , * V_2 ;
unsigned long V_16 ;
unsigned long V_17 , V_18 , V_19 ;
V_17 = F_7 ( V_15 ) -> V_14 ;
V_18 = F_7 ( V_15 ) -> V_20 ;
if ( ! V_18 )
return 0 ;
V_16 = sizeof( struct V_1 ) * V_18 ;
V_13 = F_15 ( F_7 ( V_15 ) ,
V_16 , V_21 , F_16 ( V_22 ) ) ;
if ( ! V_13 )
return - V_23 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
V_2 = V_13 + V_19 ;
F_1 ( V_2 , V_15 ) ;
}
F_7 ( V_15 ) -> V_9 = V_13 ;
V_24 += V_16 ;
return 0 ;
}
void T_3 F_17 ( void )
{
int V_15 , V_25 ;
if ( F_18 () )
return;
F_19 (nid) {
V_25 = F_14 ( V_15 ) ;
if ( V_25 )
goto V_25;
}
F_20 ( V_26 L_1 , V_24 ) ;
F_20 ( V_26 L_2
L_3 ) ;
return;
V_25:
F_20 ( V_27 L_4 ) ;
F_20 ( V_27 L_5 ) ;
F_21 ( L_6 ) ;
}
struct V_1 * F_5 ( struct V_10 * V_10 )
{
unsigned long V_11 = F_6 ( V_10 ) ;
struct V_28 * V_29 = F_22 ( V_11 ) ;
if ( ! V_29 -> V_1 )
return NULL ;
return V_29 -> V_1 + V_11 ;
}
struct V_10 * F_10 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_10 * V_10 ;
unsigned long V_30 ;
V_30 = F_11 ( V_2 ) ;
V_29 = F_23 ( V_30 ) ;
V_10 = F_12 ( V_2 - V_29 -> V_1 ) ;
F_13 ( V_2 != F_5 ( V_10 ) ) ;
return V_10 ;
}
static void * T_1 F_24 ( T_4 V_31 , int V_15 )
{
void * V_32 = NULL ;
V_32 = F_25 ( V_15 , V_31 , V_33 | V_34 ) ;
if ( V_32 )
return V_32 ;
if ( F_26 ( V_15 , V_35 ) )
V_32 = F_27 ( V_31 , V_15 ) ;
else
V_32 = F_28 ( V_31 ) ;
return V_32 ;
}
static void F_29 ( void * V_32 )
{
if ( F_30 ( V_32 ) ) {
F_31 ( V_32 ) ;
} else {
struct V_10 * V_10 = F_32 ( V_32 ) ;
T_4 V_16 =
sizeof( struct V_1 ) * V_36 ;
F_33 ( F_34 ( V_10 ) ) ;
F_35 ( V_32 , V_16 ) ;
}
}
static int T_1 F_36 ( unsigned long V_11 , int V_15 )
{
struct V_1 * V_13 , * V_2 ;
struct V_28 * V_29 ;
unsigned long V_16 ;
unsigned long V_30 ;
int V_19 ;
V_30 = F_37 ( V_11 ) ;
V_29 = F_23 ( V_30 ) ;
if ( V_29 -> V_1 )
return 0 ;
V_16 = sizeof( struct V_1 ) * V_36 ;
V_13 = F_24 ( V_16 , V_15 ) ;
F_38 ( V_13 ) ;
if ( ! V_13 ) {
F_20 ( V_37 L_7 ) ;
return - V_23 ;
}
for ( V_19 = 0 ; V_19 < V_36 ; V_19 ++ ) {
V_2 = V_13 + V_19 ;
F_1 ( V_2 , V_30 ) ;
}
V_11 &= V_38 ;
V_29 -> V_1 = V_13 - V_11 ;
V_24 += V_16 ;
return 0 ;
}
void F_39 ( unsigned long V_11 )
{
struct V_28 * V_39 ;
struct V_1 * V_13 ;
V_39 = F_22 ( V_11 ) ;
if ( ! V_39 || ! V_39 -> V_1 )
return;
V_13 = V_39 -> V_1 + V_11 ;
F_29 ( V_13 ) ;
V_39 -> V_1 = NULL ;
}
int T_1 F_40 ( unsigned long V_17 ,
unsigned long V_18 ,
int V_15 )
{
unsigned long V_40 , V_41 , V_11 ;
int V_25 = 0 ;
V_40 = V_17 & ~ ( V_36 - 1 ) ;
V_41 = F_41 ( V_17 + V_18 , V_36 ) ;
if ( V_15 == - 1 ) {
V_15 = F_42 ( V_17 ) ;
F_13 ( ! F_26 ( V_15 , V_42 ) ) ;
}
for ( V_11 = V_40 ; ! V_25 && V_11 < V_41 ; V_11 += V_36 ) {
if ( ! F_43 ( V_11 ) )
continue;
V_25 = F_36 ( V_11 , V_15 ) ;
}
if ( ! V_25 )
return 0 ;
for ( V_11 = V_40 ; V_11 < V_41 ; V_11 += V_36 )
F_39 ( V_11 ) ;
return - V_23 ;
}
int T_1 F_44 ( unsigned long V_17 ,
unsigned long V_18 , int V_15 )
{
unsigned long V_40 , V_41 , V_11 ;
V_40 = V_17 & ~ ( V_36 - 1 ) ;
V_41 = F_41 ( V_17 + V_18 , V_36 ) ;
for ( V_11 = V_40 ; V_11 < V_41 ; V_11 += V_36 )
F_39 ( V_11 ) ;
return 0 ;
}
static int T_1 F_45 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
struct V_47 * V_48 = V_46 ;
int V_49 = 0 ;
switch ( V_45 ) {
case V_50 :
V_49 = F_40 ( V_48 -> V_17 ,
V_48 -> V_18 , V_48 -> V_51 ) ;
break;
case V_52 :
F_44 ( V_48 -> V_17 ,
V_48 -> V_18 , V_48 -> V_51 ) ;
break;
case V_53 :
case V_54 :
break;
case V_55 :
case V_56 :
break;
}
return F_46 ( V_49 ) ;
}
void T_3 F_47 ( void )
{
unsigned long V_11 ;
int V_15 ;
if ( F_18 () )
return;
F_48 (nid, N_HIGH_MEMORY) {
unsigned long V_17 , V_57 ;
V_17 = V_14 ( V_15 ) ;
V_57 = F_49 ( V_15 ) ;
for ( V_11 = V_17 ;
V_11 < V_57 ;
V_11 = F_41 ( V_11 + 1 , V_36 ) ) {
if ( ! F_50 ( V_11 ) )
continue;
if ( F_42 ( V_11 ) != V_15 )
continue;
if ( F_36 ( V_11 , V_15 ) )
goto V_58;
}
}
F_51 ( F_45 , 0 ) ;
F_20 ( V_26 L_1 , V_24 ) ;
F_20 ( V_26 L_8
L_9 ) ;
return;
V_58:
F_20 ( V_27 L_10 ) ;
F_21 ( L_6 ) ;
}
void T_1 F_4 ( struct V_7 * V_8 )
{
return;
}
static int F_52 ( int type )
{
struct V_10 * V_10 ;
struct V_59 * V_60 ;
unsigned long V_61 , V_62 ;
V_60 = & V_59 [ type ] ;
for ( V_61 = 0 ; V_61 < V_60 -> V_63 ; V_61 ++ ) {
V_10 = F_53 ( V_33 | V_64 ) ;
if ( ! V_10 )
goto V_65;
V_60 -> V_66 [ V_61 ] = V_10 ;
}
return 0 ;
V_65:
V_62 = V_61 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ )
F_54 ( V_60 -> V_66 [ V_61 ] ) ;
return - V_23 ;
}
unsigned short F_55 ( T_5 V_67 ,
unsigned short V_68 , unsigned short V_69 )
{
int type = F_56 ( V_67 ) ;
unsigned long V_12 = F_57 ( V_67 ) ;
unsigned long V_61 = V_12 / V_70 ;
unsigned long V_71 = V_12 & V_72 ;
struct V_59 * V_60 ;
struct V_10 * V_73 ;
struct V_74 * V_75 ;
unsigned long V_4 ;
unsigned short V_76 ;
V_60 = & V_59 [ type ] ;
V_73 = V_60 -> V_66 [ V_61 ] ;
V_75 = F_58 ( V_73 ) ;
V_75 += V_71 ;
F_59 ( & V_60 -> V_77 , V_4 ) ;
V_76 = V_75 -> V_3 ;
if ( V_76 == V_68 )
V_75 -> V_3 = V_69 ;
else
V_76 = 0 ;
F_60 ( & V_60 -> V_77 , V_4 ) ;
return V_76 ;
}
unsigned short F_61 ( T_5 V_67 , unsigned short V_3 )
{
int type = F_56 ( V_67 ) ;
unsigned long V_12 = F_57 ( V_67 ) ;
unsigned long V_61 = V_12 / V_70 ;
unsigned long V_71 = V_12 & V_72 ;
struct V_59 * V_60 ;
struct V_10 * V_73 ;
struct V_74 * V_75 ;
unsigned short V_68 ;
unsigned long V_4 ;
V_60 = & V_59 [ type ] ;
V_73 = V_60 -> V_66 [ V_61 ] ;
V_75 = F_58 ( V_73 ) ;
V_75 += V_71 ;
F_59 ( & V_60 -> V_77 , V_4 ) ;
V_68 = V_75 -> V_3 ;
V_75 -> V_3 = V_3 ;
F_60 ( & V_60 -> V_77 , V_4 ) ;
return V_68 ;
}
unsigned short F_62 ( T_5 V_67 )
{
int type = F_56 ( V_67 ) ;
unsigned long V_12 = F_57 ( V_67 ) ;
unsigned long V_61 = V_12 / V_70 ;
unsigned long V_71 = V_12 & V_72 ;
struct V_59 * V_60 ;
struct V_10 * V_73 ;
struct V_74 * V_75 ;
unsigned short V_49 ;
V_60 = & V_59 [ type ] ;
V_73 = V_60 -> V_66 [ V_61 ] ;
V_75 = F_58 ( V_73 ) ;
V_75 += V_71 ;
V_49 = V_75 -> V_3 ;
return V_49 ;
}
int F_63 ( int type , unsigned long V_78 )
{
void * V_79 ;
unsigned long V_80 ;
unsigned long V_63 ;
struct V_59 * V_60 ;
if ( ! V_81 )
return 0 ;
V_63 = F_64 ( V_78 , V_70 ) ;
V_80 = V_63 * sizeof( void * ) ;
V_79 = F_28 ( V_80 ) ;
if ( ! V_79 )
goto V_82;
memset ( V_79 , 0 , V_80 ) ;
V_60 = & V_59 [ type ] ;
F_65 ( & V_83 ) ;
V_60 -> V_63 = V_63 ;
V_60 -> V_66 = V_79 ;
F_66 ( & V_60 -> V_77 ) ;
if ( F_52 ( type ) ) {
V_60 -> V_66 = NULL ;
V_60 -> V_63 = 0 ;
F_67 ( & V_83 ) ;
F_31 ( V_79 ) ;
goto V_82;
}
F_67 ( & V_83 ) ;
return 0 ;
V_82:
F_20 ( V_26 L_11 ) ;
F_20 ( V_26
L_12 ) ;
return - V_23 ;
}
void F_68 ( int type )
{
struct V_10 * * V_66 ;
unsigned long V_84 , V_63 ;
struct V_59 * V_60 ;
if ( ! V_81 )
return;
F_65 ( & V_83 ) ;
V_60 = & V_59 [ type ] ;
V_66 = V_60 -> V_66 ;
V_63 = V_60 -> V_63 ;
V_60 -> V_66 = NULL ;
V_60 -> V_63 = 0 ;
F_67 ( & V_83 ) ;
if ( V_66 ) {
for ( V_84 = 0 ; V_84 < V_63 ; V_84 ++ ) {
struct V_10 * V_10 = V_66 [ V_84 ] ;
if ( V_10 )
F_54 ( V_10 ) ;
}
F_31 ( V_66 ) ;
}
}
