static int F_1 ( struct V_1 * V_1 )
{
if ( F_2 ( V_1 ) -> V_2 )
return F_2 ( V_1 ) -> V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int free , V_12 ;
V_12 = F_4 ( V_1 -> V_13 ) -> V_14 -
V_15 -
F_2 ( V_1 ) -> V_16 -
sizeof( struct V_6 ) ;
if ( ! F_5 ( V_1 , V_17 ) )
return F_6 ( V_12 -
F_7 ( strlen ( V_18 ) ) -
V_19 - sizeof( V_20 ) ) ;
V_11 = F_8 ( V_5 ) ;
V_7 = F_9 ( V_1 , V_11 ) ;
V_9 = F_10 ( V_7 ) ;
for (; ! F_11 ( V_9 ) ; V_9 = F_12 ( V_9 ) ) {
if ( ! V_9 -> V_21 && V_9 -> V_22 ) {
T_1 V_23 = F_13 ( V_9 -> V_24 ) ;
if ( V_23 < V_12 )
V_12 = V_23 ;
}
}
free = V_12 -
( ( void * ) V_9 - ( void * ) F_10 ( V_7 ) ) - sizeof( V_20 ) ;
if ( F_2 ( V_1 ) -> V_2 ) {
V_9 = (struct V_8 * )
( ( void * ) V_11 + F_2 ( V_1 ) -> V_2 ) ;
free += F_6 ( F_14 ( V_9 -> V_22 ) ) ;
goto V_25;
}
free -= F_7 ( strlen ( V_18 ) ) ;
if ( free > V_19 )
free = F_6 ( free - V_19 ) ;
else
free = 0 ;
V_25:
return free ;
}
int F_15 ( struct V_1 * V_1 )
{
int error , V_26 ;
struct V_4 V_5 ;
if ( F_2 ( V_1 ) -> V_16 == 0 )
return 0 ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error ) {
F_17 ( V_1 , V_27 , __LINE__ , 0 ,
L_1 ,
V_1 -> V_28 ) ;
return 0 ;
}
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
V_26 = F_3 ( V_1 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
if ( ! V_26 )
return 0 ;
return V_26 + V_31 ;
}
int F_21 ( struct V_1 * V_1 )
{
return F_22 ( V_1 , V_32 ) &&
F_2 ( V_1 ) -> V_2 ;
}
int F_23 ( struct V_1 * V_1 )
{
struct V_33 V_34 = {
. V_35 = { . V_36 = - V_37 , } ,
} ;
struct V_38 V_39 = {
. V_40 = V_41 ,
. V_42 = V_18 ,
} ;
int error ;
if ( F_2 ( V_1 ) -> V_16 == 0 )
return 0 ;
error = F_16 ( V_1 , & V_34 . V_5 ) ;
if ( error )
return error ;
error = V_33 ( V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
if ( ! V_34 . V_35 . V_36 ) {
F_2 ( V_1 ) -> V_2 = ( V_43 ) ( ( void * ) V_34 . V_35 . V_44 -
( void * ) F_8 ( & V_34 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_31 +
F_14 ( V_34 . V_35 . V_44 -> V_22 ) ;
F_24 ( V_1 , V_45 ) ;
}
V_25:
F_20 ( V_34 . V_5 . V_30 ) ;
return error ;
}
static int F_25 ( struct V_1 * V_1 , void * V_46 ,
unsigned int V_47 ,
struct V_4 * V_5 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_48 = 0 ;
struct V_10 * V_11 ;
if ( ! V_47 )
return 0 ;
F_26 ( V_47 > F_2 ( V_1 ) -> V_3 ) ;
V_48 = V_47 < V_31 ?
V_47 : V_31 ;
V_11 = F_8 ( V_5 ) ;
memcpy ( V_46 , ( void * ) ( V_11 -> V_49 ) , V_48 ) ;
V_47 -= V_48 ;
V_46 += V_48 ;
if ( ! V_47 )
goto V_25;
V_7 = F_9 ( V_1 , V_11 ) ;
V_9 = (struct V_8 * ) ( ( void * ) V_11 +
F_2 ( V_1 ) -> V_2 ) ;
V_47 = F_27 (unsigned int, len,
(unsigned int)le32_to_cpu(entry->e_value_size)) ;
memcpy ( V_46 ,
( void * ) F_10 ( V_7 ) + F_13 ( V_9 -> V_24 ) , V_47 ) ;
V_48 += V_47 ;
V_25:
return V_48 ;
}
static void F_28 ( struct V_1 * V_1 , struct V_4 * V_5 ,
void * V_46 , T_2 V_50 , unsigned int V_47 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_10 * V_11 ;
int V_48 = 0 ;
F_26 ( ! F_2 ( V_1 ) -> V_2 ) ;
F_26 ( V_50 + V_47 > F_2 ( V_1 ) -> V_3 ) ;
V_11 = F_8 ( V_5 ) ;
V_46 += V_50 ;
if ( V_50 < V_31 ) {
V_48 = V_50 + V_47 > V_31 ?
V_31 - V_50 : V_47 ;
memcpy ( ( void * ) V_11 -> V_49 + V_50 , V_46 , V_48 ) ;
V_47 -= V_48 ;
V_46 += V_48 ;
V_50 += V_48 ;
}
if ( ! V_47 )
return;
V_50 -= V_31 ;
V_7 = F_9 ( V_1 , V_11 ) ;
V_9 = (struct V_8 * ) ( ( void * ) V_11 +
F_2 ( V_1 ) -> V_2 ) ;
memcpy ( ( void * ) F_10 ( V_7 ) + F_13 ( V_9 -> V_24 ) + V_50 ,
V_46 , V_47 ) ;
}
static int F_29 ( T_3 * V_51 ,
struct V_1 * V_1 , unsigned V_47 )
{
int error ;
void * V_52 = NULL ;
struct V_33 V_34 = {
. V_35 = { . V_36 = - V_37 , } ,
} ;
struct V_38 V_39 = {
. V_40 = V_41 ,
. V_42 = V_18 ,
} ;
error = F_16 ( V_1 , & V_34 . V_5 ) ;
if ( error )
return error ;
F_30 ( V_34 . V_5 . V_30 , L_2 ) ;
error = F_31 ( V_51 , V_34 . V_5 . V_30 ) ;
if ( error )
goto V_25;
if ( V_47 > V_31 ) {
V_52 = V_53 ;
V_47 -= V_31 ;
} else {
V_52 = L_3 ;
V_47 = 0 ;
}
V_39 . V_52 = V_52 ;
V_39 . V_54 = V_47 ;
error = V_33 ( V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
F_26 ( ! V_34 . V_35 . V_36 ) ;
error = F_32 ( V_51 , V_1 , & V_39 , & V_34 ) ;
if ( error ) {
if ( error == - V_55 )
F_33 ( V_1 ,
V_45 ) ;
goto V_25;
}
memset ( ( void * ) F_8 ( & V_34 . V_5 ) -> V_49 ,
0 , V_31 ) ;
F_2 ( V_1 ) -> V_2 = ( V_43 ) ( ( void * ) V_34 . V_35 . V_44 -
( void * ) F_8 ( & V_34 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_47 + V_31 ;
F_34 ( V_1 , V_56 ) ;
F_35 ( V_1 , V_32 ) ;
F_36 ( V_34 . V_5 . V_30 ) ;
error = F_37 ( V_51 , V_1 , & V_34 . V_5 ) ;
V_25:
F_20 ( V_34 . V_5 . V_30 ) ;
return error ;
}
static int F_38 ( T_3 * V_51 , struct V_1 * V_1 ,
unsigned int V_47 )
{
int error ;
void * V_52 = NULL ;
struct V_33 V_34 = {
. V_35 = { . V_36 = - V_37 , } ,
} ;
struct V_38 V_39 = {
. V_40 = V_41 ,
. V_42 = V_18 ,
} ;
if ( V_47 <= F_2 ( V_1 ) -> V_3 )
return 0 ;
error = F_16 ( V_1 , & V_34 . V_5 ) ;
if ( error )
return error ;
error = V_33 ( V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
F_26 ( V_34 . V_35 . V_36 ) ;
V_47 -= V_31 ;
V_52 = F_39 ( V_47 , V_57 ) ;
if ( ! V_52 )
goto V_25;
error = F_40 ( V_1 , V_39 . V_40 , V_39 . V_42 ,
V_52 , V_47 ) ;
if ( error == - V_37 )
goto V_25;
F_30 ( V_34 . V_5 . V_30 , L_2 ) ;
error = F_31 ( V_51 , V_34 . V_5 . V_30 ) ;
if ( error )
goto V_25;
V_39 . V_52 = V_52 ;
V_39 . V_54 = V_47 ;
error = F_32 ( V_51 , V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
F_2 ( V_1 ) -> V_2 = ( V_43 ) ( ( void * ) V_34 . V_35 . V_44 -
( void * ) F_8 ( & V_34 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_31 +
F_14 ( V_34 . V_35 . V_44 -> V_22 ) ;
F_24 ( V_1 , V_45 ) ;
F_36 ( V_34 . V_5 . V_30 ) ;
error = F_37 ( V_51 , V_1 , & V_34 . V_5 ) ;
V_25:
F_41 ( V_52 ) ;
F_20 ( V_34 . V_5 . V_30 ) ;
return error ;
}
static int F_42 ( T_3 * V_51 , struct V_1 * V_1 ,
unsigned int V_47 )
{
int V_58 , V_59 ;
struct V_60 * V_61 = F_2 ( V_1 ) ;
if ( ! F_5 ( V_1 , V_45 ) )
return - V_55 ;
V_59 = F_15 ( V_1 ) ;
if ( V_59 < V_47 )
return - V_55 ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_61 -> V_2 )
V_58 = F_38 ( V_51 , V_1 , V_47 ) ;
else
V_58 = F_29 ( V_51 , V_1 , V_47 ) ;
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_58 ;
}
static int F_45 ( T_3 * V_51 ,
struct V_1 * V_1 )
{
struct V_60 * V_61 = F_2 ( V_1 ) ;
struct V_33 V_34 = {
. V_35 = { . V_36 = 0 , } ,
} ;
struct V_38 V_39 = {
. V_40 = V_41 ,
. V_42 = V_18 ,
. V_52 = NULL ,
. V_54 = 0 ,
} ;
int error ;
if ( ! V_61 -> V_2 )
return 0 ;
error = F_16 ( V_1 , & V_34 . V_5 ) ;
if ( error )
return error ;
error = V_33 ( V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
F_30 ( V_34 . V_5 . V_30 , L_2 ) ;
error = F_31 ( V_51 , V_34 . V_5 . V_30 ) ;
if ( error )
goto V_25;
error = F_32 ( V_51 , V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
memset ( ( void * ) F_8 ( & V_34 . V_5 ) -> V_49 ,
0 , V_31 ) ;
if ( F_46 ( V_1 -> V_13 ,
V_62 ) ) {
if ( F_47 ( V_1 -> V_63 ) ||
F_48 ( V_1 -> V_63 ) || F_49 ( V_1 -> V_63 ) ) {
F_35 ( V_1 , V_56 ) ;
F_50 ( V_51 , V_1 ) ;
}
}
F_34 ( V_1 , V_32 ) ;
F_36 ( V_34 . V_5 . V_30 ) ;
error = F_37 ( V_51 , V_1 , & V_34 . V_5 ) ;
F_2 ( V_1 ) -> V_2 = 0 ;
F_2 ( V_1 ) -> V_3 = 0 ;
F_33 ( V_1 , V_45 ) ;
V_25:
F_20 ( V_34 . V_5 . V_30 ) ;
if ( error == - V_37 )
error = 0 ;
return error ;
}
static int F_51 ( struct V_1 * V_1 , struct V_64 * V_64 )
{
void * V_65 ;
int V_58 = 0 ;
T_1 V_47 ;
struct V_4 V_5 ;
F_26 ( ! F_52 ( V_64 ) ) ;
F_26 ( ! F_21 ( V_1 ) ) ;
F_26 ( V_64 -> V_66 ) ;
if ( ! F_2 ( V_1 ) -> V_2 ) {
F_53 ( V_1 -> V_13 , L_4 ,
V_1 -> V_28 ) ;
goto V_25;
}
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
goto V_25;
V_47 = F_27 ( T_1 , F_1 ( V_1 ) , F_54 ( V_1 ) ) ;
V_65 = F_55 ( V_64 ) ;
V_58 = F_25 ( V_1 , V_65 , V_47 , & V_5 ) ;
F_56 ( V_64 ) ;
F_57 ( V_65 ) ;
F_58 ( V_64 , V_47 , V_67 ) ;
F_59 ( V_64 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_58 ;
}
int F_60 ( struct V_1 * V_1 , struct V_64 * V_64 )
{
int V_58 = 0 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return - V_68 ;
}
if ( ! V_64 -> V_66 )
V_58 = F_51 ( V_1 , V_64 ) ;
else if ( ! F_61 ( V_64 ) ) {
F_58 ( V_64 , 0 , V_67 ) ;
F_59 ( V_64 ) ;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_62 ( V_64 ) ;
return V_58 >= 0 ? 0 : V_58 ;
}
static int F_63 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
unsigned V_71 )
{
int V_58 , V_72 ;
T_3 * V_51 = NULL ;
int V_73 = 0 , V_74 = 0 ;
struct V_64 * V_64 = NULL ;
unsigned V_75 , V_76 ;
struct V_4 V_5 ;
if ( ! F_21 ( V_1 ) ) {
F_33 ( V_1 , V_45 ) ;
return 0 ;
}
V_72 = F_64 ( V_1 ) ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_77:
V_51 = F_65 ( V_1 , V_78 , V_72 ) ;
if ( F_66 ( V_51 ) ) {
V_58 = F_67 ( V_51 ) ;
V_51 = NULL ;
goto V_25;
}
V_71 |= V_79 ;
V_64 = F_68 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_80 ;
goto V_25;
}
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
V_74 = 1 ;
if ( ! F_21 ( V_1 ) ) {
V_58 = 0 ;
goto V_25;
}
V_75 = 0 ;
V_76 = F_1 ( V_1 ) ;
if ( ! F_61 ( V_64 ) ) {
V_58 = F_51 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_25;
}
V_58 = F_45 ( V_51 , V_1 ) ;
if ( V_58 )
goto V_25;
if ( F_69 ( V_1 ) )
V_58 = F_70 ( V_64 , V_75 , V_76 , V_81 ) ;
else
V_58 = F_70 ( V_64 , V_75 , V_76 , V_82 ) ;
if ( ! V_58 && F_71 ( V_1 ) ) {
V_58 = F_72 ( V_51 , F_73 ( V_64 ) ,
V_75 , V_76 , NULL ,
V_83 ) ;
}
if ( V_58 ) {
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
F_75 ( V_51 , V_1 ) ;
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
V_74 = 0 ;
F_76 ( V_51 ) ;
V_51 = NULL ;
F_77 ( V_1 ) ;
if ( V_1 -> V_84 )
F_78 ( NULL , V_1 ) ;
}
if ( V_58 == - V_55 && F_79 ( V_1 -> V_13 , & V_73 ) )
goto V_77;
F_80 ( V_64 , V_75 , V_76 ) ;
V_25:
if ( V_64 ) {
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
}
if ( V_74 )
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_51 )
F_76 ( V_51 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_81 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
T_2 V_50 , unsigned V_47 ,
unsigned V_71 ,
struct V_64 * * V_85 )
{
int V_58 ;
T_3 * V_51 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
if ( V_50 + V_47 > F_15 ( V_1 ) )
goto V_86;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_51 = F_65 ( V_1 , V_87 , 1 ) ;
if ( F_66 ( V_51 ) ) {
V_58 = F_67 ( V_51 ) ;
V_51 = NULL ;
goto V_25;
}
V_58 = F_42 ( V_51 , V_1 , V_50 + V_47 ) ;
if ( V_58 && V_58 != - V_55 )
goto V_25;
if ( V_58 == - V_55 ) {
F_76 ( V_51 ) ;
F_20 ( V_5 . V_30 ) ;
goto V_86;
}
V_71 |= V_79 ;
V_64 = F_68 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_80 ;
goto V_25;
}
* V_85 = V_64 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
V_58 = 0 ;
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
goto V_88;
}
if ( ! F_61 ( V_64 ) ) {
V_58 = F_51 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_88;
}
V_58 = 1 ;
V_51 = NULL ;
V_88:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
if ( V_51 )
F_76 ( V_51 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
V_86:
return F_63 ( V_70 ,
V_1 , V_71 ) ;
}
int F_82 ( struct V_1 * V_1 , T_2 V_50 , unsigned V_47 ,
unsigned V_89 , struct V_64 * V_64 )
{
int V_58 ;
void * V_65 ;
struct V_4 V_5 ;
if ( F_83 ( V_89 < V_47 ) ) {
if ( ! F_61 ( V_64 ) ) {
V_89 = 0 ;
goto V_25;
}
}
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 ) {
F_84 ( V_1 -> V_13 , V_58 ) ;
V_89 = 0 ;
goto V_25;
}
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
F_26 ( ! F_21 ( V_1 ) ) ;
V_65 = F_55 ( V_64 ) ;
F_28 ( V_1 , & V_5 , V_65 , V_50 , V_47 ) ;
F_57 ( V_65 ) ;
F_59 ( V_64 ) ;
F_85 ( V_64 ) ;
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_89 ;
}
struct V_90 *
F_86 ( struct V_1 * V_1 ,
unsigned V_47 ,
struct V_64 * V_64 )
{
int V_58 ;
void * V_65 ;
struct V_4 V_5 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 ) {
F_84 ( V_1 -> V_13 , V_58 ) ;
return NULL ;
}
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
V_65 = F_55 ( V_64 ) ;
F_28 ( V_1 , & V_5 , V_65 , 0 , V_47 ) ;
F_57 ( V_65 ) ;
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_5 . V_30 ;
}
static int F_87 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
unsigned V_71 ,
void * * V_91 )
{
int V_58 = 0 , V_92 ;
struct V_64 * V_64 ;
V_64 = F_68 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 )
return - V_80 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_33 ( V_1 , V_45 ) ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
if ( ! F_61 ( V_64 ) ) {
V_58 = F_51 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_25;
}
V_58 = F_70 ( V_64 , 0 , V_92 ,
V_93 ) ;
if ( V_58 ) {
F_77 ( V_1 ) ;
goto V_25;
}
F_88 ( V_64 ) ;
F_59 ( V_64 ) ;
F_33 ( V_1 , V_45 ) ;
* V_91 = ( void * ) V_94 ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_64 ) {
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
}
return V_58 ;
}
int F_89 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
T_2 V_50 , unsigned V_47 ,
unsigned V_71 ,
struct V_64 * * V_85 ,
void * * V_91 )
{
int V_58 , V_92 ;
T_3 * V_51 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
int V_73 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_95:
V_51 = F_65 ( V_1 , V_87 , 1 ) ;
if ( F_66 ( V_51 ) ) {
V_58 = F_67 ( V_51 ) ;
goto V_25;
}
V_92 = F_15 ( V_1 ) ;
V_58 = - V_55 ;
if ( V_92 >= V_50 + V_47 ) {
V_58 = F_42 ( V_51 , V_1 , V_50 + V_47 ) ;
if ( V_58 && V_58 != - V_55 )
goto V_96;
}
if ( V_58 == - V_55 ) {
V_58 = F_87 ( V_70 ,
V_1 ,
V_71 ,
V_91 ) ;
F_76 ( V_51 ) ;
if ( V_58 == - V_55 &&
F_79 ( V_1 -> V_13 , & V_73 ) )
goto V_95;
goto V_25;
}
V_71 |= V_79 ;
V_64 = F_68 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_80 ;
goto V_96;
}
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
V_58 = 0 ;
goto V_97;
}
if ( ! F_61 ( V_64 ) ) {
V_58 = F_51 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_97;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_85 = V_64 ;
F_20 ( V_5 . V_30 ) ;
return 1 ;
V_97:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
V_96:
F_76 ( V_51 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_90 ( struct V_1 * V_1 , T_2 V_50 ,
unsigned V_47 , unsigned V_89 ,
struct V_64 * V_64 )
{
int V_98 = 0 ;
V_89 = F_82 ( V_1 , V_50 , V_47 , V_89 , V_64 ) ;
if ( V_50 + V_89 > V_1 -> V_99 ) {
F_91 ( V_1 , V_50 + V_89 ) ;
V_98 = 1 ;
}
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
if ( V_98 )
F_92 ( V_1 ) ;
return V_89 ;
}
void F_93 ( struct V_1 * V_100 , struct V_90 * V_30 ,
void * V_101 , int V_92 )
{
int V_102 ;
unsigned short V_103 ;
struct V_104 * V_105 = V_101 ;
void * V_106 = V_101 + V_92 ;
F_94 ( L_5 , V_100 -> V_28 ) ;
V_102 = 0 ;
while ( ( void * ) V_105 < V_106 ) {
V_103 = F_95 ( V_105 -> V_107 , V_92 ) ;
F_94 ( L_6 ,
V_102 , V_103 , V_105 -> V_108 , V_105 -> V_42 ,
V_105 -> V_108 , F_14 ( V_105 -> V_1 ) ) ;
if ( F_96 ( V_100 , NULL , V_105 , V_30 ,
V_101 , V_92 , V_102 ) )
F_97 () ;
V_102 += V_103 ;
V_105 = (struct V_104 * ) ( ( char * ) V_105 + V_103 ) ;
}
}
static int F_98 ( T_3 * V_51 ,
struct V_109 * V_109 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_101 , int V_92 )
{
struct V_1 * V_100 = V_109 -> V_110 -> V_111 ;
const char * V_42 = V_109 -> V_112 . V_42 ;
int V_113 = V_109 -> V_112 . V_47 ;
int V_114 ;
struct V_104 * V_105 ;
V_114 = F_99 ( V_100 , V_1 , V_5 -> V_30 ,
V_101 , V_92 ,
V_42 , V_113 , & V_105 ) ;
if ( V_114 )
return V_114 ;
F_30 ( V_5 -> V_30 , L_2 ) ;
V_114 = F_31 ( V_51 , V_5 -> V_30 ) ;
if ( V_114 )
return V_114 ;
F_100 ( V_1 , V_105 , V_92 , V_42 , V_113 ) ;
F_93 ( V_100 , V_5 -> V_30 , V_101 , V_92 ) ;
V_100 -> V_115 = V_100 -> V_116 = F_101 ( V_100 ) ;
F_102 ( V_100 ) ;
V_100 -> V_117 ++ ;
F_103 ( V_51 , V_100 ) ;
return 1 ;
}
static void * F_104 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
F_26 ( ! F_2 ( V_1 ) -> V_2 ) ;
V_7 = F_9 ( V_1 , F_8 ( V_5 ) ) ;
V_9 = (struct V_8 * ) ( ( void * ) F_8 ( V_5 ) +
F_2 ( V_1 ) -> V_2 ) ;
return ( void * ) F_10 ( V_7 ) + F_13 ( V_9 -> V_24 ) ;
}
static void F_105 ( void * V_118 , int V_119 , int V_120 )
{
struct V_104 * V_105 , * V_121 ;
void * V_122 ;
int V_103 ;
V_105 = (struct V_104 * ) V_118 ;
if ( V_119 ) {
V_122 = V_118 + V_119 ;
do {
V_121 = V_105 ;
V_103 = F_95 ( V_105 -> V_107 , V_119 ) ;
V_118 += V_103 ;
V_105 = (struct V_104 * ) V_118 ;
} while ( V_118 < V_122 );
V_121 -> V_107 = F_106 ( V_103 + V_120 -
V_119 , V_120 ) ;
} else {
V_105 -> V_1 = 0 ;
V_105 -> V_107 = F_106 ( V_120 , V_120 ) ;
}
}
static int F_107 ( T_3 * V_51 , struct V_1 * V_100 ,
struct V_4 * V_5 )
{
int V_58 ;
int V_119 = F_2 ( V_100 ) -> V_3 - V_31 ;
int V_120 = F_3 ( V_100 , V_5 ) ;
if ( V_120 - V_119 <= F_108 ( 1 ) )
return - V_55 ;
V_58 = F_38 ( V_51 , V_100 ,
V_120 + V_31 ) ;
if ( V_58 )
return V_58 ;
F_105 ( F_104 ( V_100 , V_5 ) , V_119 ,
F_2 ( V_100 ) -> V_3 -
V_31 ) ;
V_100 -> V_99 = F_2 ( V_100 ) -> V_123 = F_2 ( V_100 ) -> V_3 ;
return 0 ;
}
static void F_109 ( T_3 * V_51 , struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_124 , int V_92 )
{
F_29 ( V_51 , V_1 , V_92 ) ;
F_28 ( V_1 , V_5 , V_124 , 0 , V_92 ) ;
F_24 ( V_1 , V_45 ) ;
}
static int F_110 ( T_3 * V_51 ,
struct V_1 * V_1 ,
struct V_90 * V_125 ,
void * V_124 ,
int V_92 )
{
int V_114 , V_126 = 0 , V_127 = 0 ;
struct V_104 * V_105 ;
struct V_128 * V_129 ;
void * V_130 = V_125 -> V_131 ;
V_105 = (struct V_104 * ) V_130 ;
V_105 = F_111 ( V_1 , V_105 ,
V_1 -> V_13 -> V_132 , V_126 ,
F_14 ( ( (struct V_104 * ) V_124 ) -> V_1 ) , 1 ) ;
V_127 = ( void * ) V_105 - V_130 ;
memcpy ( ( void * ) V_105 , V_124 + V_133 ,
V_92 - V_133 ) ;
if ( F_112 ( V_1 -> V_13 ,
V_134 ) )
V_126 = sizeof( struct V_128 ) ;
V_1 -> V_99 = V_1 -> V_13 -> V_132 ;
F_91 ( V_1 , V_1 -> V_13 -> V_132 ) ;
F_2 ( V_1 ) -> V_123 = V_1 -> V_13 -> V_132 ;
F_105 ( V_125 -> V_131 ,
V_92 - V_133 + V_127 ,
V_1 -> V_13 -> V_132 - V_126 ) ;
if ( V_126 ) {
V_129 = F_113 ( V_125 -> V_131 ,
V_1 -> V_13 -> V_132 ) ;
F_114 ( V_129 , V_1 -> V_13 -> V_132 ) ;
}
F_115 ( V_125 ) ;
V_114 = F_116 ( V_51 , V_1 , V_125 ) ;
if ( V_114 )
goto V_25;
F_117 ( V_125 ) ;
V_25:
return V_114 ;
}
static int F_118 ( T_3 * V_51 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
int error ;
void * V_124 = NULL ;
struct V_90 * V_135 = NULL ;
struct V_136 V_137 ;
int V_92 ;
V_92 = F_1 ( V_1 ) ;
V_124 = F_119 ( V_92 , V_57 ) ;
if ( ! V_124 ) {
error = - V_80 ;
goto V_25;
}
error = F_25 ( V_1 , V_124 , V_92 , V_5 ) ;
if ( error < 0 )
goto V_25;
error = F_45 ( V_51 , V_1 ) ;
if ( error )
goto V_25;
V_137 . V_138 = 0 ;
V_137 . V_139 = 1 ;
V_137 . V_140 = 0 ;
error = V_136 ( V_51 , V_1 , & V_137 , V_141 ) ;
if ( error < 0 )
goto V_142;
if ( ! ( V_137 . V_140 & V_143 ) ) {
error = - V_144 ;
goto V_142;
}
V_135 = F_120 ( V_1 -> V_13 , V_137 . V_145 ) ;
if ( ! V_135 ) {
error = - V_80 ;
goto V_142;
}
F_121 ( V_135 ) ;
error = F_122 ( V_51 , V_135 ) ;
if ( error ) {
F_123 ( V_135 ) ;
error = - V_144 ;
goto V_142;
}
memset ( V_135 -> V_131 , 0 , V_1 -> V_13 -> V_132 ) ;
if ( ! F_47 ( V_1 -> V_63 ) ) {
memcpy ( V_135 -> V_131 , V_124 , V_92 ) ;
F_115 ( V_135 ) ;
error = F_124 ( V_51 ,
V_1 , V_135 ) ;
} else {
error = F_110 ( V_51 , V_1 , V_135 ,
V_124 , V_92 ) ;
}
F_123 ( V_135 ) ;
V_142:
if ( error )
F_109 ( V_51 , V_1 , V_5 , V_124 , V_92 ) ;
V_25:
F_20 ( V_135 ) ;
F_41 ( V_124 ) ;
return error ;
}
int F_125 ( T_3 * V_51 , struct V_109 * V_109 ,
struct V_1 * V_1 )
{
int V_58 , V_92 ;
void * V_101 ;
struct V_4 V_5 ;
struct V_1 * V_100 = V_109 -> V_110 -> V_111 ;
V_58 = F_16 ( V_100 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_43 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_21 ( V_100 ) )
goto V_25;
V_101 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_133 ;
V_92 = V_31 - V_133 ;
V_58 = F_98 ( V_51 , V_109 , V_1 , & V_5 ,
V_101 , V_92 ) ;
if ( V_58 != - V_55 )
goto V_25;
V_92 = F_2 ( V_100 ) -> V_3 -
V_31 ;
if ( ! V_92 ) {
V_58 = F_107 ( V_51 , V_100 , & V_5 ) ;
if ( V_58 && V_58 != - V_55 )
goto V_25;
V_92 = F_2 ( V_100 ) -> V_3 -
V_31 ;
}
if ( V_92 ) {
V_101 = F_104 ( V_100 , & V_5 ) ;
V_58 = F_98 ( V_51 , V_109 , V_1 , & V_5 ,
V_101 , V_92 ) ;
if ( V_58 != - V_55 )
goto V_25;
}
V_58 = F_118 ( V_51 , V_100 , & V_5 ) ;
V_25:
F_103 ( V_51 , V_100 ) ;
F_44 ( & F_2 ( V_100 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_126 ( struct V_146 * V_147 ,
struct V_1 * V_100 , T_4 V_148 ,
struct V_149 * V_150 ,
V_20 V_151 , V_20 V_152 ,
int * V_153 )
{
int V_114 = 0 , V_154 = 0 ;
unsigned int V_155 ;
int V_50 ;
struct V_104 * V_105 ;
struct V_1 * V_1 = F_127 ( V_147 ) ;
int V_58 , V_92 = 0 ;
struct V_4 V_5 ;
void * V_156 = NULL ;
struct V_104 V_157 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_153 = 0 ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
V_156 = F_119 ( V_92 , V_57 ) ;
if ( ! V_156 ) {
V_58 = - V_80 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_25 ( V_1 , V_156 , V_92 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_50 = 0 ;
V_155 = F_14 ( ( (struct V_104 * ) V_156 ) -> V_1 ) ;
while ( V_50 < V_92 ) {
if ( V_50 == 0 ) {
V_157 . V_1 = F_128 ( V_1 -> V_28 ) ;
V_157 . V_108 = 1 ;
strcpy ( V_157 . V_42 , L_7 ) ;
V_157 . V_107 = F_106 (
F_108 ( V_157 . V_108 ) ,
V_92 ) ;
F_129 ( V_1 -> V_13 , & V_157 , V_158 ) ;
V_105 = & V_157 ;
V_50 = V_159 ;
} else if ( V_50 == V_159 ) {
V_157 . V_1 = F_128 ( V_155 ) ;
V_157 . V_108 = 2 ;
strcpy ( V_157 . V_42 , L_8 ) ;
V_157 . V_107 = F_106 (
F_108 ( V_157 . V_108 ) ,
V_92 ) ;
F_129 ( V_1 -> V_13 , & V_157 , V_158 ) ;
V_105 = & V_157 ;
V_50 = V_133 ;
} else {
V_105 = (struct V_104 * ) ( V_156 + V_50 ) ;
V_50 += F_95 ( V_105 -> V_107 , V_92 ) ;
if ( F_96 ( V_1 , V_147 , V_105 ,
V_5 . V_30 , V_156 ,
V_92 , V_50 ) ) {
V_58 = V_154 ;
goto V_25;
}
}
F_130 ( V_105 -> V_42 , V_105 -> V_108 , V_150 ) ;
if ( ( V_150 -> V_160 < V_151 ) ||
( ( V_150 -> V_160 == V_151 ) &&
( V_150 -> V_161 < V_152 ) ) )
continue;
if ( V_105 -> V_1 == 0 )
continue;
V_114 = F_131 ( V_147 ,
V_150 -> V_160 , V_150 -> V_161 , V_105 ) ;
if ( V_114 ) {
V_154 = V_114 ;
goto V_25;
}
V_154 ++ ;
}
V_58 = V_154 ;
V_25:
F_41 ( V_156 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_132 ( struct V_146 * V_146 ,
struct V_162 * V_163 ,
int * V_153 )
{
unsigned int V_102 , V_155 ;
int V_39 ;
struct V_104 * V_105 ;
struct V_164 * V_165 ;
struct V_1 * V_1 = F_127 ( V_146 ) ;
int V_58 , V_92 = 0 ;
struct V_4 V_5 ;
void * V_156 = NULL ;
int V_166 , V_167 , V_168 , V_169 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_153 = 0 ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
V_156 = F_119 ( V_92 , V_57 ) ;
if ( ! V_156 ) {
V_58 = - V_80 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_25 ( V_1 , V_156 , V_92 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_58 = 0 ;
V_165 = V_1 -> V_13 ;
V_155 = F_14 ( ( (struct V_104 * ) V_156 ) -> V_1 ) ;
V_102 = V_163 -> V_50 ;
V_166 = F_108 ( 1 ) ;
V_167 = V_166 + F_108 ( 2 ) ;
V_168 = V_167 - V_133 ;
V_169 = V_168 + V_92 ;
if ( V_146 -> V_170 != V_1 -> V_117 ) {
for ( V_39 = 0 ; V_39 < V_169 && V_39 < V_102 ; ) {
if ( ! V_39 ) {
V_39 = V_166 ;
continue;
} else if ( V_39 == V_166 ) {
V_39 = V_167 ;
continue;
}
V_105 = (struct V_104 * )
( V_156 + V_39 - V_168 ) ;
if ( F_95 ( V_105 -> V_107 , V_169 )
< F_108 ( 1 ) )
break;
V_39 += F_95 ( V_105 -> V_107 ,
V_169 ) ;
}
V_102 = V_39 ;
V_163 -> V_50 = V_102 ;
V_146 -> V_170 = V_1 -> V_117 ;
}
while ( V_163 -> V_50 < V_169 ) {
if ( V_163 -> V_50 == 0 ) {
if ( ! F_133 ( V_163 , L_7 , 1 , V_1 -> V_28 , V_171 ) )
goto V_25;
V_163 -> V_50 = V_166 ;
continue;
}
if ( V_163 -> V_50 == V_166 ) {
if ( ! F_133 ( V_163 , L_8 , 2 , V_155 , V_171 ) )
goto V_25;
V_163 -> V_50 = V_167 ;
continue;
}
V_105 = (struct V_104 * )
( V_156 + V_163 -> V_50 - V_168 ) ;
if ( F_96 ( V_1 , V_146 , V_105 , V_5 . V_30 , V_156 ,
V_169 , V_163 -> V_50 ) )
goto V_25;
if ( F_14 ( V_105 -> V_1 ) ) {
if ( ! F_133 ( V_163 , V_105 -> V_42 , V_105 -> V_108 ,
F_14 ( V_105 -> V_1 ) ,
F_134 ( V_165 , V_105 -> V_172 ) ) )
goto V_25;
}
V_163 -> V_50 += F_95 ( V_105 -> V_107 , V_169 ) ;
}
V_25:
F_41 ( V_156 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_90 * F_135 ( struct V_1 * V_1 ,
struct V_104 * * V_173 ,
int * V_174 )
{
struct V_4 V_5 ;
* V_174 = F_16 ( V_1 , & V_5 ) ;
if ( * V_174 )
return NULL ;
* V_173 = (struct V_104 * ) F_8 ( & V_5 ) -> V_49 ;
return V_5 . V_30 ;
}
int F_136 ( T_3 * V_51 , struct V_1 * V_175 ,
struct V_1 * V_1 )
{
int V_58 , V_92 = V_31 ;
struct V_4 V_5 ;
struct V_104 * V_105 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_42 ( V_51 , V_1 , V_92 ) ;
if ( V_58 )
goto V_25;
V_105 = (struct V_104 * ) F_8 ( & V_5 ) -> V_49 ;
V_105 -> V_1 = F_128 ( V_175 -> V_28 ) ;
V_105 = (struct V_104 * ) ( ( void * ) V_105 + V_133 ) ;
V_105 -> V_1 = 0 ;
V_105 -> V_107 = F_106 (
V_92 - V_133 ,
V_92 ) ;
F_137 ( V_1 , 2 ) ;
V_1 -> V_99 = F_2 ( V_1 ) -> V_123 = V_92 ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_90 * F_138 ( struct V_1 * V_100 ,
const struct V_176 * V_112 ,
struct V_104 * * V_177 ,
int * V_153 )
{
int V_58 ;
struct V_4 V_5 ;
void * V_101 ;
int V_92 ;
if ( F_16 ( V_100 , & V_5 ) )
return NULL ;
F_18 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_21 ( V_100 ) ) {
* V_153 = 0 ;
goto V_25;
}
V_101 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_133 ;
V_92 = V_31 - V_133 ;
V_58 = F_139 ( V_5 . V_30 , V_101 , V_92 ,
V_100 , V_112 , 0 , V_177 ) ;
if ( V_58 == 1 )
goto V_178;
if ( V_58 < 0 )
goto V_25;
if ( F_1 ( V_100 ) == V_31 )
goto V_25;
V_101 = F_104 ( V_100 , & V_5 ) ;
V_92 = F_1 ( V_100 ) - V_31 ;
V_58 = F_139 ( V_5 . V_30 , V_101 , V_92 ,
V_100 , V_112 , 0 , V_177 ) ;
if ( V_58 == 1 )
goto V_178;
V_25:
F_20 ( V_5 . V_30 ) ;
V_5 . V_30 = NULL ;
V_178:
F_19 ( & F_2 ( V_100 ) -> V_29 ) ;
return V_5 . V_30 ;
}
int F_140 ( T_3 * V_51 ,
struct V_1 * V_100 ,
struct V_104 * V_179 ,
struct V_90 * V_30 ,
int * V_153 )
{
int V_114 , V_92 ;
struct V_4 V_5 ;
void * V_101 ;
V_114 = F_16 ( V_100 , & V_5 ) ;
if ( V_114 )
return V_114 ;
F_43 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_21 ( V_100 ) ) {
* V_153 = 0 ;
goto V_25;
}
if ( ( void * ) V_179 - ( ( void * ) F_8 ( & V_5 ) -> V_49 ) <
V_31 ) {
V_101 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_133 ;
V_92 = V_31 -
V_133 ;
} else {
V_101 = F_104 ( V_100 , & V_5 ) ;
V_92 = F_1 ( V_100 ) -
V_31 ;
}
F_30 ( V_30 , L_2 ) ;
V_114 = F_31 ( V_51 , V_30 ) ;
if ( V_114 )
goto V_25;
V_114 = F_141 ( V_51 , V_100 , V_179 , V_30 ,
V_101 , V_92 , 0 ) ;
if ( V_114 )
goto V_25;
F_30 ( V_30 , L_9 ) ;
V_114 = F_103 ( V_51 , V_100 ) ;
if ( F_83 ( V_114 ) )
goto V_25;
F_93 ( V_100 , V_5 . V_30 , V_101 , V_92 ) ;
V_25:
F_44 ( & F_2 ( V_100 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
if ( V_114 != - V_180 )
F_84 ( V_100 -> V_13 , V_114 ) ;
return V_114 ;
}
static inline struct V_104 *
F_142 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned int V_102 ,
void * * V_101 ,
int * V_92 )
{
void * V_181 ;
F_26 ( V_102 > F_1 ( V_1 ) ) ;
if ( V_102 < V_31 ) {
V_181 = ( void * ) F_8 ( V_5 ) -> V_49 ;
* V_92 = V_31 ;
} else {
V_181 = F_104 ( V_1 , V_5 ) ;
V_102 -= V_31 ;
* V_92 = F_1 ( V_1 ) -
V_31 ;
}
if ( V_101 )
* V_101 = V_181 ;
return (struct V_104 * ) ( V_181 + V_102 ) ;
}
int F_143 ( struct V_1 * V_100 , int * V_153 )
{
int V_114 , V_92 ;
struct V_4 V_5 ;
void * V_181 ;
unsigned int V_102 ;
struct V_104 * V_105 ;
int V_58 = 1 ;
V_114 = F_16 ( V_100 , & V_5 ) ;
if ( V_114 ) {
F_144 ( V_100 , L_10 ,
V_114 , V_100 -> V_28 ) ;
return 1 ;
}
F_18 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_21 ( V_100 ) ) {
* V_153 = 0 ;
goto V_25;
}
V_105 = (struct V_104 * ) F_8 ( & V_5 ) -> V_49 ;
if ( ! F_14 ( V_105 -> V_1 ) ) {
F_53 ( V_100 -> V_13 ,
L_11 ,
V_100 -> V_28 ) ;
V_58 = 1 ;
goto V_25;
}
V_102 = V_133 ;
while ( V_102 < V_100 -> V_99 ) {
V_105 = F_142 ( V_100 , & V_5 , V_102 ,
& V_181 , & V_92 ) ;
if ( F_96 ( V_100 , NULL , V_105 ,
V_5 . V_30 , V_181 ,
V_92 , V_102 ) ) {
F_53 ( V_100 -> V_13 ,
L_12
L_13
L_14 ,
V_100 -> V_28 , F_14 ( V_105 -> V_1 ) ,
F_13 ( V_105 -> V_107 ) , V_105 -> V_108 ,
V_92 ) ;
V_58 = 1 ;
goto V_25;
}
if ( F_14 ( V_105 -> V_1 ) ) {
V_58 = 0 ;
goto V_25;
}
V_102 += F_95 ( V_105 -> V_107 , V_92 ) ;
}
V_25:
F_19 ( & F_2 ( V_100 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_145 ( T_3 * V_51 , struct V_1 * V_1 )
{
int V_58 ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
V_58 = F_45 ( V_51 , V_1 ) ;
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_58 ;
}
int F_146 ( struct V_1 * V_1 ,
struct V_182 * V_183 ,
int * V_184 )
{
T_5 V_185 = 0 ;
T_5 V_186 ;
V_20 V_71 = V_187 | V_188 ;
int error = 0 ;
struct V_4 V_5 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
* V_184 = 0 ;
goto V_25;
}
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
goto V_25;
V_185 = ( T_5 ) V_5 . V_30 -> V_189 << V_1 -> V_13 -> V_190 ;
V_185 += ( char * ) F_8 ( & V_5 ) - V_5 . V_30 -> V_131 ;
V_185 += F_147 ( struct V_10 , V_49 ) ;
V_186 = F_54 ( V_1 ) ;
if ( V_185 )
error = F_148 ( V_183 , 0 , V_185 ,
V_186 , V_71 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return ( error < 0 ? error : 0 ) ;
}
int F_149 ( T_3 * V_51 ,
struct V_1 * V_1 ,
int V_191 )
{
int error ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_4 V_5 ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
return error ;
V_11 = F_8 ( & V_5 ) ;
V_9 = (struct V_8 * ) ( ( void * ) V_11 +
F_2 ( V_1 ) -> V_2 ) ;
if ( F_7 ( V_9 -> V_192 ) +
F_6 ( F_14 ( V_9 -> V_22 ) ) < V_191 ) {
error = - V_55 ;
goto V_25;
}
error = F_118 ( V_51 , V_1 , & V_5 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return error ;
}
void F_150 ( struct V_1 * V_1 , int * V_184 )
{
T_3 * V_51 ;
int V_92 , V_54 , V_72 ;
T_1 V_99 ;
void * V_52 = NULL ;
struct V_33 V_34 = {
. V_35 = { . V_36 = - V_37 , } ,
} ;
struct V_38 V_39 = {
. V_40 = V_41 ,
. V_42 = V_18 ,
} ;
V_72 = F_64 ( V_1 ) ;
V_51 = F_65 ( V_1 , V_87 , V_72 ) ;
if ( F_66 ( V_51 ) )
return;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
* V_184 = 0 ;
F_76 ( V_51 ) ;
return;
}
if ( F_75 ( V_51 , V_1 ) )
goto V_25;
if ( F_16 ( V_1 , & V_34 . V_5 ) )
goto V_25;
F_43 ( & F_2 ( V_1 ) -> V_193 ) ;
V_99 = V_1 -> V_99 ;
V_92 = F_1 ( V_1 ) ;
F_2 ( V_1 ) -> V_123 = V_99 ;
if ( V_99 < V_92 ) {
if ( V_92 > V_31 ) {
if ( V_33 ( V_1 , & V_39 , & V_34 ) )
goto V_194;
F_26 ( V_34 . V_35 . V_36 ) ;
V_54 = F_14 ( V_34 . V_35 . V_44 -> V_22 ) ;
V_52 = F_119 ( V_54 , V_57 ) ;
if ( ! V_52 )
goto V_194;
if ( F_40 ( V_1 , V_39 . V_40 , V_39 . V_42 ,
V_52 , V_54 ) )
goto V_194;
V_39 . V_52 = V_52 ;
V_39 . V_54 = V_99 > V_31 ?
V_99 - V_31 : 0 ;
if ( F_32 ( V_51 , V_1 , & V_39 , & V_34 ) )
goto V_194;
}
if ( V_99 < V_31 ) {
void * V_195 = ( void * ) F_8 ( & V_34 . V_5 ) -> V_49 ;
memset ( V_195 + V_99 , 0 ,
V_31 - V_99 ) ;
}
F_2 ( V_1 ) -> V_3 = V_99 <
V_31 ?
V_31 : V_99 ;
}
V_194:
F_44 ( & F_2 ( V_1 ) -> V_193 ) ;
V_25:
F_20 ( V_34 . V_5 . V_30 ) ;
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
F_41 ( V_52 ) ;
if ( V_1 -> V_84 )
F_78 ( V_51 , V_1 ) ;
V_1 -> V_115 = V_1 -> V_116 = F_101 ( V_1 ) ;
F_103 ( V_51 , V_1 ) ;
if ( F_151 ( V_1 ) )
F_152 ( V_51 ) ;
F_76 ( V_51 ) ;
return;
}
int F_153 ( struct V_1 * V_1 )
{
int error , V_72 ;
T_3 * V_51 ;
struct V_4 V_5 ;
if ( ! F_21 ( V_1 ) ) {
F_33 ( V_1 , V_45 ) ;
return 0 ;
}
V_72 = F_64 ( V_1 ) ;
V_5 . V_30 = NULL ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
return error ;
V_51 = F_65 ( V_1 , V_78 , V_72 ) ;
if ( F_66 ( V_51 ) ) {
error = F_67 ( V_51 ) ;
goto V_196;
}
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
error = F_118 ( V_51 , V_1 , & V_5 ) ;
F_44 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
F_76 ( V_51 ) ;
V_196:
F_20 ( V_5 . V_30 ) ;
return error ;
}
