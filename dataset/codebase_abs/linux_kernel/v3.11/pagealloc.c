static int F_1 ( struct V_1 * V_2 , T_1 V_3 , struct V_4 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * * V_11 = & V_7 -> V_10 ;
struct V_10 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_13 * V_15 ;
while ( * V_11 ) {
V_12 = * V_11 ;
V_15 = F_2 ( V_12 , struct V_13 , V_10 ) ;
if ( V_15 -> V_3 < V_3 )
V_11 = & V_12 -> V_16 ;
else if ( V_15 -> V_3 > V_3 )
V_11 = & V_12 -> V_17 ;
else
return - V_18 ;
}
V_14 = F_3 ( sizeof( * V_14 ) , V_19 ) ;
if ( ! V_14 )
return - V_20 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_4 = V_4 ;
V_14 -> V_5 = V_5 ;
F_4 ( & V_14 -> V_10 , V_12 , V_11 ) ;
F_5 ( & V_14 -> V_10 , V_7 ) ;
return 0 ;
}
static struct V_4 * F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * V_21 = V_7 -> V_10 ;
struct V_4 * V_22 = NULL ;
struct V_13 * V_15 ;
while ( V_21 ) {
V_15 = F_2 ( V_21 , struct V_13 , V_10 ) ;
if ( V_15 -> V_3 < V_3 ) {
V_21 = V_21 -> V_16 ;
} else if ( V_15 -> V_3 > V_3 ) {
V_21 = V_21 -> V_17 ;
} else {
F_7 ( & V_15 -> V_10 , V_7 ) ;
V_22 = V_15 -> V_4 ;
F_8 ( V_15 ) ;
break;
}
}
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 * V_5 ,
T_3 * V_23 , int V_24 )
{
struct V_25 V_26 ;
struct V_27 V_28 ;
int V_29 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_26 . V_30 . V_31 = F_10 ( V_32 ) ;
V_26 . V_30 . V_33 = V_24 ? F_10 ( V_34 ) : F_10 ( V_35 ) ;
V_29 = F_11 ( V_2 , & V_26 , sizeof( V_26 ) , & V_28 , sizeof( V_28 ) ) ;
if ( V_29 )
return V_29 ;
if ( V_28 . V_30 . V_36 )
return F_12 ( & V_28 . V_30 ) ;
* V_23 = F_13 ( V_28 . V_37 ) ;
* V_5 = F_14 ( V_28 . V_5 ) ;
return V_29 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_5 , int V_23 ,
int V_38 )
{
struct V_39 * V_26 ;
struct V_40 V_28 ;
struct V_4 * V_4 ;
int V_41 ;
T_1 V_3 ;
int V_29 ;
int V_42 ;
V_41 = sizeof( * V_26 ) + V_23 * sizeof( V_26 -> V_43 [ 0 ] ) ;
V_26 = F_16 ( V_41 ) ;
if ( ! V_26 ) {
F_17 ( V_2 , L_1 , V_41 ) ;
return - V_20 ;
}
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
for ( V_42 = 0 ; V_42 < V_23 ; V_42 ++ ) {
V_4 = F_18 ( V_44 ) ;
if ( ! V_4 ) {
V_29 = - V_20 ;
F_17 ( V_2 , L_2 ) ;
goto V_45;
}
V_3 = F_19 ( & V_2 -> V_46 -> V_2 , V_4 , 0 ,
V_47 , V_48 ) ;
if ( F_20 ( & V_2 -> V_46 -> V_2 , V_3 ) ) {
F_17 ( V_2 , L_3 ) ;
F_21 ( V_4 ) ;
V_29 = - V_20 ;
goto V_45;
}
V_29 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_29 ) {
F_22 ( V_2 , L_4 ) ;
F_23 ( & V_2 -> V_46 -> V_2 , V_3 , V_47 , V_48 ) ;
F_21 ( V_4 ) ;
V_29 = - V_20 ;
goto V_45;
}
V_26 -> V_43 [ V_42 ] = F_24 ( V_3 ) ;
}
V_26 -> V_30 . V_31 = F_10 ( V_49 ) ;
V_26 -> V_30 . V_33 = F_10 ( V_50 ) ;
V_26 -> V_5 = F_10 ( V_5 ) ;
V_26 -> V_51 = F_25 ( V_23 ) ;
V_29 = F_11 ( V_2 , V_26 , V_41 , & V_28 , sizeof( V_28 ) ) ;
F_26 ( V_2 , L_5 , V_29 ) ;
if ( V_29 ) {
F_17 ( V_2 , L_6 , V_5 , V_23 , V_29 ) ;
goto V_45;
}
V_2 -> V_8 . V_52 += V_23 ;
if ( V_28 . V_30 . V_36 ) {
V_29 = F_12 ( & V_28 . V_30 ) ;
if ( V_29 ) {
F_17 ( V_2 , L_7 , V_5 , V_23 , V_28 . V_30 . V_36 ) ;
goto V_45;
}
}
F_26 ( V_2 , L_5 , V_29 ) ;
goto V_53;
V_45:
if ( V_38 ) {
memset ( V_26 , 0 , V_41 ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_26 -> V_30 . V_31 = F_10 ( V_49 ) ;
V_26 -> V_30 . V_33 = F_10 ( V_54 ) ;
if ( F_11 ( V_2 , V_26 , sizeof( * V_26 ) , & V_28 , sizeof( V_28 ) ) )
F_17 ( V_2 , L_8 ) ;
}
for ( V_42 -- ; V_42 >= 0 ; V_42 -- ) {
V_3 = F_27 ( V_26 -> V_43 [ V_42 ] ) ;
V_4 = F_6 ( V_2 , V_3 ) ;
if ( ! V_4 ) {
F_22 ( V_2 , L_9 ,
V_3 ) ;
continue;
}
F_23 ( & V_2 -> V_46 -> V_2 , V_3 , V_47 , V_48 ) ;
F_21 ( V_4 ) ;
}
V_53:
F_28 ( V_26 ) ;
return V_29 ;
}
static int F_29 ( struct V_1 * V_2 , T_4 V_5 , int V_23 ,
int * V_55 )
{
struct V_39 V_26 ;
struct V_40 * V_28 ;
struct V_4 * V_4 ;
int V_56 ;
int V_57 ;
T_1 V_3 ;
int V_29 ;
int V_42 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_57 = sizeof( * V_28 ) + V_23 * sizeof( V_28 -> V_43 [ 0 ] ) ;
V_28 = F_16 ( V_57 ) ;
if ( ! V_28 )
return - V_20 ;
V_26 . V_30 . V_31 = F_10 ( V_49 ) ;
V_26 . V_30 . V_33 = F_10 ( V_58 ) ;
V_26 . V_5 = F_10 ( V_5 ) ;
V_26 . V_51 = F_25 ( V_23 ) ;
F_26 ( V_2 , L_10 , V_23 , V_57 ) ;
V_29 = F_11 ( V_2 , & V_26 , sizeof( V_26 ) , V_28 , V_57 ) ;
if ( V_29 ) {
F_22 ( V_2 , L_11 ) ;
goto V_53;
}
V_2 -> V_8 . V_52 -= V_23 ;
if ( V_28 -> V_30 . V_36 ) {
V_29 = F_12 ( & V_28 -> V_30 ) ;
goto V_53;
}
V_56 = F_13 ( V_28 -> V_51 ) ;
if ( V_55 )
* V_55 = V_56 ;
for ( V_42 = 0 ; V_42 < V_56 ; V_42 ++ ) {
V_3 = F_27 ( V_28 -> V_43 [ V_42 ] ) ;
V_4 = F_6 ( V_2 , V_3 ) ;
if ( ! V_4 ) {
F_17 ( V_2 , L_12 , V_3 ) ;
} else {
F_23 ( & V_2 -> V_46 -> V_2 , V_3 , V_47 , V_48 ) ;
F_21 ( V_4 ) ;
}
}
V_53:
F_28 ( V_28 ) ;
return V_29 ;
}
static void F_30 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_31 ( V_60 , struct V_61 , V_60 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
int V_29 = 0 ;
if ( V_62 -> V_23 < 0 )
V_29 = F_29 ( V_2 , V_62 -> V_5 , - 1 * V_62 -> V_23 , NULL ) ;
else if ( V_62 -> V_23 > 0 )
V_29 = F_15 ( V_2 , V_62 -> V_5 , V_62 -> V_23 , 1 ) ;
if ( V_29 )
F_17 ( V_2 , L_13 , V_62 -> V_23 < 0 ?
L_14 : L_15 , V_29 ) ;
F_8 ( V_62 ) ;
}
void F_32 ( struct V_1 * V_2 , T_2 V_5 ,
T_3 V_23 )
{
struct V_61 * V_62 ;
V_62 = F_33 ( sizeof( * V_62 ) , V_63 ) ;
if ( ! V_62 ) {
F_17 ( V_2 , L_16 ) ;
return;
}
V_62 -> V_2 = V_2 ;
V_62 -> V_5 = V_5 ;
V_62 -> V_23 = V_23 ;
F_34 ( & V_62 -> V_60 , F_30 ) ;
F_35 ( V_2 -> V_8 . V_64 , & V_62 -> V_60 ) ;
}
int F_36 ( struct V_1 * V_2 , int V_24 )
{
T_2 V_65 ( V_5 ) ;
T_3 V_65 ( V_23 ) ;
int V_29 ;
V_29 = F_9 ( V_2 , & V_5 , & V_23 , V_24 ) ;
if ( V_29 )
return V_29 ;
F_26 ( V_2 , L_17 ,
V_23 , V_24 ? L_18 : L_19 , V_5 ) ;
return F_15 ( V_2 , V_5 , V_23 , 0 ) ;
}
static int F_37 ( void )
{
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int V_70 ;
V_70 = ( sizeof( V_69 -> V_26 ) + sizeof( V_67 -> V_71 ) -
sizeof( struct V_40 ) ) / 8 ;
return V_70 ;
}
int F_38 ( struct V_1 * V_2 )
{
unsigned long V_72 = V_73 + F_39 ( 5000 ) ;
struct V_13 * V_74 ;
struct V_10 * V_75 ;
int V_29 ;
do {
V_75 = F_40 ( & V_2 -> V_8 . V_9 ) ;
if ( V_75 ) {
V_74 = F_2 ( V_75 , struct V_13 , V_10 ) ;
V_29 = F_29 ( V_2 , V_74 -> V_5 , F_37 () , NULL ) ;
if ( V_29 ) {
F_17 ( V_2 , L_20 , V_29 ) ;
return V_29 ;
}
}
if ( F_41 ( V_73 , V_72 ) ) {
F_17 ( V_2 , L_21 ) ;
break;
}
} while ( V_75 );
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 = V_76 ;
}
void F_43 ( struct V_1 * V_2 )
{
}
int F_44 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_64 = F_45 ( L_22 ) ;
if ( ! V_2 -> V_8 . V_64 )
return - V_20 ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_8 . V_64 ) ;
}
