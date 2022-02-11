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
struct V_32 V_33 = {
. V_34 = { . V_35 = - V_36 , } ,
} ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_18 ,
} ;
int error ;
if ( F_2 ( V_1 ) -> V_16 == 0 )
return 0 ;
error = F_16 ( V_1 , & V_33 . V_5 ) ;
if ( error )
return error ;
error = V_32 ( V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
if ( ! V_33 . V_34 . V_35 ) {
F_2 ( V_1 ) -> V_2 = ( V_42 ) ( ( void * ) V_33 . V_34 . V_43 -
( void * ) F_8 ( & V_33 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_31 +
F_14 ( V_33 . V_34 . V_43 -> V_22 ) ;
F_22 ( V_1 , V_44 ) ;
}
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
return error ;
}
static int F_23 ( struct V_1 * V_1 , void * V_45 ,
unsigned int V_46 ,
struct V_4 * V_5 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_47 = 0 ;
struct V_10 * V_11 ;
if ( ! V_46 )
return 0 ;
F_24 ( V_46 > F_2 ( V_1 ) -> V_3 ) ;
V_47 = V_46 < V_31 ?
V_46 : V_31 ;
V_11 = F_8 ( V_5 ) ;
memcpy ( V_45 , ( void * ) ( V_11 -> V_48 ) , V_47 ) ;
V_46 -= V_47 ;
V_45 += V_47 ;
if ( ! V_46 )
goto V_25;
V_7 = F_9 ( V_1 , V_11 ) ;
V_9 = (struct V_8 * ) ( ( void * ) V_11 +
F_2 ( V_1 ) -> V_2 ) ;
V_46 = F_25 (unsigned int, len,
(unsigned int)le32_to_cpu(entry->e_value_size)) ;
memcpy ( V_45 ,
( void * ) F_10 ( V_7 ) + F_13 ( V_9 -> V_24 ) , V_46 ) ;
V_47 += V_46 ;
V_25:
return V_47 ;
}
static void F_26 ( struct V_1 * V_1 , struct V_4 * V_5 ,
void * V_45 , T_2 V_49 , unsigned int V_46 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_10 * V_11 ;
int V_47 = 0 ;
F_24 ( ! F_2 ( V_1 ) -> V_2 ) ;
F_24 ( V_49 + V_46 > F_2 ( V_1 ) -> V_3 ) ;
V_11 = F_8 ( V_5 ) ;
V_45 += V_49 ;
if ( V_49 < V_31 ) {
V_47 = V_49 + V_46 > V_31 ?
V_31 - V_49 : V_46 ;
memcpy ( ( void * ) V_11 -> V_48 + V_49 , V_45 , V_47 ) ;
V_46 -= V_47 ;
V_45 += V_47 ;
V_49 += V_47 ;
}
if ( ! V_46 )
return;
V_49 -= V_31 ;
V_7 = F_9 ( V_1 , V_11 ) ;
V_9 = (struct V_8 * ) ( ( void * ) V_11 +
F_2 ( V_1 ) -> V_2 ) ;
memcpy ( ( void * ) F_10 ( V_7 ) + F_13 ( V_9 -> V_24 ) + V_49 ,
V_45 , V_46 ) ;
}
static int F_27 ( T_3 * V_50 ,
struct V_1 * V_1 , unsigned V_46 )
{
int error ;
void * V_51 = NULL ;
struct V_32 V_33 = {
. V_34 = { . V_35 = - V_36 , } ,
} ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_18 ,
} ;
error = F_16 ( V_1 , & V_33 . V_5 ) ;
if ( error )
return error ;
F_28 ( V_33 . V_5 . V_30 , L_2 ) ;
error = F_29 ( V_50 , V_33 . V_5 . V_30 ) ;
if ( error )
goto V_25;
if ( V_46 > V_31 ) {
V_51 = V_52 ;
V_46 -= V_31 ;
} else {
V_51 = L_3 ;
V_46 = 0 ;
}
V_38 . V_51 = V_51 ;
V_38 . V_53 = V_46 ;
error = V_32 ( V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
F_24 ( ! V_33 . V_34 . V_35 ) ;
error = F_30 ( V_50 , V_1 , & V_38 , & V_33 ) ;
if ( error ) {
if ( error == - V_54 )
F_31 ( V_1 ,
V_44 ) ;
goto V_25;
}
memset ( ( void * ) F_8 ( & V_33 . V_5 ) -> V_48 ,
0 , V_31 ) ;
F_2 ( V_1 ) -> V_2 = ( V_42 ) ( ( void * ) V_33 . V_34 . V_43 -
( void * ) F_8 ( & V_33 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_46 + V_31 ;
F_32 ( V_1 , V_55 ) ;
F_33 ( V_1 , V_56 ) ;
F_34 ( V_33 . V_5 . V_30 ) ;
error = F_35 ( V_50 , V_1 , & V_33 . V_5 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
return error ;
}
static int F_36 ( T_3 * V_50 , struct V_1 * V_1 ,
unsigned int V_46 )
{
int error ;
void * V_51 = NULL ;
struct V_32 V_33 = {
. V_34 = { . V_35 = - V_36 , } ,
} ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_18 ,
} ;
if ( V_46 <= F_2 ( V_1 ) -> V_3 )
return 0 ;
error = F_16 ( V_1 , & V_33 . V_5 ) ;
if ( error )
return error ;
error = V_32 ( V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
F_24 ( V_33 . V_34 . V_35 ) ;
V_46 -= V_31 ;
V_51 = F_37 ( V_46 , V_57 ) ;
if ( ! V_51 )
goto V_25;
error = F_38 ( V_1 , V_38 . V_39 , V_38 . V_41 ,
V_51 , V_46 ) ;
if ( error == - V_36 )
goto V_25;
F_28 ( V_33 . V_5 . V_30 , L_2 ) ;
error = F_29 ( V_50 , V_33 . V_5 . V_30 ) ;
if ( error )
goto V_25;
V_38 . V_51 = V_51 ;
V_38 . V_53 = V_46 ;
error = F_30 ( V_50 , V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
F_2 ( V_1 ) -> V_2 = ( V_42 ) ( ( void * ) V_33 . V_34 . V_43 -
( void * ) F_8 ( & V_33 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_31 +
F_14 ( V_33 . V_34 . V_43 -> V_22 ) ;
F_22 ( V_1 , V_44 ) ;
F_34 ( V_33 . V_5 . V_30 ) ;
error = F_35 ( V_50 , V_1 , & V_33 . V_5 ) ;
V_25:
F_39 ( V_51 ) ;
F_20 ( V_33 . V_5 . V_30 ) ;
return error ;
}
static int F_40 ( T_3 * V_50 , struct V_1 * V_1 ,
unsigned int V_46 )
{
int V_58 , V_59 ;
struct V_60 * V_61 = F_2 ( V_1 ) ;
if ( ! F_5 ( V_1 , V_44 ) )
return - V_54 ;
V_59 = F_15 ( V_1 ) ;
if ( V_59 < V_46 )
return - V_54 ;
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_61 -> V_2 )
V_58 = F_36 ( V_50 , V_1 , V_46 ) ;
else
V_58 = F_27 ( V_50 , V_1 , V_46 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_58 ;
}
static int F_43 ( T_3 * V_50 ,
struct V_1 * V_1 )
{
struct V_60 * V_61 = F_2 ( V_1 ) ;
struct V_32 V_33 = {
. V_34 = { . V_35 = 0 , } ,
} ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_18 ,
. V_51 = NULL ,
. V_53 = 0 ,
} ;
int error ;
if ( ! V_61 -> V_2 )
return 0 ;
error = F_16 ( V_1 , & V_33 . V_5 ) ;
if ( error )
return error ;
error = V_32 ( V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
F_28 ( V_33 . V_5 . V_30 , L_2 ) ;
error = F_29 ( V_50 , V_33 . V_5 . V_30 ) ;
if ( error )
goto V_25;
error = F_30 ( V_50 , V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
memset ( ( void * ) F_8 ( & V_33 . V_5 ) -> V_48 ,
0 , V_31 ) ;
if ( F_44 ( V_1 -> V_13 ,
V_62 ) ) {
if ( F_45 ( V_1 -> V_63 ) ||
F_46 ( V_1 -> V_63 ) || F_47 ( V_1 -> V_63 ) ) {
F_33 ( V_1 , V_55 ) ;
F_48 ( V_50 , V_1 ) ;
}
}
F_32 ( V_1 , V_56 ) ;
F_34 ( V_33 . V_5 . V_30 ) ;
error = F_35 ( V_50 , V_1 , & V_33 . V_5 ) ;
F_2 ( V_1 ) -> V_2 = 0 ;
F_2 ( V_1 ) -> V_3 = 0 ;
F_31 ( V_1 , V_44 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
if ( error == - V_36 )
error = 0 ;
return error ;
}
static int F_49 ( struct V_1 * V_1 , struct V_64 * V_64 )
{
void * V_65 ;
int V_58 = 0 ;
T_1 V_46 ;
struct V_4 V_5 ;
F_24 ( ! F_50 ( V_64 ) ) ;
F_24 ( ! F_51 ( V_1 ) ) ;
F_24 ( V_64 -> V_66 ) ;
if ( ! F_2 ( V_1 ) -> V_2 ) {
F_52 ( V_1 -> V_13 , L_4 ,
V_1 -> V_28 ) ;
goto V_25;
}
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
goto V_25;
V_46 = F_25 ( T_1 , F_1 ( V_1 ) , F_53 ( V_1 ) ) ;
V_65 = F_54 ( V_64 ) ;
V_58 = F_23 ( V_1 , V_65 , V_46 , & V_5 ) ;
F_55 ( V_64 ) ;
F_56 ( V_65 ) ;
F_57 ( V_64 , V_46 , V_67 ) ;
F_58 ( V_64 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_58 ;
}
int F_59 ( struct V_1 * V_1 , struct V_64 * V_64 )
{
int V_58 = 0 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return - V_68 ;
}
if ( ! V_64 -> V_66 )
V_58 = F_49 ( V_1 , V_64 ) ;
else if ( ! F_60 ( V_64 ) ) {
F_57 ( V_64 , 0 , V_67 ) ;
F_58 ( V_64 ) ;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_61 ( V_64 ) ;
return V_58 >= 0 ? 0 : V_58 ;
}
static int F_62 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
unsigned V_71 )
{
int V_58 , V_72 ;
T_3 * V_50 = NULL ;
int V_73 = 0 , V_74 = 0 ;
struct V_64 * V_64 = NULL ;
unsigned V_75 , V_76 ;
struct V_4 V_5 ;
if ( ! F_51 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
return 0 ;
}
V_72 = F_63 ( V_1 ) ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_77:
V_50 = F_64 ( V_1 , V_78 , V_72 ) ;
if ( F_65 ( V_50 ) ) {
V_58 = F_66 ( V_50 ) ;
V_50 = NULL ;
goto V_25;
}
V_71 |= V_79 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_80 ;
goto V_25;
}
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
V_74 = 1 ;
if ( ! F_51 ( V_1 ) ) {
V_58 = 0 ;
goto V_25;
}
V_75 = 0 ;
V_76 = F_1 ( V_1 ) ;
if ( ! F_60 ( V_64 ) ) {
V_58 = F_49 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_25;
}
V_58 = F_43 ( V_50 , V_1 ) ;
if ( V_58 )
goto V_25;
if ( F_68 ( V_1 ) )
V_58 = F_69 ( V_64 , V_75 , V_76 , V_81 ) ;
else
V_58 = F_69 ( V_64 , V_75 , V_76 , V_82 ) ;
if ( ! V_58 && F_70 ( V_1 ) ) {
V_58 = F_71 ( V_50 , F_72 ( V_64 ) ,
V_75 , V_76 , NULL ,
V_83 ) ;
}
if ( V_58 ) {
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
V_64 = NULL ;
F_74 ( V_50 , V_1 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_74 = 0 ;
F_75 ( V_50 ) ;
V_50 = NULL ;
F_76 ( V_1 ) ;
if ( V_1 -> V_84 )
F_77 ( NULL , V_1 ) ;
}
if ( V_58 == - V_54 && F_78 ( V_1 -> V_13 , & V_73 ) )
goto V_77;
if ( V_64 )
F_79 ( V_64 , V_75 , V_76 ) ;
V_25:
if ( V_64 ) {
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
}
if ( V_74 )
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_50 )
F_75 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_80 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
T_2 V_49 , unsigned V_46 ,
unsigned V_71 ,
struct V_64 * * V_85 )
{
int V_58 ;
T_3 * V_50 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
if ( V_49 + V_46 > F_15 ( V_1 ) )
goto V_86;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_50 = F_64 ( V_1 , V_87 , 1 ) ;
if ( F_65 ( V_50 ) ) {
V_58 = F_66 ( V_50 ) ;
V_50 = NULL ;
goto V_25;
}
V_58 = F_40 ( V_50 , V_1 , V_49 + V_46 ) ;
if ( V_58 && V_58 != - V_54 )
goto V_25;
if ( V_58 == - V_54 ) {
F_75 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
goto V_86;
}
V_71 |= V_79 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_80 ;
goto V_25;
}
* V_85 = V_64 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
V_58 = 0 ;
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
goto V_88;
}
if ( ! F_60 ( V_64 ) ) {
V_58 = F_49 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_88;
}
V_58 = 1 ;
V_50 = NULL ;
V_88:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
if ( V_50 )
F_75 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
V_86:
return F_62 ( V_70 ,
V_1 , V_71 ) ;
}
int F_81 ( struct V_1 * V_1 , T_2 V_49 , unsigned V_46 ,
unsigned V_89 , struct V_64 * V_64 )
{
int V_58 ;
void * V_65 ;
struct V_4 V_5 ;
if ( F_82 ( V_89 < V_46 ) ) {
if ( ! F_60 ( V_64 ) ) {
V_89 = 0 ;
goto V_25;
}
}
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 ) {
F_83 ( V_1 -> V_13 , V_58 ) ;
V_89 = 0 ;
goto V_25;
}
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
F_24 ( ! F_51 ( V_1 ) ) ;
V_65 = F_54 ( V_64 ) ;
F_26 ( V_1 , & V_5 , V_65 , V_49 , V_46 ) ;
F_56 ( V_65 ) ;
F_58 ( V_64 ) ;
F_84 ( V_64 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_89 ;
}
struct V_90 *
F_85 ( struct V_1 * V_1 ,
unsigned V_46 ,
struct V_64 * V_64 )
{
int V_58 ;
void * V_65 ;
struct V_4 V_5 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 ) {
F_83 ( V_1 -> V_13 , V_58 ) ;
return NULL ;
}
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
V_65 = F_54 ( V_64 ) ;
F_26 ( V_1 , & V_5 , V_65 , 0 , V_46 ) ;
F_56 ( V_65 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_5 . V_30 ;
}
static int F_86 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
unsigned V_71 ,
void * * V_91 )
{
int V_58 = 0 , V_92 ;
struct V_64 * V_64 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 )
return - V_80 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
if ( ! F_60 ( V_64 ) ) {
V_58 = F_49 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_25;
}
V_58 = F_69 ( V_64 , 0 , V_92 ,
V_93 ) ;
if ( V_58 ) {
F_76 ( V_1 ) ;
goto V_25;
}
F_87 ( V_64 ) ;
F_58 ( V_64 ) ;
F_31 ( V_1 , V_44 ) ;
* V_91 = ( void * ) V_94 ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_64 ) {
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
}
return V_58 ;
}
int F_88 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
T_2 V_49 , unsigned V_46 ,
unsigned V_71 ,
struct V_64 * * V_85 ,
void * * V_91 )
{
int V_58 , V_92 ;
T_3 * V_50 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
int V_73 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_95:
V_50 = F_64 ( V_1 , V_87 , 1 ) ;
if ( F_65 ( V_50 ) ) {
V_58 = F_66 ( V_50 ) ;
goto V_25;
}
V_92 = F_15 ( V_1 ) ;
V_58 = - V_54 ;
if ( V_92 >= V_49 + V_46 ) {
V_58 = F_40 ( V_50 , V_1 , V_49 + V_46 ) ;
if ( V_58 && V_58 != - V_54 )
goto V_96;
}
if ( V_58 == - V_54 ) {
V_58 = F_86 ( V_70 ,
V_1 ,
V_71 ,
V_91 ) ;
F_75 ( V_50 ) ;
if ( V_58 == - V_54 &&
F_78 ( V_1 -> V_13 , & V_73 ) )
goto V_95;
goto V_25;
}
V_71 |= V_79 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_80 ;
goto V_96;
}
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
V_58 = 0 ;
goto V_97;
}
if ( ! F_60 ( V_64 ) ) {
V_58 = F_49 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_97;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_85 = V_64 ;
F_20 ( V_5 . V_30 ) ;
return 1 ;
V_97:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
V_96:
F_75 ( V_50 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_89 ( struct V_1 * V_1 , T_2 V_49 ,
unsigned V_46 , unsigned V_89 ,
struct V_64 * V_64 )
{
int V_98 = 0 ;
V_89 = F_81 ( V_1 , V_49 , V_46 , V_89 , V_64 ) ;
if ( V_49 + V_89 > V_1 -> V_99 ) {
F_90 ( V_1 , V_49 + V_89 ) ;
V_98 = 1 ;
}
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
if ( V_98 )
F_91 ( V_1 ) ;
return V_89 ;
}
void F_92 ( struct V_1 * V_100 , struct V_90 * V_30 ,
void * V_101 , int V_92 )
{
int V_102 ;
unsigned short V_103 ;
struct V_104 * V_105 = V_101 ;
void * V_106 = V_101 + V_92 ;
F_93 ( L_5 , V_100 -> V_28 ) ;
V_102 = 0 ;
while ( ( void * ) V_105 < V_106 ) {
V_103 = F_94 ( V_105 -> V_107 , V_92 ) ;
F_93 ( L_6 ,
V_102 , V_103 , V_105 -> V_108 , V_105 -> V_41 ,
V_105 -> V_108 , F_14 ( V_105 -> V_1 ) ) ;
if ( F_95 ( V_100 , NULL , V_105 , V_30 ,
V_101 , V_92 , V_102 ) )
F_96 () ;
V_102 += V_103 ;
V_105 = (struct V_104 * ) ( ( char * ) V_105 + V_103 ) ;
}
}
static int F_97 ( T_3 * V_50 ,
struct V_109 * V_109 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_101 , int V_92 )
{
struct V_1 * V_100 = V_109 -> V_110 -> V_111 ;
const char * V_41 = V_109 -> V_112 . V_41 ;
int V_113 = V_109 -> V_112 . V_46 ;
int V_114 ;
struct V_104 * V_105 ;
V_114 = F_98 ( V_100 , V_1 , V_5 -> V_30 ,
V_101 , V_92 ,
V_41 , V_113 , & V_105 ) ;
if ( V_114 )
return V_114 ;
F_28 ( V_5 -> V_30 , L_2 ) ;
V_114 = F_29 ( V_50 , V_5 -> V_30 ) ;
if ( V_114 )
return V_114 ;
F_99 ( V_1 , V_105 , V_92 , V_41 , V_113 ) ;
F_92 ( V_100 , V_5 -> V_30 , V_101 , V_92 ) ;
V_100 -> V_115 = V_100 -> V_116 = F_100 ( V_100 ) ;
F_101 ( V_100 ) ;
V_100 -> V_117 ++ ;
F_102 ( V_50 , V_100 ) ;
return 1 ;
}
static void * F_103 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
F_24 ( ! F_2 ( V_1 ) -> V_2 ) ;
V_7 = F_9 ( V_1 , F_8 ( V_5 ) ) ;
V_9 = (struct V_8 * ) ( ( void * ) F_8 ( V_5 ) +
F_2 ( V_1 ) -> V_2 ) ;
return ( void * ) F_10 ( V_7 ) + F_13 ( V_9 -> V_24 ) ;
}
static void F_104 ( void * V_118 , int V_119 , int V_120 )
{
struct V_104 * V_105 , * V_121 ;
void * V_122 ;
int V_103 ;
V_105 = (struct V_104 * ) V_118 ;
if ( V_119 ) {
V_122 = V_118 + V_119 ;
do {
V_121 = V_105 ;
V_103 = F_94 ( V_105 -> V_107 , V_119 ) ;
V_118 += V_103 ;
V_105 = (struct V_104 * ) V_118 ;
} while ( V_118 < V_122 );
V_121 -> V_107 = F_105 ( V_103 + V_120 -
V_119 , V_120 ) ;
} else {
V_105 -> V_1 = 0 ;
V_105 -> V_107 = F_105 ( V_120 , V_120 ) ;
}
}
static int F_106 ( T_3 * V_50 , struct V_1 * V_100 ,
struct V_4 * V_5 )
{
int V_58 ;
int V_119 = F_2 ( V_100 ) -> V_3 - V_31 ;
int V_120 = F_3 ( V_100 , V_5 ) ;
if ( V_120 - V_119 <= F_107 ( 1 ) )
return - V_54 ;
V_58 = F_36 ( V_50 , V_100 ,
V_120 + V_31 ) ;
if ( V_58 )
return V_58 ;
F_104 ( F_103 ( V_100 , V_5 ) , V_119 ,
F_2 ( V_100 ) -> V_3 -
V_31 ) ;
V_100 -> V_99 = F_2 ( V_100 ) -> V_123 = F_2 ( V_100 ) -> V_3 ;
return 0 ;
}
static void F_108 ( T_3 * V_50 , struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_124 , int V_92 )
{
F_27 ( V_50 , V_1 , V_92 ) ;
F_26 ( V_1 , V_5 , V_124 , 0 , V_92 ) ;
F_22 ( V_1 , V_44 ) ;
}
static int F_109 ( T_3 * V_50 ,
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
V_105 = F_110 ( V_1 , V_105 ,
V_1 -> V_13 -> V_132 , V_126 ,
F_14 ( ( (struct V_104 * ) V_124 ) -> V_1 ) , 1 ) ;
V_127 = ( void * ) V_105 - V_130 ;
memcpy ( ( void * ) V_105 , V_124 + V_133 ,
V_92 - V_133 ) ;
if ( F_111 ( V_1 -> V_13 ) )
V_126 = sizeof( struct V_128 ) ;
V_1 -> V_99 = V_1 -> V_13 -> V_132 ;
F_90 ( V_1 , V_1 -> V_13 -> V_132 ) ;
F_2 ( V_1 ) -> V_123 = V_1 -> V_13 -> V_132 ;
F_104 ( V_125 -> V_131 ,
V_92 - V_133 + V_127 ,
V_1 -> V_13 -> V_132 - V_126 ) ;
if ( V_126 ) {
V_129 = F_112 ( V_125 -> V_131 ,
V_1 -> V_13 -> V_132 ) ;
F_113 ( V_129 , V_1 -> V_13 -> V_132 ) ;
}
F_114 ( V_125 ) ;
V_114 = F_115 ( V_50 , V_1 , V_125 ) ;
if ( V_114 )
goto V_25;
F_116 ( V_125 ) ;
V_25:
return V_114 ;
}
static int F_117 ( T_3 * V_50 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
int error ;
void * V_124 = NULL ;
struct V_90 * V_134 = NULL ;
struct V_135 V_136 ;
int V_92 ;
V_92 = F_1 ( V_1 ) ;
V_124 = F_118 ( V_92 , V_57 ) ;
if ( ! V_124 ) {
error = - V_80 ;
goto V_25;
}
error = F_23 ( V_1 , V_124 , V_92 , V_5 ) ;
if ( error < 0 )
goto V_25;
if ( F_45 ( V_1 -> V_63 ) ) {
error = F_119 ( V_1 , V_5 -> V_30 ,
V_124 + V_133 ,
V_92 - V_133 ) ;
if ( error )
goto V_25;
}
error = F_43 ( V_50 , V_1 ) ;
if ( error )
goto V_25;
V_136 . V_137 = 0 ;
V_136 . V_138 = 1 ;
V_136 . V_139 = 0 ;
error = V_135 ( V_50 , V_1 , & V_136 , V_140 ) ;
if ( error < 0 )
goto V_141;
if ( ! ( V_136 . V_139 & V_142 ) ) {
error = - V_143 ;
goto V_141;
}
V_134 = F_120 ( V_1 -> V_13 , V_136 . V_144 ) ;
if ( ! V_134 ) {
error = - V_80 ;
goto V_141;
}
F_121 ( V_134 ) ;
error = F_122 ( V_50 , V_134 ) ;
if ( error ) {
F_123 ( V_134 ) ;
error = - V_143 ;
goto V_141;
}
memset ( V_134 -> V_131 , 0 , V_1 -> V_13 -> V_132 ) ;
if ( ! F_45 ( V_1 -> V_63 ) ) {
memcpy ( V_134 -> V_131 , V_124 , V_92 ) ;
F_114 ( V_134 ) ;
error = F_124 ( V_50 ,
V_1 , V_134 ) ;
} else {
error = F_109 ( V_50 , V_1 , V_134 ,
V_124 , V_92 ) ;
}
F_123 ( V_134 ) ;
V_141:
if ( error )
F_108 ( V_50 , V_1 , V_5 , V_124 , V_92 ) ;
V_25:
F_20 ( V_134 ) ;
F_39 ( V_124 ) ;
return error ;
}
int F_125 ( T_3 * V_50 , struct V_109 * V_109 ,
struct V_1 * V_1 )
{
int V_58 , V_92 ;
void * V_101 ;
struct V_4 V_5 ;
struct V_1 * V_100 = V_109 -> V_110 -> V_111 ;
V_58 = F_16 ( V_100 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_41 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_51 ( V_100 ) )
goto V_25;
V_101 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_133 ;
V_92 = V_31 - V_133 ;
V_58 = F_97 ( V_50 , V_109 , V_1 , & V_5 ,
V_101 , V_92 ) ;
if ( V_58 != - V_54 )
goto V_25;
V_92 = F_2 ( V_100 ) -> V_3 -
V_31 ;
if ( ! V_92 ) {
V_58 = F_106 ( V_50 , V_100 , & V_5 ) ;
if ( V_58 && V_58 != - V_54 )
goto V_25;
V_92 = F_2 ( V_100 ) -> V_3 -
V_31 ;
}
if ( V_92 ) {
V_101 = F_103 ( V_100 , & V_5 ) ;
V_58 = F_97 ( V_50 , V_109 , V_1 , & V_5 ,
V_101 , V_92 ) ;
if ( V_58 != - V_54 )
goto V_25;
}
V_58 = F_117 ( V_50 , V_100 , & V_5 ) ;
V_25:
F_102 ( V_50 , V_100 ) ;
F_42 ( & F_2 ( V_100 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_126 ( struct V_145 * V_146 ,
struct V_1 * V_100 , T_4 V_147 ,
struct V_148 * V_149 ,
V_20 V_150 , V_20 V_151 ,
int * V_152 )
{
int V_114 = 0 , V_153 = 0 ;
unsigned int V_154 ;
int V_49 ;
struct V_104 * V_105 ;
struct V_1 * V_1 = F_127 ( V_146 ) ;
int V_58 , V_92 = 0 ;
struct V_4 V_5 ;
void * V_155 = NULL ;
struct V_104 V_156 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_152 = 0 ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
V_155 = F_118 ( V_92 , V_57 ) ;
if ( ! V_155 ) {
V_58 = - V_80 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_23 ( V_1 , V_155 , V_92 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_49 = 0 ;
V_154 = F_14 ( ( (struct V_104 * ) V_155 ) -> V_1 ) ;
while ( V_49 < V_92 ) {
if ( V_49 == 0 ) {
V_156 . V_1 = F_128 ( V_1 -> V_28 ) ;
V_156 . V_108 = 1 ;
strcpy ( V_156 . V_41 , L_7 ) ;
V_156 . V_107 = F_105 (
F_107 ( V_156 . V_108 ) ,
V_92 ) ;
F_129 ( V_1 -> V_13 , & V_156 , V_157 ) ;
V_105 = & V_156 ;
V_49 = V_158 ;
} else if ( V_49 == V_158 ) {
V_156 . V_1 = F_128 ( V_154 ) ;
V_156 . V_108 = 2 ;
strcpy ( V_156 . V_41 , L_8 ) ;
V_156 . V_107 = F_105 (
F_107 ( V_156 . V_108 ) ,
V_92 ) ;
F_129 ( V_1 -> V_13 , & V_156 , V_157 ) ;
V_105 = & V_156 ;
V_49 = V_133 ;
} else {
V_105 = (struct V_104 * ) ( V_155 + V_49 ) ;
V_49 += F_94 ( V_105 -> V_107 , V_92 ) ;
if ( F_95 ( V_1 , V_146 , V_105 ,
V_5 . V_30 , V_155 ,
V_92 , V_49 ) ) {
V_58 = V_153 ;
goto V_25;
}
}
F_130 ( V_105 -> V_41 , V_105 -> V_108 , V_149 ) ;
if ( ( V_149 -> V_159 < V_150 ) ||
( ( V_149 -> V_159 == V_150 ) &&
( V_149 -> V_160 < V_151 ) ) )
continue;
if ( V_105 -> V_1 == 0 )
continue;
V_114 = F_131 ( V_146 ,
V_149 -> V_159 , V_149 -> V_160 , V_105 ) ;
if ( V_114 ) {
V_153 = V_114 ;
goto V_25;
}
V_153 ++ ;
}
V_58 = V_153 ;
V_25:
F_39 ( V_155 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_132 ( struct V_145 * V_145 ,
struct V_161 * V_162 ,
int * V_152 )
{
unsigned int V_102 , V_154 ;
int V_38 ;
struct V_104 * V_105 ;
struct V_163 * V_164 ;
struct V_1 * V_1 = F_127 ( V_145 ) ;
int V_58 , V_92 = 0 ;
struct V_4 V_5 ;
void * V_155 = NULL ;
int V_165 , V_166 , V_167 , V_168 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_152 = 0 ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
V_155 = F_118 ( V_92 , V_57 ) ;
if ( ! V_155 ) {
V_58 = - V_80 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_23 ( V_1 , V_155 , V_92 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_58 = 0 ;
V_164 = V_1 -> V_13 ;
V_154 = F_14 ( ( (struct V_104 * ) V_155 ) -> V_1 ) ;
V_102 = V_162 -> V_49 ;
V_165 = F_107 ( 1 ) ;
V_166 = V_165 + F_107 ( 2 ) ;
V_167 = V_166 - V_133 ;
V_168 = V_167 + V_92 ;
if ( V_145 -> V_169 != V_1 -> V_117 ) {
for ( V_38 = 0 ; V_38 < V_168 && V_38 < V_102 ; ) {
if ( ! V_38 ) {
V_38 = V_165 ;
continue;
} else if ( V_38 == V_165 ) {
V_38 = V_166 ;
continue;
}
V_105 = (struct V_104 * )
( V_155 + V_38 - V_167 ) ;
if ( F_94 ( V_105 -> V_107 , V_168 )
< F_107 ( 1 ) )
break;
V_38 += F_94 ( V_105 -> V_107 ,
V_168 ) ;
}
V_102 = V_38 ;
V_162 -> V_49 = V_102 ;
V_145 -> V_169 = V_1 -> V_117 ;
}
while ( V_162 -> V_49 < V_168 ) {
if ( V_162 -> V_49 == 0 ) {
if ( ! F_133 ( V_162 , L_7 , 1 , V_1 -> V_28 , V_170 ) )
goto V_25;
V_162 -> V_49 = V_165 ;
continue;
}
if ( V_162 -> V_49 == V_165 ) {
if ( ! F_133 ( V_162 , L_8 , 2 , V_154 , V_170 ) )
goto V_25;
V_162 -> V_49 = V_166 ;
continue;
}
V_105 = (struct V_104 * )
( V_155 + V_162 -> V_49 - V_167 ) ;
if ( F_95 ( V_1 , V_145 , V_105 , V_5 . V_30 , V_155 ,
V_168 , V_162 -> V_49 ) )
goto V_25;
if ( F_14 ( V_105 -> V_1 ) ) {
if ( ! F_133 ( V_162 , V_105 -> V_41 , V_105 -> V_108 ,
F_14 ( V_105 -> V_1 ) ,
F_134 ( V_164 , V_105 -> V_171 ) ) )
goto V_25;
}
V_162 -> V_49 += F_94 ( V_105 -> V_107 , V_168 ) ;
}
V_25:
F_39 ( V_155 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_90 * F_135 ( struct V_1 * V_1 ,
struct V_104 * * V_172 ,
int * V_173 )
{
struct V_4 V_5 ;
* V_173 = F_16 ( V_1 , & V_5 ) ;
if ( * V_173 )
return NULL ;
* V_172 = (struct V_104 * ) F_8 ( & V_5 ) -> V_48 ;
return V_5 . V_30 ;
}
int F_136 ( T_3 * V_50 , struct V_1 * V_174 ,
struct V_1 * V_1 )
{
int V_58 , V_92 = V_31 ;
struct V_4 V_5 ;
struct V_104 * V_105 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_40 ( V_50 , V_1 , V_92 ) ;
if ( V_58 )
goto V_25;
V_105 = (struct V_104 * ) F_8 ( & V_5 ) -> V_48 ;
V_105 -> V_1 = F_128 ( V_174 -> V_28 ) ;
V_105 = (struct V_104 * ) ( ( void * ) V_105 + V_133 ) ;
V_105 -> V_1 = 0 ;
V_105 -> V_107 = F_105 (
V_92 - V_133 ,
V_92 ) ;
F_137 ( V_1 , 2 ) ;
V_1 -> V_99 = F_2 ( V_1 ) -> V_123 = V_92 ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_90 * F_138 ( struct V_1 * V_100 ,
const struct V_175 * V_112 ,
struct V_104 * * V_176 ,
int * V_152 )
{
int V_58 ;
struct V_4 V_5 ;
void * V_101 ;
int V_92 ;
if ( F_16 ( V_100 , & V_5 ) )
return NULL ;
F_18 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_51 ( V_100 ) ) {
* V_152 = 0 ;
goto V_25;
}
V_101 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_133 ;
V_92 = V_31 - V_133 ;
V_58 = F_139 ( V_5 . V_30 , V_101 , V_92 ,
V_100 , V_112 , 0 , V_176 ) ;
if ( V_58 == 1 )
goto V_177;
if ( V_58 < 0 )
goto V_25;
if ( F_1 ( V_100 ) == V_31 )
goto V_25;
V_101 = F_103 ( V_100 , & V_5 ) ;
V_92 = F_1 ( V_100 ) - V_31 ;
V_58 = F_139 ( V_5 . V_30 , V_101 , V_92 ,
V_100 , V_112 , 0 , V_176 ) ;
if ( V_58 == 1 )
goto V_177;
V_25:
F_20 ( V_5 . V_30 ) ;
V_5 . V_30 = NULL ;
V_177:
F_19 ( & F_2 ( V_100 ) -> V_29 ) ;
return V_5 . V_30 ;
}
int F_140 ( T_3 * V_50 ,
struct V_1 * V_100 ,
struct V_104 * V_178 ,
struct V_90 * V_30 ,
int * V_152 )
{
int V_114 , V_92 ;
struct V_4 V_5 ;
void * V_101 ;
V_114 = F_16 ( V_100 , & V_5 ) ;
if ( V_114 )
return V_114 ;
F_41 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_51 ( V_100 ) ) {
* V_152 = 0 ;
goto V_25;
}
if ( ( void * ) V_178 - ( ( void * ) F_8 ( & V_5 ) -> V_48 ) <
V_31 ) {
V_101 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_133 ;
V_92 = V_31 -
V_133 ;
} else {
V_101 = F_103 ( V_100 , & V_5 ) ;
V_92 = F_1 ( V_100 ) -
V_31 ;
}
F_28 ( V_30 , L_2 ) ;
V_114 = F_29 ( V_50 , V_30 ) ;
if ( V_114 )
goto V_25;
V_114 = F_141 ( V_50 , V_100 , V_178 , V_30 ,
V_101 , V_92 , 0 ) ;
if ( V_114 )
goto V_25;
F_28 ( V_30 , L_9 ) ;
V_114 = F_102 ( V_50 , V_100 ) ;
if ( F_82 ( V_114 ) )
goto V_25;
F_92 ( V_100 , V_5 . V_30 , V_101 , V_92 ) ;
V_25:
F_42 ( & F_2 ( V_100 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
if ( V_114 != - V_179 )
F_83 ( V_100 -> V_13 , V_114 ) ;
return V_114 ;
}
static inline struct V_104 *
F_142 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned int V_102 ,
void * * V_101 ,
int * V_92 )
{
void * V_180 ;
F_24 ( V_102 > F_1 ( V_1 ) ) ;
if ( V_102 < V_31 ) {
V_180 = ( void * ) F_8 ( V_5 ) -> V_48 ;
* V_92 = V_31 ;
} else {
V_180 = F_103 ( V_1 , V_5 ) ;
V_102 -= V_31 ;
* V_92 = F_1 ( V_1 ) -
V_31 ;
}
if ( V_101 )
* V_101 = V_180 ;
return (struct V_104 * ) ( V_180 + V_102 ) ;
}
int F_143 ( struct V_1 * V_100 , int * V_152 )
{
int V_114 , V_92 ;
struct V_4 V_5 ;
void * V_180 ;
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
if ( ! F_51 ( V_100 ) ) {
* V_152 = 0 ;
goto V_25;
}
V_105 = (struct V_104 * ) F_8 ( & V_5 ) -> V_48 ;
if ( ! F_14 ( V_105 -> V_1 ) ) {
F_52 ( V_100 -> V_13 ,
L_11 ,
V_100 -> V_28 ) ;
V_58 = 1 ;
goto V_25;
}
V_102 = V_133 ;
while ( V_102 < V_100 -> V_99 ) {
V_105 = F_142 ( V_100 , & V_5 , V_102 ,
& V_180 , & V_92 ) ;
if ( F_95 ( V_100 , NULL , V_105 ,
V_5 . V_30 , V_180 ,
V_92 , V_102 ) ) {
F_52 ( V_100 -> V_13 ,
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
V_102 += F_94 ( V_105 -> V_107 , V_92 ) ;
}
V_25:
F_19 ( & F_2 ( V_100 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_145 ( T_3 * V_50 , struct V_1 * V_1 )
{
int V_58 ;
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
V_58 = F_43 ( V_50 , V_1 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_58 ;
}
int F_146 ( struct V_1 * V_1 ,
struct V_181 * V_182 ,
int * V_183 )
{
T_5 V_184 = 0 ;
T_5 V_185 ;
V_20 V_71 = V_186 | V_187 ;
int error = 0 ;
struct V_4 V_5 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
* V_183 = 0 ;
goto V_25;
}
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
goto V_25;
V_184 = ( T_5 ) V_5 . V_30 -> V_188 << V_1 -> V_13 -> V_189 ;
V_184 += ( char * ) F_8 ( & V_5 ) - V_5 . V_30 -> V_131 ;
V_184 += F_147 ( struct V_10 , V_48 ) ;
V_185 = F_53 ( V_1 ) ;
if ( V_184 )
error = F_148 ( V_182 , 0 , V_184 ,
V_185 , V_71 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return ( error < 0 ? error : 0 ) ;
}
int F_149 ( T_3 * V_50 ,
struct V_1 * V_1 ,
int V_190 )
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
if ( F_7 ( V_9 -> V_191 ) +
F_6 ( F_14 ( V_9 -> V_22 ) ) < V_190 ) {
error = - V_54 ;
goto V_25;
}
error = F_117 ( V_50 , V_1 , & V_5 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return error ;
}
void F_150 ( struct V_1 * V_1 , int * V_183 )
{
T_3 * V_50 ;
int V_92 , V_53 , V_72 ;
T_1 V_99 ;
void * V_51 = NULL ;
struct V_32 V_33 = {
. V_34 = { . V_35 = - V_36 , } ,
} ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_18 ,
} ;
V_72 = F_63 ( V_1 ) ;
V_50 = F_64 ( V_1 , V_87 , V_72 ) ;
if ( F_65 ( V_50 ) )
return;
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
* V_183 = 0 ;
F_75 ( V_50 ) ;
return;
}
if ( F_74 ( V_50 , V_1 ) )
goto V_25;
if ( F_16 ( V_1 , & V_33 . V_5 ) )
goto V_25;
F_41 ( & F_2 ( V_1 ) -> V_192 ) ;
V_99 = V_1 -> V_99 ;
V_92 = F_1 ( V_1 ) ;
F_2 ( V_1 ) -> V_123 = V_99 ;
if ( V_99 < V_92 ) {
if ( V_92 > V_31 ) {
if ( V_32 ( V_1 , & V_38 , & V_33 ) )
goto V_193;
F_24 ( V_33 . V_34 . V_35 ) ;
V_53 = F_14 ( V_33 . V_34 . V_43 -> V_22 ) ;
V_51 = F_118 ( V_53 , V_57 ) ;
if ( ! V_51 )
goto V_193;
if ( F_38 ( V_1 , V_38 . V_39 , V_38 . V_41 ,
V_51 , V_53 ) )
goto V_193;
V_38 . V_51 = V_51 ;
V_38 . V_53 = V_99 > V_31 ?
V_99 - V_31 : 0 ;
if ( F_30 ( V_50 , V_1 , & V_38 , & V_33 ) )
goto V_193;
}
if ( V_99 < V_31 ) {
void * V_194 = ( void * ) F_8 ( & V_33 . V_5 ) -> V_48 ;
memset ( V_194 + V_99 , 0 ,
V_31 - V_99 ) ;
}
F_2 ( V_1 ) -> V_3 = V_99 <
V_31 ?
V_31 : V_99 ;
}
V_193:
F_42 ( & F_2 ( V_1 ) -> V_192 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
F_39 ( V_51 ) ;
if ( V_1 -> V_84 )
F_77 ( V_50 , V_1 ) ;
V_1 -> V_115 = V_1 -> V_116 = F_100 ( V_1 ) ;
F_102 ( V_50 , V_1 ) ;
if ( F_151 ( V_1 ) )
F_152 ( V_50 ) ;
F_75 ( V_50 ) ;
return;
}
int F_153 ( struct V_1 * V_1 )
{
int error , V_72 ;
T_3 * V_50 ;
struct V_4 V_5 ;
if ( ! F_51 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
return 0 ;
}
V_72 = F_63 ( V_1 ) ;
V_5 . V_30 = NULL ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
return error ;
V_50 = F_64 ( V_1 , V_78 , V_72 ) ;
if ( F_65 ( V_50 ) ) {
error = F_66 ( V_50 ) ;
goto V_195;
}
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
error = F_117 ( V_50 , V_1 , & V_5 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
F_75 ( V_50 ) ;
V_195:
F_20 ( V_5 . V_30 ) ;
return error ;
}
