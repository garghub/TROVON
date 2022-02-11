int F_1 ( struct V_1 * V_1 )
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
free += F_14 ( V_9 -> V_22 ) ;
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
void F_28 ( struct V_1 * V_1 , struct V_4 * V_5 ,
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
error = F_30 ( V_51 , V_34 . V_5 . V_30 ) ;
if ( error )
goto V_25;
if ( V_47 > V_31 ) {
V_52 = V_53 ;
V_47 -= V_31 ;
} else {
V_52 = L_2 ;
V_47 = 0 ;
}
V_39 . V_52 = V_52 ;
V_39 . V_54 = V_47 ;
error = V_33 ( V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
F_26 ( ! V_34 . V_35 . V_36 ) ;
error = F_31 ( V_51 , V_1 , & V_39 , & V_34 ) ;
if ( error ) {
if ( error == - V_55 )
F_32 ( V_1 ,
V_45 ) ;
goto V_25;
}
memset ( ( void * ) F_8 ( & V_34 . V_5 ) -> V_49 ,
0 , V_31 ) ;
F_2 ( V_1 ) -> V_2 = ( V_43 ) ( ( void * ) V_34 . V_35 . V_44 -
( void * ) F_8 ( & V_34 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_47 + V_31 ;
F_33 ( V_1 , V_56 ) ;
F_34 ( V_1 , V_32 ) ;
F_35 ( V_34 . V_5 . V_30 ) ;
error = F_36 ( V_51 , V_1 , & V_34 . V_5 ) ;
V_25:
F_20 ( V_34 . V_5 . V_30 ) ;
return error ;
}
static int F_37 ( T_3 * V_51 , struct V_1 * V_1 ,
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
V_52 = F_38 ( V_47 , V_57 ) ;
if ( ! V_52 )
goto V_25;
error = F_39 ( V_1 , V_39 . V_40 , V_39 . V_42 ,
V_52 , V_47 ) ;
if ( error == - V_37 )
goto V_25;
error = F_30 ( V_51 , V_34 . V_5 . V_30 ) ;
if ( error )
goto V_25;
V_39 . V_52 = V_52 ;
V_39 . V_54 = V_47 ;
error = F_31 ( V_51 , V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
F_2 ( V_1 ) -> V_2 = ( V_43 ) ( ( void * ) V_34 . V_35 . V_44 -
( void * ) F_8 ( & V_34 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_31 +
F_14 ( V_34 . V_35 . V_44 -> V_22 ) ;
F_24 ( V_1 , V_45 ) ;
F_35 ( V_34 . V_5 . V_30 ) ;
error = F_36 ( V_51 , V_1 , & V_34 . V_5 ) ;
V_25:
F_40 ( V_52 ) ;
F_20 ( V_34 . V_5 . V_30 ) ;
return error ;
}
int F_41 ( T_3 * V_51 , struct V_1 * V_1 ,
unsigned int V_47 )
{
int V_58 , V_59 ;
struct V_60 * V_61 = F_2 ( V_1 ) ;
if ( ! F_5 ( V_1 , V_45 ) )
return - V_55 ;
V_59 = F_15 ( V_1 ) ;
if ( V_59 < V_47 )
return - V_55 ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_61 -> V_2 )
V_58 = F_37 ( V_51 , V_1 , V_47 ) ;
else
V_58 = F_29 ( V_51 , V_1 , V_47 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_58 ;
}
static int F_44 ( T_3 * V_51 ,
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
error = F_30 ( V_51 , V_34 . V_5 . V_30 ) ;
if ( error )
goto V_25;
error = F_31 ( V_51 , V_1 , & V_39 , & V_34 ) ;
if ( error )
goto V_25;
memset ( ( void * ) F_8 ( & V_34 . V_5 ) -> V_49 ,
0 , V_31 ) ;
if ( F_45 ( V_1 -> V_13 ,
V_62 ) ) {
if ( F_46 ( V_1 -> V_63 ) ||
F_47 ( V_1 -> V_63 ) || F_48 ( V_1 -> V_63 ) ) {
F_34 ( V_1 , V_56 ) ;
F_49 ( V_51 , V_1 ) ;
}
}
F_33 ( V_1 , V_32 ) ;
F_35 ( V_34 . V_5 . V_30 ) ;
error = F_36 ( V_51 , V_1 , & V_34 . V_5 ) ;
F_2 ( V_1 ) -> V_2 = 0 ;
F_2 ( V_1 ) -> V_3 = 0 ;
F_32 ( V_1 , V_45 ) ;
V_25:
F_20 ( V_34 . V_5 . V_30 ) ;
if ( error == - V_37 )
error = 0 ;
return error ;
}
static int F_50 ( struct V_1 * V_1 , struct V_64 * V_64 )
{
void * V_65 ;
int V_58 = 0 ;
T_1 V_47 ;
struct V_4 V_5 ;
F_26 ( ! F_51 ( V_64 ) ) ;
F_26 ( ! F_21 ( V_1 ) ) ;
F_26 ( V_64 -> V_66 ) ;
if ( ! F_2 ( V_1 ) -> V_2 ) {
F_52 ( V_1 -> V_13 , L_3 ,
V_1 -> V_28 ) ;
goto V_25;
}
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
goto V_25;
V_47 = F_27 ( T_1 , F_1 ( V_1 ) , F_53 ( V_1 ) ) ;
V_65 = F_54 ( V_64 ) ;
V_58 = F_25 ( V_1 , V_65 , V_47 , & V_5 ) ;
F_55 ( V_64 ) ;
F_56 ( V_65 ) ;
F_57 ( V_64 , V_47 , V_67 ) ;
F_58 ( V_64 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_58 ;
}
int F_59 ( struct V_1 * V_1 , struct V_64 * V_64 )
{
int V_58 = 0 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return - V_68 ;
}
if ( ! V_64 -> V_66 )
V_58 = F_50 ( V_1 , V_64 ) ;
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
T_3 * V_51 = NULL ;
int V_73 = 0 , V_74 = 0 ;
struct V_64 * V_64 = NULL ;
unsigned V_75 , V_76 ;
struct V_4 V_5 ;
if ( ! F_21 ( V_1 ) ) {
F_32 ( V_1 , V_45 ) ;
return 0 ;
}
V_72 = F_63 ( V_1 ) ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_77:
V_51 = F_64 ( V_1 , V_72 ) ;
if ( F_65 ( V_51 ) ) {
V_58 = F_66 ( V_51 ) ;
V_51 = NULL ;
goto V_25;
}
V_71 |= V_78 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_79 ;
goto V_25;
}
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_74 = 1 ;
if ( ! F_21 ( V_1 ) ) {
V_58 = 0 ;
goto V_25;
}
V_75 = 0 ;
V_76 = F_1 ( V_1 ) ;
if ( ! F_60 ( V_64 ) ) {
V_58 = F_50 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_25;
}
V_58 = F_44 ( V_51 , V_1 ) ;
if ( V_58 )
goto V_25;
if ( F_68 ( V_1 ) )
V_58 = F_69 ( V_64 , V_75 , V_76 , V_80 ) ;
else
V_58 = F_69 ( V_64 , V_75 , V_76 , V_81 ) ;
if ( ! V_58 && F_70 ( V_1 ) ) {
V_58 = F_71 ( V_51 , F_72 ( V_64 ) ,
V_75 , V_76 , NULL ,
V_82 ) ;
}
if ( V_58 ) {
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
F_74 ( V_51 , V_1 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
V_74 = 0 ;
F_75 ( V_51 ) ;
V_51 = NULL ;
F_76 ( V_1 ) ;
if ( V_1 -> V_83 )
F_77 ( NULL , V_1 ) ;
}
if ( V_58 == - V_55 && F_78 ( V_1 -> V_13 , & V_73 ) )
goto V_77;
F_79 ( V_64 , V_75 , V_76 ) ;
V_25:
if ( V_64 ) {
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
}
if ( V_74 )
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_51 )
F_75 ( V_51 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_80 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
T_2 V_50 , unsigned V_47 ,
unsigned V_71 ,
struct V_64 * * V_84 )
{
int V_58 ;
T_3 * V_51 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
if ( V_50 + V_47 > F_15 ( V_1 ) )
goto V_85;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_51 = F_64 ( V_1 , 1 ) ;
if ( F_65 ( V_51 ) ) {
V_58 = F_66 ( V_51 ) ;
V_51 = NULL ;
goto V_25;
}
V_58 = F_41 ( V_51 , V_1 , V_50 + V_47 ) ;
if ( V_58 && V_58 != - V_55 )
goto V_25;
if ( V_58 == - V_55 ) {
F_75 ( V_51 ) ;
F_20 ( V_5 . V_30 ) ;
goto V_85;
}
V_71 |= V_78 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_79 ;
goto V_25;
}
* V_84 = V_64 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
V_58 = 0 ;
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
goto V_86;
}
if ( ! F_60 ( V_64 ) ) {
V_58 = F_50 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_86;
}
V_58 = 1 ;
V_51 = NULL ;
V_86:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
if ( V_51 )
F_75 ( V_51 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
V_85:
return F_62 ( V_70 ,
V_1 , V_71 ) ;
}
int F_81 ( struct V_1 * V_1 , T_2 V_50 , unsigned V_47 ,
unsigned V_87 , struct V_64 * V_64 )
{
int V_58 ;
void * V_65 ;
struct V_4 V_5 ;
if ( F_82 ( V_87 < V_47 ) ) {
if ( ! F_60 ( V_64 ) ) {
V_87 = 0 ;
goto V_25;
}
}
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 ) {
F_83 ( V_1 -> V_13 , V_58 ) ;
V_87 = 0 ;
goto V_25;
}
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
F_26 ( ! F_21 ( V_1 ) ) ;
V_65 = F_54 ( V_64 ) ;
F_28 ( V_1 , & V_5 , V_65 , V_50 , V_47 ) ;
F_56 ( V_65 ) ;
F_58 ( V_64 ) ;
F_84 ( V_64 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_87 ;
}
struct V_88 *
F_85 ( struct V_1 * V_1 ,
unsigned V_47 ,
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
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_65 = F_54 ( V_64 ) ;
F_28 ( V_1 , & V_5 , V_65 , 0 , V_47 ) ;
F_56 ( V_65 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_5 . V_30 ;
}
static int F_86 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
unsigned V_71 ,
void * * V_89 )
{
int V_58 = 0 , V_90 ;
struct V_64 * V_64 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 )
return - V_79 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_32 ( V_1 , V_45 ) ;
goto V_25;
}
V_90 = F_1 ( V_1 ) ;
if ( ! F_60 ( V_64 ) ) {
V_58 = F_50 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_25;
}
V_58 = F_69 ( V_64 , 0 , V_90 ,
V_91 ) ;
if ( V_58 ) {
F_76 ( V_1 ) ;
goto V_25;
}
F_87 ( V_64 ) ;
F_58 ( V_64 ) ;
F_32 ( V_1 , V_45 ) ;
* V_89 = ( void * ) V_92 ;
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
T_2 V_50 , unsigned V_47 ,
unsigned V_71 ,
struct V_64 * * V_84 ,
void * * V_89 )
{
int V_58 , V_90 ;
T_3 * V_51 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_51 = F_64 ( V_1 , 1 ) ;
if ( F_65 ( V_51 ) ) {
V_58 = F_66 ( V_51 ) ;
V_51 = NULL ;
goto V_25;
}
V_90 = F_15 ( V_1 ) ;
V_58 = - V_55 ;
if ( V_90 >= V_50 + V_47 ) {
V_58 = F_41 ( V_51 , V_1 , V_50 + V_47 ) ;
if ( V_58 && V_58 != - V_55 )
goto V_25;
}
if ( V_58 == - V_55 ) {
V_58 = F_86 ( V_70 ,
V_1 ,
V_71 ,
V_89 ) ;
goto V_25;
}
V_71 |= V_78 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_79 ;
goto V_25;
}
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
V_58 = 0 ;
goto V_93;
}
if ( ! F_60 ( V_64 ) ) {
V_58 = F_50 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_93;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_84 = V_64 ;
V_51 = NULL ;
F_20 ( V_5 . V_30 ) ;
return 1 ;
V_93:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
V_25:
if ( V_51 )
F_75 ( V_51 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_89 ( struct V_1 * V_1 , T_2 V_50 ,
unsigned V_47 , unsigned V_87 ,
struct V_64 * V_64 )
{
int V_94 = 0 ;
V_87 = F_81 ( V_1 , V_50 , V_47 , V_87 , V_64 ) ;
if ( V_50 + V_87 > V_1 -> V_95 ) {
F_90 ( V_1 , V_50 + V_87 ) ;
V_94 = 1 ;
}
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
if ( V_94 )
F_91 ( V_1 ) ;
return V_87 ;
}
void F_92 ( struct V_1 * V_96 , struct V_88 * V_30 ,
void * V_97 , int V_90 )
{
int V_98 ;
unsigned short V_99 ;
struct V_100 * V_101 = V_97 ;
void * V_102 = V_97 + V_90 ;
F_93 ( L_4 , V_96 -> V_28 ) ;
V_98 = 0 ;
while ( ( void * ) V_101 < V_102 ) {
V_99 = F_94 ( V_101 -> V_103 , V_90 ) ;
F_93 ( L_5 ,
V_98 , V_99 , V_101 -> V_104 , V_101 -> V_42 ,
V_101 -> V_104 , F_14 ( V_101 -> V_1 ) ) ;
if ( F_95 ( V_96 , NULL , V_101 , V_30 ,
V_97 , V_90 , V_98 ) )
F_96 () ;
V_98 += V_99 ;
V_101 = (struct V_100 * ) ( ( char * ) V_101 + V_99 ) ;
}
}
static int F_97 ( T_3 * V_51 ,
struct V_105 * V_105 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_97 , int V_90 )
{
struct V_1 * V_96 = V_105 -> V_106 -> V_107 ;
const char * V_42 = V_105 -> V_108 . V_42 ;
int V_109 = V_105 -> V_108 . V_47 ;
unsigned short V_110 ;
int V_111 ;
struct V_100 * V_101 ;
V_110 = F_98 ( V_109 ) ;
V_111 = F_99 ( V_96 , V_1 , V_5 -> V_30 ,
V_97 , V_90 ,
V_42 , V_109 , & V_101 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_30 ( V_51 , V_5 -> V_30 ) ;
if ( V_111 )
return V_111 ;
F_100 ( V_1 , V_101 , V_90 , V_42 , V_109 ) ;
F_92 ( V_96 , V_5 -> V_30 , V_97 , V_90 ) ;
V_96 -> V_112 = V_96 -> V_113 = F_101 ( V_96 ) ;
F_102 ( V_96 ) ;
V_96 -> V_114 ++ ;
F_103 ( V_51 , V_96 ) ;
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
static void F_105 ( void * V_115 , int V_116 , int V_117 )
{
struct V_100 * V_101 , * V_118 ;
void * V_119 ;
int V_99 ;
V_101 = (struct V_100 * ) V_115 ;
if ( V_116 ) {
V_119 = V_115 + V_116 ;
do {
V_118 = V_101 ;
V_99 = F_94 ( V_101 -> V_103 , V_116 ) ;
V_115 += V_99 ;
V_101 = (struct V_100 * ) V_115 ;
} while ( V_115 < V_119 );
V_118 -> V_103 = F_106 ( V_99 + V_117 -
V_116 , V_117 ) ;
} else {
V_101 -> V_1 = 0 ;
V_101 -> V_103 = F_106 ( V_117 , V_117 ) ;
}
}
static int F_107 ( T_3 * V_51 , struct V_1 * V_96 ,
struct V_4 * V_5 )
{
int V_58 ;
int V_116 = F_2 ( V_96 ) -> V_3 - V_31 ;
int V_117 = F_3 ( V_96 , V_5 ) ;
if ( V_117 - V_116 <= F_98 ( 1 ) )
return - V_55 ;
V_58 = F_37 ( V_51 , V_96 ,
V_117 + V_31 ) ;
if ( V_58 )
return V_58 ;
F_105 ( F_104 ( V_96 , V_5 ) , V_116 ,
F_2 ( V_96 ) -> V_3 -
V_31 ) ;
V_96 -> V_95 = F_2 ( V_96 ) -> V_120 = F_2 ( V_96 ) -> V_3 ;
return 0 ;
}
static void F_108 ( T_3 * V_51 , struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_121 , int V_90 )
{
F_29 ( V_51 , V_1 , V_90 ) ;
F_28 ( V_1 , V_5 , V_121 , 0 , V_90 ) ;
F_24 ( V_1 , V_45 ) ;
}
static int F_109 ( T_3 * V_51 ,
struct V_1 * V_1 ,
struct V_88 * V_122 ,
void * V_121 ,
int V_90 )
{
int V_111 , V_123 = 0 , V_124 = 0 ;
struct V_100 * V_101 ;
struct V_125 * V_126 ;
void * V_127 = V_122 -> V_128 ;
V_101 = (struct V_100 * ) V_127 ;
V_101 = F_110 ( V_1 , V_101 ,
V_1 -> V_13 -> V_129 , V_123 ,
F_14 ( ( (struct V_100 * ) V_121 ) -> V_1 ) , 1 ) ;
V_124 = ( void * ) V_101 - V_127 ;
memcpy ( ( void * ) V_101 , V_121 + V_130 ,
V_90 - V_130 ) ;
if ( F_111 ( V_1 -> V_13 ,
V_131 ) )
V_123 = sizeof( struct V_125 ) ;
V_1 -> V_95 = V_1 -> V_13 -> V_129 ;
F_90 ( V_1 , V_1 -> V_13 -> V_129 ) ;
F_2 ( V_1 ) -> V_120 = V_1 -> V_13 -> V_129 ;
F_105 ( V_122 -> V_128 ,
V_90 - V_130 + V_124 ,
V_1 -> V_13 -> V_129 - V_123 ) ;
if ( V_123 ) {
V_126 = F_112 ( V_122 -> V_128 ,
V_1 -> V_13 -> V_129 ) ;
F_113 ( V_126 , V_1 -> V_13 -> V_129 ) ;
}
F_114 ( V_122 ) ;
V_111 = F_115 ( V_51 , V_1 , V_122 ) ;
if ( V_111 )
goto V_25;
F_116 ( V_122 ) ;
V_25:
return V_111 ;
}
static int F_117 ( T_3 * V_51 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
int error ;
void * V_121 = NULL ;
struct V_88 * V_132 = NULL ;
struct V_133 V_134 ;
int V_90 ;
V_90 = F_1 ( V_1 ) ;
V_121 = F_118 ( V_90 , V_57 ) ;
if ( ! V_121 ) {
error = - V_79 ;
goto V_25;
}
error = F_25 ( V_1 , V_121 , V_90 , V_5 ) ;
if ( error < 0 )
goto V_25;
error = F_44 ( V_51 , V_1 ) ;
if ( error )
goto V_25;
V_134 . V_135 = 0 ;
V_134 . V_136 = 1 ;
V_134 . V_137 = 0 ;
error = V_133 ( V_51 , V_1 , & V_134 , V_138 ) ;
if ( error < 0 )
goto V_139;
if ( ! ( V_134 . V_137 & V_140 ) ) {
error = - V_141 ;
goto V_139;
}
V_132 = F_119 ( V_1 -> V_13 , V_134 . V_142 ) ;
if ( ! V_132 ) {
error = - V_141 ;
goto V_139;
}
F_120 ( V_132 ) ;
error = F_121 ( V_51 , V_132 ) ;
if ( error ) {
F_122 ( V_132 ) ;
error = - V_141 ;
goto V_139;
}
memset ( V_132 -> V_128 , 0 , V_1 -> V_13 -> V_129 ) ;
if ( ! F_46 ( V_1 -> V_63 ) ) {
memcpy ( V_132 -> V_128 , V_121 , V_90 ) ;
F_114 ( V_132 ) ;
error = F_123 ( V_51 ,
V_1 , V_132 ) ;
} else {
error = F_109 ( V_51 , V_1 , V_132 ,
V_121 , V_90 ) ;
}
F_122 ( V_132 ) ;
V_139:
if ( error )
F_108 ( V_51 , V_1 , V_5 , V_121 , V_90 ) ;
V_25:
F_20 ( V_132 ) ;
F_40 ( V_121 ) ;
return error ;
}
int F_124 ( T_3 * V_51 , struct V_105 * V_105 ,
struct V_1 * V_1 )
{
int V_58 , V_90 ;
void * V_97 ;
struct V_4 V_5 ;
struct V_1 * V_96 = V_105 -> V_106 -> V_107 ;
V_58 = F_16 ( V_96 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_42 ( & F_2 ( V_96 ) -> V_29 ) ;
if ( ! F_21 ( V_96 ) )
goto V_25;
V_97 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_130 ;
V_90 = V_31 - V_130 ;
V_58 = F_97 ( V_51 , V_105 , V_1 , & V_5 ,
V_97 , V_90 ) ;
if ( V_58 != - V_55 )
goto V_25;
V_90 = F_2 ( V_96 ) -> V_3 -
V_31 ;
if ( ! V_90 ) {
V_58 = F_107 ( V_51 , V_96 , & V_5 ) ;
if ( V_58 && V_58 != - V_55 )
goto V_25;
V_90 = F_2 ( V_96 ) -> V_3 -
V_31 ;
}
if ( V_90 ) {
V_97 = F_104 ( V_96 , & V_5 ) ;
V_58 = F_97 ( V_51 , V_105 , V_1 , & V_5 ,
V_97 , V_90 ) ;
if ( V_58 != - V_55 )
goto V_25;
}
V_58 = F_117 ( V_51 , V_96 , & V_5 ) ;
V_25:
F_103 ( V_51 , V_96 ) ;
F_43 ( & F_2 ( V_96 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_125 ( struct V_143 * V_144 ,
void * V_145 , T_4 V_146 ,
int * V_147 )
{
int error = 0 ;
unsigned int V_98 , V_148 ;
int V_39 , V_149 ;
struct V_100 * V_101 ;
struct V_150 * V_151 ;
struct V_1 * V_1 = V_144 -> V_152 . V_105 -> V_107 ;
int V_58 , V_90 = 0 ;
struct V_4 V_5 ;
void * V_153 = NULL ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_147 = 0 ;
goto V_25;
}
V_90 = F_1 ( V_1 ) ;
V_153 = F_118 ( V_90 , V_57 ) ;
if ( ! V_153 ) {
V_58 = - V_79 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_25 ( V_1 , V_153 , V_90 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_151 = V_1 -> V_13 ;
V_149 = 0 ;
V_148 = F_14 ( ( (struct V_100 * ) V_153 ) -> V_1 ) ;
while ( ! error && ! V_149 && V_144 -> V_154 < V_1 -> V_95 ) {
V_155:
if ( V_144 -> V_156 != V_1 -> V_114 ) {
for ( V_39 = 0 ;
V_39 < V_1 -> V_95 && V_39 < V_98 ; ) {
if ( ! V_39 ) {
V_39 += V_130 ;
continue;
}
V_101 = (struct V_100 * )
( V_153 + V_39 ) ;
if ( F_94 ( V_101 -> V_103 ,
V_90 ) < F_98 ( 1 ) )
break;
V_39 += F_94 ( V_101 -> V_103 ,
V_90 ) ;
}
V_98 = V_39 ;
V_144 -> V_154 = V_98 ;
V_144 -> V_156 = V_1 -> V_114 ;
}
while ( ! error && V_144 -> V_154 < V_1 -> V_95 ) {
if ( V_144 -> V_154 == 0 ) {
error = V_146 ( V_145 , L_6 , 1 , 0 , V_1 -> V_28 ,
V_157 ) ;
if ( error )
break;
V_149 ++ ;
error = V_146 ( V_145 , L_7 , 2 , 0 , V_148 ,
V_157 ) ;
if ( error )
break;
V_149 ++ ;
V_144 -> V_154 = V_98 = V_130 ;
continue;
}
V_101 = (struct V_100 * ) ( V_153 + V_98 ) ;
if ( F_95 ( V_1 , V_144 , V_101 ,
V_5 . V_30 , V_153 ,
V_90 , V_98 ) ) {
V_58 = V_149 ;
goto V_25;
}
V_98 += F_94 ( V_101 -> V_103 ,
V_90 ) ;
if ( F_14 ( V_101 -> V_1 ) ) {
T_5 V_158 = V_144 -> V_156 ;
error = V_146 ( V_145 , V_101 -> V_42 ,
V_101 -> V_104 ,
V_144 -> V_154 ,
F_14 ( V_101 -> V_1 ) ,
F_126 ( V_151 , V_101 -> V_159 ) ) ;
if ( error )
break;
if ( V_158 != V_144 -> V_156 )
goto V_155;
V_149 ++ ;
}
V_144 -> V_154 += F_94 ( V_101 -> V_103 ,
V_90 ) ;
}
V_98 = 0 ;
}
V_25:
F_40 ( V_153 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_88 * F_127 ( struct V_1 * V_1 ,
struct V_100 * * V_160 ,
int * V_161 )
{
struct V_4 V_5 ;
* V_161 = F_16 ( V_1 , & V_5 ) ;
if ( * V_161 )
return NULL ;
* V_160 = (struct V_100 * ) F_8 ( & V_5 ) -> V_49 ;
return V_5 . V_30 ;
}
int F_128 ( T_3 * V_51 , struct V_1 * V_162 ,
struct V_1 * V_1 )
{
int V_58 , V_90 = V_31 ;
struct V_4 V_5 ;
struct V_100 * V_101 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_41 ( V_51 , V_1 , V_90 ) ;
if ( V_58 )
goto V_25;
V_101 = (struct V_100 * ) F_8 ( & V_5 ) -> V_49 ;
V_101 -> V_1 = F_129 ( V_162 -> V_28 ) ;
V_101 = (struct V_100 * ) ( ( void * ) V_101 + V_130 ) ;
V_101 -> V_1 = 0 ;
V_101 -> V_103 = F_106 (
V_90 - V_130 ,
V_90 ) ;
F_130 ( V_1 , 2 ) ;
V_1 -> V_95 = F_2 ( V_1 ) -> V_120 = V_90 ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_88 * F_131 ( struct V_1 * V_96 ,
const struct V_163 * V_108 ,
struct V_100 * * V_164 ,
int * V_147 )
{
int V_58 ;
struct V_4 V_5 ;
void * V_97 ;
int V_90 ;
if ( F_16 ( V_96 , & V_5 ) )
return NULL ;
F_18 ( & F_2 ( V_96 ) -> V_29 ) ;
if ( ! F_21 ( V_96 ) ) {
* V_147 = 0 ;
goto V_25;
}
V_97 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_130 ;
V_90 = V_31 - V_130 ;
V_58 = F_132 ( V_5 . V_30 , V_97 , V_90 ,
V_96 , V_108 , 0 , V_164 ) ;
if ( V_58 == 1 )
goto V_165;
if ( V_58 < 0 )
goto V_25;
if ( F_1 ( V_96 ) == V_31 )
goto V_25;
V_97 = F_104 ( V_96 , & V_5 ) ;
V_90 = F_1 ( V_96 ) - V_31 ;
V_58 = F_132 ( V_5 . V_30 , V_97 , V_90 ,
V_96 , V_108 , 0 , V_164 ) ;
if ( V_58 == 1 )
goto V_165;
V_25:
F_20 ( V_5 . V_30 ) ;
V_5 . V_30 = NULL ;
V_165:
F_19 ( & F_2 ( V_96 ) -> V_29 ) ;
return V_5 . V_30 ;
}
int F_133 ( T_3 * V_51 ,
struct V_1 * V_96 ,
struct V_100 * V_166 ,
struct V_88 * V_30 ,
int * V_147 )
{
int V_111 , V_90 ;
struct V_4 V_5 ;
void * V_97 ;
V_111 = F_16 ( V_96 , & V_5 ) ;
if ( V_111 )
return V_111 ;
F_42 ( & F_2 ( V_96 ) -> V_29 ) ;
if ( ! F_21 ( V_96 ) ) {
* V_147 = 0 ;
goto V_25;
}
if ( ( void * ) V_166 - ( ( void * ) F_8 ( & V_5 ) -> V_49 ) <
V_31 ) {
V_97 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_130 ;
V_90 = V_31 -
V_130 ;
} else {
V_97 = F_104 ( V_96 , & V_5 ) ;
V_90 = F_1 ( V_96 ) -
V_31 ;
}
V_111 = F_30 ( V_51 , V_30 ) ;
if ( V_111 )
goto V_25;
V_111 = F_134 ( V_51 , V_96 , V_166 , V_30 ,
V_97 , V_90 , 0 ) ;
if ( V_111 )
goto V_25;
F_135 ( V_30 , L_8 ) ;
V_111 = F_103 ( V_51 , V_96 ) ;
if ( F_82 ( V_111 ) )
goto V_25;
F_92 ( V_96 , V_5 . V_30 , V_97 , V_90 ) ;
V_25:
F_43 ( & F_2 ( V_96 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
if ( V_111 != - V_167 )
F_83 ( V_96 -> V_13 , V_111 ) ;
return V_111 ;
}
static inline struct V_100 *
F_136 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned int V_98 ,
void * * V_97 ,
int * V_90 )
{
void * V_168 ;
F_26 ( V_98 > F_1 ( V_1 ) ) ;
if ( V_98 < V_31 ) {
V_168 = ( void * ) F_8 ( V_5 ) -> V_49 ;
* V_90 = V_31 ;
} else {
V_168 = F_104 ( V_1 , V_5 ) ;
V_98 -= V_31 ;
* V_90 = F_1 ( V_1 ) -
V_31 ;
}
if ( V_97 )
* V_97 = V_168 ;
return (struct V_100 * ) ( V_168 + V_98 ) ;
}
int F_137 ( struct V_1 * V_96 , int * V_147 )
{
int V_111 , V_90 ;
struct V_4 V_5 ;
void * V_168 ;
unsigned int V_98 ;
struct V_100 * V_101 ;
int V_58 = 1 ;
V_111 = F_16 ( V_96 , & V_5 ) ;
if ( V_111 ) {
F_138 ( V_96 , L_9 ,
V_111 , V_96 -> V_28 ) ;
return 1 ;
}
F_18 ( & F_2 ( V_96 ) -> V_29 ) ;
if ( ! F_21 ( V_96 ) ) {
* V_147 = 0 ;
goto V_25;
}
V_101 = (struct V_100 * ) F_8 ( & V_5 ) -> V_49 ;
if ( ! F_14 ( V_101 -> V_1 ) ) {
F_52 ( V_96 -> V_13 ,
L_10 ,
V_96 -> V_28 ) ;
V_58 = 1 ;
goto V_25;
}
V_98 = V_130 ;
while ( V_98 < V_96 -> V_95 ) {
V_101 = F_136 ( V_96 , & V_5 , V_98 ,
& V_168 , & V_90 ) ;
if ( F_95 ( V_96 , NULL , V_101 ,
V_5 . V_30 , V_168 ,
V_90 , V_98 ) ) {
F_52 ( V_96 -> V_13 ,
L_11
L_12
L_13 ,
V_96 -> V_28 , F_14 ( V_101 -> V_1 ) ,
F_13 ( V_101 -> V_103 ) , V_101 -> V_104 ,
V_90 ) ;
V_58 = 1 ;
goto V_25;
}
if ( F_14 ( V_101 -> V_1 ) ) {
V_58 = 0 ;
goto V_25;
}
V_98 += F_94 ( V_101 -> V_103 , V_90 ) ;
}
V_25:
F_19 ( & F_2 ( V_96 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_139 ( T_3 * V_51 , struct V_1 * V_1 )
{
int V_58 ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_58 = F_44 ( V_51 , V_1 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_58 ;
}
int F_140 ( struct V_1 * V_1 ,
struct V_169 * V_170 ,
int * V_171 )
{
T_6 V_172 = 0 ;
T_6 V_173 ;
V_20 V_71 = V_174 | V_175 ;
int error = 0 ;
struct V_4 V_5 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
* V_171 = 0 ;
goto V_25;
}
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
goto V_25;
V_172 = V_5 . V_30 -> V_176 << V_1 -> V_13 -> V_177 ;
V_172 += ( char * ) F_8 ( & V_5 ) - V_5 . V_30 -> V_128 ;
V_172 += F_141 ( struct V_10 , V_49 ) ;
V_173 = F_53 ( V_1 ) ;
if ( V_172 )
error = F_142 ( V_170 , 0 , V_172 ,
V_173 , V_71 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return ( error < 0 ? error : 0 ) ;
}
int F_143 ( T_3 * V_51 ,
struct V_1 * V_1 ,
int V_178 )
{
int error ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_10 * V_11 ;
struct V_4 V_5 ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
return error ;
V_11 = F_8 ( & V_5 ) ;
V_7 = F_9 ( V_1 , V_11 ) ;
V_9 = (struct V_8 * ) ( ( void * ) V_11 +
F_2 ( V_1 ) -> V_2 ) ;
if ( F_7 ( V_9 -> V_179 ) +
F_6 ( F_14 ( V_9 -> V_22 ) ) < V_178 ) {
error = - V_55 ;
goto V_25;
}
error = F_117 ( V_51 , V_1 , & V_5 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return error ;
}
void F_144 ( struct V_1 * V_1 , int * V_171 )
{
T_3 * V_51 ;
int V_90 , V_54 , V_72 ;
T_1 V_95 ;
void * V_52 = NULL ;
struct V_33 V_34 = {
. V_35 = { . V_36 = - V_37 , } ,
} ;
struct V_38 V_39 = {
. V_40 = V_41 ,
. V_42 = V_18 ,
} ;
V_72 = F_63 ( V_1 ) ;
V_51 = F_64 ( V_1 , V_72 ) ;
if ( F_65 ( V_51 ) )
return;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
* V_171 = 0 ;
F_75 ( V_51 ) ;
return;
}
if ( F_74 ( V_51 , V_1 ) )
goto V_25;
if ( F_16 ( V_1 , & V_34 . V_5 ) )
goto V_25;
F_42 ( & F_2 ( V_1 ) -> V_180 ) ;
V_95 = V_1 -> V_95 ;
V_90 = F_1 ( V_1 ) ;
F_2 ( V_1 ) -> V_120 = V_95 ;
if ( V_95 < V_90 ) {
if ( V_90 > V_31 ) {
if ( V_33 ( V_1 , & V_39 , & V_34 ) )
goto V_181;
F_26 ( V_34 . V_35 . V_36 ) ;
V_54 = F_14 ( V_34 . V_35 . V_44 -> V_22 ) ;
V_52 = F_118 ( V_54 , V_57 ) ;
if ( ! V_52 )
goto V_181;
if ( F_39 ( V_1 , V_39 . V_40 , V_39 . V_42 ,
V_52 , V_54 ) )
goto V_181;
V_39 . V_52 = V_52 ;
V_39 . V_54 = V_95 > V_31 ?
V_95 - V_31 : 0 ;
if ( F_31 ( V_51 , V_1 , & V_39 , & V_34 ) )
goto V_181;
}
if ( V_95 < V_31 )
memset ( F_8 ( & V_34 . V_5 ) -> V_49 + V_95 , 0 ,
V_31 - V_95 ) ;
F_2 ( V_1 ) -> V_3 = V_95 <
V_31 ?
V_31 : V_95 ;
}
V_181:
F_43 ( & F_2 ( V_1 ) -> V_180 ) ;
V_25:
F_20 ( V_34 . V_5 . V_30 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
F_40 ( V_52 ) ;
if ( V_1 -> V_83 )
F_77 ( V_51 , V_1 ) ;
V_1 -> V_112 = V_1 -> V_113 = F_101 ( V_1 ) ;
F_103 ( V_51 , V_1 ) ;
if ( F_145 ( V_1 ) )
F_146 ( V_51 ) ;
F_75 ( V_51 ) ;
return;
}
int F_147 ( struct V_1 * V_1 )
{
int error , V_72 ;
T_3 * V_51 ;
struct V_4 V_5 ;
if ( ! F_21 ( V_1 ) ) {
F_32 ( V_1 , V_45 ) ;
return 0 ;
}
V_72 = F_63 ( V_1 ) ;
V_5 . V_30 = NULL ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
return error ;
V_51 = F_64 ( V_1 , V_72 ) ;
if ( F_65 ( V_51 ) ) {
error = F_66 ( V_51 ) ;
goto V_182;
}
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
error = F_117 ( V_51 , V_1 , & V_5 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
F_75 ( V_51 ) ;
V_182:
F_20 ( V_5 . V_30 ) ;
return error ;
}
