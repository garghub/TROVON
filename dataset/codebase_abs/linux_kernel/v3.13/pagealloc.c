static int F_1 ( struct V_1 * V_2 , T_1 V_3 , struct V_4 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * * V_11 = & V_7 -> V_10 ;
struct V_10 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_13 * V_15 ;
int V_16 ;
while ( * V_11 ) {
V_12 = * V_11 ;
V_15 = F_2 ( V_12 , struct V_13 , V_10 ) ;
if ( V_15 -> V_3 < V_3 )
V_11 = & V_12 -> V_17 ;
else if ( V_15 -> V_3 > V_3 )
V_11 = & V_12 -> V_18 ;
else
return - V_19 ;
}
V_14 = F_3 ( sizeof( * V_14 ) , V_20 ) ;
if ( ! V_14 )
return - V_21 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_4 = V_4 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_22 = V_23 ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ )
F_4 ( V_16 , & V_14 -> V_24 ) ;
F_5 ( & V_14 -> V_10 , V_12 , V_11 ) ;
F_6 ( & V_14 -> V_10 , V_7 ) ;
F_7 ( & V_14 -> V_25 , & V_2 -> V_8 . V_26 ) ;
return 0 ;
}
static struct V_13 * F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * V_27 = V_7 -> V_10 ;
struct V_13 * V_28 = NULL ;
struct V_13 * V_15 ;
while ( V_27 ) {
V_15 = F_2 ( V_27 , struct V_13 , V_10 ) ;
if ( V_15 -> V_3 < V_3 ) {
V_27 = V_27 -> V_17 ;
} else if ( V_15 -> V_3 > V_3 ) {
V_27 = V_27 -> V_18 ;
} else {
V_28 = V_15 ;
break;
}
}
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 * V_5 ,
T_3 * V_29 , int V_30 )
{
struct V_31 V_32 ;
struct V_33 V_34 ;
int V_35 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_32 . V_36 . V_37 = F_10 ( V_38 ) ;
V_32 . V_36 . V_39 = V_30 ? F_10 ( V_40 ) : F_10 ( V_41 ) ;
V_35 = F_11 ( V_2 , & V_32 , sizeof( V_32 ) , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 )
return V_35 ;
if ( V_34 . V_36 . V_42 )
return F_12 ( & V_34 . V_36 ) ;
* V_29 = F_13 ( V_34 . V_43 ) ;
* V_5 = F_14 ( V_34 . V_5 ) ;
return V_35 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_13 * V_44 ;
unsigned V_45 ;
if ( F_16 ( & V_2 -> V_8 . V_26 ) ) {
return - V_21 ;
F_17 ( V_2 , L_1 ) ;
}
V_44 = F_18 ( V_2 -> V_8 . V_26 . V_46 , struct V_13 , V_25 ) ;
V_45 = F_19 ( & V_44 -> V_24 , 8 * sizeof( V_44 -> V_24 ) ) ;
if ( V_45 >= V_23 ) {
F_17 ( V_2 , L_2 ) ;
return - V_47 ;
}
F_20 ( V_45 , & V_44 -> V_24 ) ;
V_44 -> V_22 -- ;
if ( ! V_44 -> V_22 )
F_21 ( & V_44 -> V_25 ) ;
* V_3 = V_44 -> V_3 + V_45 * 4096 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_13 * V_48 ;
int V_45 ;
V_48 = F_8 ( V_2 , V_3 & V_49 ) ;
if ( ! V_48 ) {
F_17 ( V_2 , L_3 ) ;
return;
}
V_45 = ( V_3 & ~ V_49 ) % 4096 ;
V_48 -> V_22 ++ ;
F_4 ( V_45 , & V_48 -> V_24 ) ;
if ( V_48 -> V_22 == V_23 ) {
F_23 ( & V_48 -> V_10 , & V_2 -> V_8 . V_9 ) ;
if ( V_48 -> V_22 != 1 )
F_21 ( & V_48 -> V_25 ) ;
F_24 ( & V_2 -> V_50 -> V_2 , V_3 , V_51 , V_52 ) ;
F_25 ( V_48 -> V_4 ) ;
F_26 ( V_48 ) ;
} else if ( V_48 -> V_22 == 1 ) {
F_7 ( & V_48 -> V_25 , & V_2 -> V_8 . V_26 ) ;
}
}
static int F_27 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_4 * V_4 ;
T_1 V_3 ;
int V_35 ;
V_4 = F_28 ( V_53 ) ;
if ( ! V_4 ) {
F_17 ( V_2 , L_4 ) ;
return - V_21 ;
}
V_3 = F_29 ( & V_2 -> V_50 -> V_2 , V_4 , 0 ,
V_51 , V_52 ) ;
if ( F_30 ( & V_2 -> V_50 -> V_2 , V_3 ) ) {
F_17 ( V_2 , L_5 ) ;
V_35 = - V_21 ;
goto V_54;
}
V_35 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_35 ) {
F_31 ( V_2 , L_6 ) ;
goto V_55;
}
return 0 ;
V_55:
F_24 ( & V_2 -> V_50 -> V_2 , V_3 , V_51 , V_52 ) ;
V_54:
F_25 ( V_4 ) ;
return V_35 ;
}
static int F_32 ( struct V_1 * V_2 , T_2 V_5 , int V_29 ,
int V_56 )
{
struct V_57 * V_32 ;
struct V_58 V_34 ;
struct V_57 * V_59 ;
int V_60 ;
T_1 V_3 ;
int V_35 ;
int V_16 ;
V_60 = sizeof( * V_32 ) + V_29 * sizeof( V_32 -> V_61 [ 0 ] ) ;
V_32 = F_33 ( V_60 ) ;
if ( ! V_32 ) {
F_17 ( V_2 , L_7 , V_60 ) ;
return - V_21 ;
}
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
for ( V_16 = 0 ; V_16 < V_29 ; V_16 ++ ) {
V_62:
V_35 = F_15 ( V_2 , & V_3 ) ;
if ( V_35 ) {
if ( V_35 == - V_21 )
V_35 = F_27 ( V_2 , V_5 ) ;
if ( V_35 )
goto V_63;
goto V_62;
}
V_32 -> V_61 [ V_16 ] = F_34 ( V_3 ) ;
}
V_32 -> V_36 . V_37 = F_10 ( V_64 ) ;
V_32 -> V_36 . V_39 = F_10 ( V_65 ) ;
V_32 -> V_5 = F_10 ( V_5 ) ;
V_32 -> V_66 = F_35 ( V_29 ) ;
V_35 = F_11 ( V_2 , V_32 , V_60 , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 ) {
F_17 ( V_2 , L_8 , V_5 , V_29 , V_35 ) ;
goto V_54;
}
V_2 -> V_8 . V_67 += V_29 ;
if ( V_34 . V_36 . V_42 ) {
V_35 = F_12 ( & V_34 . V_36 ) ;
if ( V_35 ) {
F_17 ( V_2 , L_9 , V_5 , V_29 , V_34 . V_36 . V_42 ) ;
goto V_54;
}
}
F_36 ( V_2 , L_10 , V_35 ) ;
goto V_68;
V_54:
if ( V_56 ) {
V_59 = F_3 ( sizeof( * V_59 ) , V_20 ) ;
if ( ! V_59 ) {
F_17 ( V_2 , L_11 ) ;
goto V_63;
}
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_59 -> V_36 . V_37 = F_10 ( V_64 ) ;
V_59 -> V_36 . V_39 = F_10 ( V_69 ) ;
if ( F_11 ( V_2 , V_59 , sizeof( * V_59 ) , & V_34 , sizeof( V_34 ) ) )
F_17 ( V_2 , L_12 ) ;
F_26 ( V_59 ) ;
}
V_63:
for ( V_16 -- ; V_16 >= 0 ; V_16 -- )
F_22 ( V_2 , F_37 ( V_32 -> V_61 [ V_16 ] ) ) ;
V_68:
F_38 ( V_32 ) ;
return V_35 ;
}
static int F_39 ( struct V_1 * V_2 , T_4 V_5 , int V_29 ,
int * V_70 )
{
struct V_57 V_32 ;
struct V_58 * V_34 ;
int V_71 ;
int V_72 ;
T_1 V_3 ;
int V_35 ;
int V_16 ;
if ( V_70 )
* V_70 = 0 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_72 = sizeof( * V_34 ) + V_29 * sizeof( V_34 -> V_61 [ 0 ] ) ;
V_34 = F_33 ( V_72 ) ;
if ( ! V_34 )
return - V_21 ;
V_32 . V_36 . V_37 = F_10 ( V_64 ) ;
V_32 . V_36 . V_39 = F_10 ( V_73 ) ;
V_32 . V_5 = F_10 ( V_5 ) ;
V_32 . V_66 = F_35 ( V_29 ) ;
F_36 ( V_2 , L_13 , V_29 , V_72 ) ;
V_35 = F_11 ( V_2 , & V_32 , sizeof( V_32 ) , V_34 , V_72 ) ;
if ( V_35 ) {
F_31 ( V_2 , L_14 ) ;
goto V_68;
}
V_2 -> V_8 . V_67 -= V_29 ;
if ( V_34 -> V_36 . V_42 ) {
V_35 = F_12 ( & V_34 -> V_36 ) ;
goto V_68;
}
V_71 = F_13 ( V_34 -> V_66 ) ;
if ( V_70 )
* V_70 = V_71 ;
for ( V_16 = 0 ; V_16 < V_71 ; V_16 ++ ) {
V_3 = F_37 ( V_34 -> V_61 [ V_16 ] ) ;
F_22 ( V_2 , V_3 ) ;
}
V_68:
F_38 ( V_34 ) ;
return V_35 ;
}
static void F_40 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = F_41 ( V_75 , struct V_76 , V_75 ) ;
struct V_1 * V_2 = V_77 -> V_2 ;
int V_35 = 0 ;
if ( V_77 -> V_29 < 0 )
V_35 = F_39 ( V_2 , V_77 -> V_5 , - 1 * V_77 -> V_29 , NULL ) ;
else if ( V_77 -> V_29 > 0 )
V_35 = F_32 ( V_2 , V_77 -> V_5 , V_77 -> V_29 , 1 ) ;
if ( V_35 )
F_17 ( V_2 , L_15 , V_77 -> V_29 < 0 ?
L_16 : L_17 , V_35 ) ;
F_26 ( V_77 ) ;
}
void F_42 ( struct V_1 * V_2 , T_2 V_5 ,
T_3 V_29 )
{
struct V_76 * V_77 ;
V_77 = F_3 ( sizeof( * V_77 ) , V_78 ) ;
if ( ! V_77 ) {
F_17 ( V_2 , L_18 ) ;
return;
}
V_77 -> V_2 = V_2 ;
V_77 -> V_5 = V_5 ;
V_77 -> V_29 = V_29 ;
F_43 ( & V_77 -> V_75 , F_40 ) ;
F_44 ( V_2 -> V_8 . V_79 , & V_77 -> V_75 ) ;
}
int F_45 ( struct V_1 * V_2 , int V_30 )
{
T_2 V_80 ( V_5 ) ;
T_3 V_80 ( V_29 ) ;
int V_35 ;
V_35 = F_9 ( V_2 , & V_5 , & V_29 , V_30 ) ;
if ( V_35 )
return V_35 ;
F_36 ( V_2 , L_19 ,
V_29 , V_30 ? L_20 : L_21 , V_5 ) ;
return F_32 ( V_2 , V_5 , V_29 , 0 ) ;
}
static int F_46 ( void )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_85 ;
V_85 = ( sizeof( V_84 -> V_34 ) + V_86 * sizeof( V_82 -> V_87 ) -
sizeof( struct V_58 ) ) /
F_47 ( struct V_58 , V_61 [ 0 ] ) ;
return V_85 ;
}
int F_48 ( struct V_1 * V_2 )
{
unsigned long V_88 = V_89 + F_49 ( V_90 ) ;
struct V_13 * V_48 ;
struct V_10 * V_91 ;
int V_70 = 0 ;
int V_35 ;
do {
V_91 = F_50 ( & V_2 -> V_8 . V_9 ) ;
if ( V_91 ) {
V_48 = F_2 ( V_91 , struct V_13 , V_10 ) ;
V_35 = F_39 ( V_2 , V_48 -> V_5 ,
F_46 () ,
& V_70 ) ;
if ( V_35 ) {
F_17 ( V_2 , L_22 , V_35 ) ;
return V_35 ;
}
if ( V_70 )
V_88 = V_89 + F_49 ( V_90 ) ;
}
if ( F_51 ( V_89 , V_88 ) ) {
F_17 ( V_2 , L_23 ) ;
break;
}
} while ( V_91 );
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 = V_92 ;
F_53 ( & V_2 -> V_8 . V_26 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
}
int F_55 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_79 = F_56 ( L_24 ) ;
if ( ! V_2 -> V_8 . V_79 )
return - V_21 ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 )
{
F_58 ( V_2 -> V_8 . V_79 ) ;
}
