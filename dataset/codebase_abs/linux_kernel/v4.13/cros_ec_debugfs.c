static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( F_3 ( V_2 ) ,
struct V_3 ,
V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = & V_4 -> V_10 ;
struct V_11 V_12 = {
. V_13 = V_14 + V_7 -> V_15 ,
} ;
struct V_16 * V_17 =
(struct V_16 * ) V_4 -> V_18 -> V_19 ;
T_1 * V_20 = ( T_1 * ) V_4 -> V_18 -> V_19 ;
int V_21 ;
int V_22 ;
int V_23 ;
V_23 = F_4 ( V_7 -> V_24 , & V_12 ) ;
if ( V_23 < 0 ) {
F_5 ( V_7 -> V_25 , L_1 ) ;
goto V_26;
}
if ( V_12 . V_27 != V_28 ) {
F_5 ( V_7 -> V_25 , L_2 ) ;
goto V_26;
}
F_6 ( & V_4 -> V_29 ) ;
V_22 = F_7 ( V_9 -> V_30 , V_9 -> V_31 , V_32 ) ;
while ( 1 ) {
if ( ! V_22 ) {
F_8 ( V_7 -> V_25 ,
L_3 ) ;
break;
}
memset ( V_17 , '\0' , sizeof( * V_17 ) ) ;
V_17 -> V_33 = V_34 ;
V_23 = F_4 ( V_7 -> V_24 , V_4 -> V_18 ) ;
if ( V_23 < 0 ) {
F_5 ( V_7 -> V_25 , L_1 ) ;
break;
}
if ( V_4 -> V_18 -> V_27 != V_28 ) {
F_5 ( V_7 -> V_25 ,
L_4 ) ;
break;
}
if ( V_23 == 0 || V_20 [ 0 ] == '\0' )
break;
V_21 = 0 ;
while ( V_21 < V_23 && V_20 [ V_21 ] != '\0' && V_22 > 0 ) {
V_9 -> V_35 [ V_9 -> V_30 ] = V_20 [ V_21 ] ;
V_9 -> V_30 = F_9 ( V_9 -> V_30 , V_32 , 1 ) ;
V_21 ++ ;
V_22 -- ;
}
F_10 ( & V_4 -> V_36 ) ;
}
F_11 ( & V_4 -> V_29 ) ;
V_26:
F_12 ( & V_4 -> V_5 ,
F_13 ( V_37 * 1000 ) ) ;
}
static int F_14 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
V_39 -> V_40 = V_38 -> V_41 ;
return F_15 ( V_38 , V_39 ) ;
}
static T_2 F_16 ( struct V_39 * V_39 , char T_3 * V_35 ,
T_4 V_42 , T_5 * V_43 )
{
struct V_3 * V_4 = V_39 -> V_40 ;
struct V_8 * V_9 = & V_4 -> V_10 ;
T_2 V_23 ;
F_6 ( & V_4 -> V_29 ) ;
while ( ! F_17 ( V_9 -> V_30 , V_9 -> V_31 , V_32 ) ) {
if ( V_39 -> V_44 & V_45 ) {
V_23 = - V_46 ;
goto error;
}
F_11 ( & V_4 -> V_29 ) ;
V_23 = F_18 ( V_4 -> V_36 ,
F_17 ( V_9 -> V_30 , V_9 -> V_31 , V_32 ) ) ;
if ( V_23 < 0 )
return V_23 ;
F_6 ( & V_4 -> V_29 ) ;
}
V_23 = F_19 ( T_4 , F_20 ( V_9 -> V_30 , V_9 -> V_31 , V_32 ) ,
V_42 ) ;
if ( F_21 ( V_35 , V_9 -> V_35 + V_9 -> V_31 , V_23 ) ) {
V_23 = - V_47 ;
goto error;
}
V_9 -> V_31 = F_9 ( V_9 -> V_31 , V_32 , V_23 ) ;
error:
F_11 ( & V_4 -> V_29 ) ;
return V_23 ;
}
static unsigned int F_22 ( struct V_39 * V_39 ,
T_6 * V_48 )
{
struct V_3 * V_4 = V_39 -> V_40 ;
unsigned int V_49 = 0 ;
F_23 ( V_39 , & V_4 -> V_36 , V_48 ) ;
F_6 ( & V_4 -> V_29 ) ;
if ( F_17 ( V_4 -> V_10 . V_30 ,
V_4 -> V_10 . V_31 ,
V_32 ) )
V_49 |= V_50 | V_51 ;
F_11 ( & V_4 -> V_29 ) ;
return V_49 ;
}
static int F_24 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_23 ;
struct V_11 * V_56 ;
V_56 = F_26 ( sizeof( * V_56 ) + F_27 ( sizeof( * V_53 ) , sizeof( * V_55 ) ) ,
V_57 ) ;
if ( ! V_56 )
return 0 ;
V_56 -> V_13 = V_58 + V_7 -> V_15 ;
V_56 -> V_59 = sizeof( * V_53 ) ;
V_56 -> V_60 = sizeof( * V_55 ) ;
V_53 = (struct V_52 * ) V_56 -> V_19 ;
V_53 -> V_61 = V_62 ;
V_55 = (struct V_54 * ) V_56 -> V_19 ;
V_23 = F_4 ( V_7 -> V_24 , V_56 ) >= 0 &&
V_56 -> V_27 == V_28 &&
( V_55 -> V_63 & F_28 ( 1 ) ) ;
F_29 ( V_56 ) ;
return V_23 ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
char * V_35 ;
int V_64 ;
int V_65 ;
if ( ! F_25 ( V_7 ) ) {
F_31 ( V_7 -> V_25 ,
L_5 ) ;
return 0 ;
}
V_35 = F_32 ( V_7 -> V_25 , V_32 , V_57 ) ;
if ( ! V_35 )
return - V_66 ;
V_64 = sizeof( struct V_16 ) ;
V_65 = V_7 -> V_24 -> V_67 ;
V_4 -> V_18 = F_32 ( V_7 -> V_25 ,
sizeof( * V_4 -> V_18 ) +
F_27 ( V_64 , V_65 ) , V_57 ) ;
if ( ! V_4 -> V_18 )
return - V_66 ;
V_4 -> V_18 -> V_68 = 1 ;
V_4 -> V_18 -> V_13 = V_62 + V_7 -> V_15 ;
V_4 -> V_18 -> V_59 = V_64 ;
V_4 -> V_18 -> V_60 = V_65 ;
V_4 -> V_10 . V_35 = V_35 ;
V_4 -> V_10 . V_30 = 0 ;
V_4 -> V_10 . V_31 = 0 ;
F_33 ( & V_4 -> V_29 ) ;
F_34 ( & V_4 -> V_36 ) ;
if ( ! F_35 ( L_6 ,
V_69 | V_70 ,
V_4 -> V_71 ,
V_4 ,
& V_72 ) )
return - V_66 ;
F_36 ( & V_4 -> V_5 ,
F_1 ) ;
F_12 ( & V_4 -> V_5 , 0 ) ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
if ( V_4 -> V_10 . V_35 ) {
F_38 ( & V_4 -> V_5 ) ;
F_39 ( & V_4 -> V_29 ) ;
}
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_73 * V_24 = V_4 -> V_7 -> V_24 ;
int V_23 ;
struct V_11 * V_56 ;
int V_60 ;
V_60 = V_24 -> V_67 ;
V_56 = F_32 ( V_4 -> V_7 -> V_25 ,
sizeof( * V_56 ) + V_60 , V_57 ) ;
if ( ! V_56 )
return - V_66 ;
V_56 -> V_13 = V_74 ;
V_56 -> V_60 = V_60 ;
V_23 = F_4 ( V_24 , V_56 ) ;
if ( V_23 < 0 ) {
F_31 ( V_4 -> V_7 -> V_25 , L_7 ) ;
V_23 = 0 ;
goto free;
}
if ( V_23 == 0 )
goto free;
V_4 -> V_75 . V_19 = V_56 -> V_19 ;
V_4 -> V_75 . V_76 = V_23 ;
if ( ! F_41 ( L_8 ,
V_69 | V_70 ,
V_4 -> V_71 ,
& V_4 -> V_75 ) ) {
V_23 = - V_66 ;
goto free;
}
return 0 ;
free:
F_42 ( V_4 -> V_7 -> V_25 , V_56 ) ;
return V_23 ;
}
int F_43 ( struct V_6 * V_7 )
{
struct V_77 * V_78 = F_44 ( V_7 -> V_25 ) ;
const char * V_79 = V_78 -> V_80 ;
struct V_3 * V_4 ;
int V_23 ;
V_4 = F_32 ( V_7 -> V_25 , sizeof( * V_4 ) , V_57 ) ;
if ( ! V_4 )
return - V_66 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_71 = F_45 ( V_79 , NULL ) ;
if ( ! V_4 -> V_71 )
return - V_66 ;
V_23 = F_40 ( V_4 ) ;
if ( V_23 )
goto V_81;
V_23 = F_30 ( V_4 ) ;
if ( V_23 )
goto V_81;
V_7 -> V_4 = V_4 ;
return 0 ;
V_81:
F_46 ( V_4 -> V_71 ) ;
return V_23 ;
}
void F_47 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_4 )
return;
F_46 ( V_7 -> V_4 -> V_71 ) ;
F_37 ( V_7 -> V_4 ) ;
}
