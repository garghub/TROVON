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
if ( F_44 ( V_1 -> V_13 ) ) {
if ( F_45 ( V_1 -> V_62 ) ||
F_46 ( V_1 -> V_62 ) || F_47 ( V_1 -> V_62 ) ) {
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
static int F_49 ( struct V_1 * V_1 , struct V_63 * V_63 )
{
void * V_64 ;
int V_58 = 0 ;
T_1 V_46 ;
struct V_4 V_5 ;
F_24 ( ! F_50 ( V_63 ) ) ;
F_24 ( ! F_51 ( V_1 ) ) ;
F_24 ( V_63 -> V_65 ) ;
if ( ! F_2 ( V_1 ) -> V_2 ) {
F_52 ( V_1 -> V_13 , L_4 ,
V_1 -> V_28 ) ;
goto V_25;
}
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
goto V_25;
V_46 = F_25 ( T_1 , F_1 ( V_1 ) , F_53 ( V_1 ) ) ;
V_64 = F_54 ( V_63 ) ;
V_58 = F_23 ( V_1 , V_64 , V_46 , & V_5 ) ;
F_55 ( V_63 ) ;
F_56 ( V_64 ) ;
F_57 ( V_63 , V_46 , V_66 ) ;
F_58 ( V_63 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_58 ;
}
int F_59 ( struct V_1 * V_1 , struct V_63 * V_63 )
{
int V_58 = 0 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return - V_67 ;
}
if ( ! V_63 -> V_65 )
V_58 = F_49 ( V_1 , V_63 ) ;
else if ( ! F_60 ( V_63 ) ) {
F_57 ( V_63 , 0 , V_66 ) ;
F_58 ( V_63 ) ;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_61 ( V_63 ) ;
return V_58 >= 0 ? 0 : V_58 ;
}
static int F_62 ( struct V_68 * V_69 ,
struct V_1 * V_1 ,
unsigned V_70 )
{
int V_58 , V_71 ;
T_3 * V_50 = NULL ;
int V_72 = 0 , V_73 = 0 ;
struct V_63 * V_63 = NULL ;
unsigned V_74 , V_75 ;
struct V_4 V_5 ;
if ( ! F_51 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
return 0 ;
}
V_71 = F_63 ( V_1 ) ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_76:
V_50 = F_64 ( V_1 , V_77 , V_71 ) ;
if ( F_65 ( V_50 ) ) {
V_58 = F_66 ( V_50 ) ;
V_50 = NULL ;
goto V_25;
}
V_70 |= V_78 ;
V_63 = F_67 ( V_69 , 0 , V_70 ) ;
if ( ! V_63 ) {
V_58 = - V_79 ;
goto V_25;
}
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
V_73 = 1 ;
if ( ! F_51 ( V_1 ) ) {
V_58 = 0 ;
goto V_25;
}
V_74 = 0 ;
V_75 = F_1 ( V_1 ) ;
if ( ! F_60 ( V_63 ) ) {
V_58 = F_49 ( V_1 , V_63 ) ;
if ( V_58 < 0 )
goto V_25;
}
V_58 = F_43 ( V_50 , V_1 ) ;
if ( V_58 )
goto V_25;
if ( F_68 ( V_1 ) )
V_58 = F_69 ( V_63 , V_74 , V_75 , V_80 ) ;
else
V_58 = F_69 ( V_63 , V_74 , V_75 , V_81 ) ;
if ( ! V_58 && F_70 ( V_1 ) ) {
V_58 = F_71 ( V_50 , F_72 ( V_63 ) ,
V_74 , V_75 , NULL ,
V_82 ) ;
}
if ( V_58 ) {
F_61 ( V_63 ) ;
F_73 ( V_63 ) ;
V_63 = NULL ;
F_74 ( V_50 , V_1 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_73 = 0 ;
F_75 ( V_50 ) ;
V_50 = NULL ;
F_76 ( V_1 ) ;
if ( V_1 -> V_83 )
F_77 ( NULL , V_1 ) ;
}
if ( V_58 == - V_54 && F_78 ( V_1 -> V_13 , & V_72 ) )
goto V_76;
if ( V_63 )
F_79 ( V_63 , V_74 , V_75 ) ;
V_25:
if ( V_63 ) {
F_61 ( V_63 ) ;
F_73 ( V_63 ) ;
}
if ( V_73 )
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_50 )
F_75 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_80 ( struct V_68 * V_69 ,
struct V_1 * V_1 ,
T_2 V_49 , unsigned V_46 ,
unsigned V_70 ,
struct V_63 * * V_84 )
{
int V_58 ;
T_3 * V_50 ;
struct V_63 * V_63 ;
struct V_4 V_5 ;
if ( V_49 + V_46 > F_15 ( V_1 ) )
goto V_85;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_50 = F_64 ( V_1 , V_86 , 1 ) ;
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
goto V_85;
}
V_70 |= V_78 ;
V_63 = F_67 ( V_69 , 0 , V_70 ) ;
if ( ! V_63 ) {
V_58 = - V_79 ;
goto V_25;
}
* V_84 = V_63 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
V_58 = 0 ;
F_61 ( V_63 ) ;
F_73 ( V_63 ) ;
goto V_87;
}
if ( ! F_60 ( V_63 ) ) {
V_58 = F_49 ( V_1 , V_63 ) ;
if ( V_58 < 0 )
goto V_87;
}
V_58 = 1 ;
V_50 = NULL ;
V_87:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
if ( V_50 )
F_75 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
V_85:
return F_62 ( V_69 ,
V_1 , V_70 ) ;
}
int F_81 ( struct V_1 * V_1 , T_2 V_49 , unsigned V_46 ,
unsigned V_88 , struct V_63 * V_63 )
{
int V_58 ;
void * V_64 ;
struct V_4 V_5 ;
if ( F_82 ( V_88 < V_46 ) ) {
if ( ! F_60 ( V_63 ) ) {
V_88 = 0 ;
goto V_25;
}
}
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 ) {
F_83 ( V_1 -> V_13 , V_58 ) ;
V_88 = 0 ;
goto V_25;
}
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
F_24 ( ! F_51 ( V_1 ) ) ;
V_64 = F_54 ( V_63 ) ;
F_26 ( V_1 , & V_5 , V_64 , V_49 , V_46 ) ;
F_56 ( V_64 ) ;
F_58 ( V_63 ) ;
F_84 ( V_63 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_88 ;
}
struct V_89 *
F_85 ( struct V_1 * V_1 ,
unsigned V_46 ,
struct V_63 * V_63 )
{
int V_58 ;
void * V_64 ;
struct V_4 V_5 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 ) {
F_83 ( V_1 -> V_13 , V_58 ) ;
return NULL ;
}
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
V_64 = F_54 ( V_63 ) ;
F_26 ( V_1 , & V_5 , V_64 , 0 , V_46 ) ;
F_56 ( V_64 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_5 . V_30 ;
}
static int F_86 ( struct V_68 * V_69 ,
struct V_1 * V_1 ,
unsigned V_70 ,
void * * V_90 )
{
int V_58 = 0 , V_91 ;
struct V_63 * V_63 ;
V_63 = F_67 ( V_69 , 0 , V_70 ) ;
if ( ! V_63 )
return - V_79 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
goto V_25;
}
V_91 = F_1 ( V_1 ) ;
if ( ! F_60 ( V_63 ) ) {
V_58 = F_49 ( V_1 , V_63 ) ;
if ( V_58 < 0 )
goto V_25;
}
V_58 = F_69 ( V_63 , 0 , V_91 ,
V_92 ) ;
if ( V_58 ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_61 ( V_63 ) ;
F_73 ( V_63 ) ;
F_76 ( V_1 ) ;
return V_58 ;
}
F_87 ( V_63 ) ;
F_58 ( V_63 ) ;
F_31 ( V_1 , V_44 ) ;
* V_90 = ( void * ) V_93 ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_63 ) {
F_61 ( V_63 ) ;
F_73 ( V_63 ) ;
}
return V_58 ;
}
int F_88 ( struct V_68 * V_69 ,
struct V_1 * V_1 ,
T_2 V_49 , unsigned V_46 ,
unsigned V_70 ,
struct V_63 * * V_84 ,
void * * V_90 )
{
int V_58 , V_91 ;
T_3 * V_50 ;
struct V_63 * V_63 ;
struct V_4 V_5 ;
int V_72 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_94:
V_50 = F_64 ( V_1 , V_86 , 1 ) ;
if ( F_65 ( V_50 ) ) {
V_58 = F_66 ( V_50 ) ;
goto V_25;
}
V_91 = F_15 ( V_1 ) ;
V_58 = - V_54 ;
if ( V_91 >= V_49 + V_46 ) {
V_58 = F_40 ( V_50 , V_1 , V_49 + V_46 ) ;
if ( V_58 && V_58 != - V_54 )
goto V_95;
}
V_70 |= V_78 ;
if ( V_58 == - V_54 ) {
V_58 = F_86 ( V_69 ,
V_1 ,
V_70 ,
V_90 ) ;
F_75 ( V_50 ) ;
if ( V_58 == - V_54 &&
F_78 ( V_1 -> V_13 , & V_72 ) )
goto V_94;
goto V_25;
}
V_63 = F_67 ( V_69 , 0 , V_70 ) ;
if ( ! V_63 ) {
V_58 = - V_79 ;
goto V_95;
}
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
V_58 = 0 ;
goto V_96;
}
if ( ! F_60 ( V_63 ) ) {
V_58 = F_49 ( V_1 , V_63 ) ;
if ( V_58 < 0 )
goto V_96;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_84 = V_63 ;
F_20 ( V_5 . V_30 ) ;
return 1 ;
V_96:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_61 ( V_63 ) ;
F_73 ( V_63 ) ;
V_95:
F_75 ( V_50 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_89 ( struct V_1 * V_1 , T_2 V_49 ,
unsigned V_46 , unsigned V_88 ,
struct V_63 * V_63 )
{
int V_97 = 0 ;
V_88 = F_81 ( V_1 , V_49 , V_46 , V_88 , V_63 ) ;
if ( V_49 + V_88 > V_1 -> V_98 ) {
F_90 ( V_1 , V_49 + V_88 ) ;
V_97 = 1 ;
}
F_61 ( V_63 ) ;
F_73 ( V_63 ) ;
if ( V_97 )
F_91 ( V_1 ) ;
return V_88 ;
}
void F_92 ( struct V_1 * V_99 , struct V_89 * V_30 ,
void * V_100 , int V_91 )
{
int V_101 ;
unsigned short V_102 ;
struct V_103 * V_104 = V_100 ;
void * V_105 = V_100 + V_91 ;
F_93 ( L_5 , V_99 -> V_28 ) ;
V_101 = 0 ;
while ( ( void * ) V_104 < V_105 ) {
V_102 = F_94 ( V_104 -> V_106 , V_91 ) ;
F_93 ( L_6 ,
V_101 , V_102 , V_104 -> V_107 , V_104 -> V_41 ,
V_104 -> V_107 , F_14 ( V_104 -> V_1 ) ) ;
if ( F_95 ( V_99 , NULL , V_104 , V_30 ,
V_100 , V_91 , V_101 ) )
F_96 () ;
V_101 += V_102 ;
V_104 = (struct V_103 * ) ( ( char * ) V_104 + V_102 ) ;
}
}
static int F_97 ( T_3 * V_50 ,
struct V_108 * V_109 ,
struct V_110 * V_110 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_100 , int V_91 )
{
struct V_1 * V_99 = F_98 ( V_110 -> V_111 ) ;
int V_112 ;
struct V_103 * V_104 ;
V_112 = F_99 ( V_99 , V_1 , V_5 -> V_30 , V_100 ,
V_91 , V_109 , & V_104 ) ;
if ( V_112 )
return V_112 ;
F_28 ( V_5 -> V_30 , L_2 ) ;
V_112 = F_29 ( V_50 , V_5 -> V_30 ) ;
if ( V_112 )
return V_112 ;
F_100 ( V_99 , V_1 , V_104 , V_91 , V_109 ) ;
F_92 ( V_99 , V_5 -> V_30 , V_100 , V_91 ) ;
V_99 -> V_113 = V_99 -> V_114 = F_101 ( V_99 ) ;
F_102 ( V_99 ) ;
V_99 -> V_115 ++ ;
F_103 ( V_50 , V_99 ) ;
return 1 ;
}
static void * F_104 ( struct V_1 * V_1 ,
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
static void F_105 ( void * V_116 , int V_117 , int V_118 )
{
struct V_103 * V_104 , * V_119 ;
void * V_120 ;
int V_102 ;
V_104 = (struct V_103 * ) V_116 ;
if ( V_117 ) {
V_120 = V_116 + V_117 ;
do {
V_119 = V_104 ;
V_102 = F_94 ( V_104 -> V_106 , V_117 ) ;
V_116 += V_102 ;
V_104 = (struct V_103 * ) V_116 ;
} while ( V_116 < V_120 );
V_119 -> V_106 = F_106 ( V_102 + V_118 -
V_117 , V_118 ) ;
} else {
V_104 -> V_1 = 0 ;
V_104 -> V_106 = F_106 ( V_118 , V_118 ) ;
}
}
static int F_107 ( T_3 * V_50 , struct V_1 * V_99 ,
struct V_4 * V_5 )
{
int V_58 ;
int V_117 = F_2 ( V_99 ) -> V_3 - V_31 ;
int V_118 = F_3 ( V_99 , V_5 ) ;
if ( V_118 - V_117 <= F_108 ( 1 ) )
return - V_54 ;
V_58 = F_36 ( V_50 , V_99 ,
V_118 + V_31 ) ;
if ( V_58 )
return V_58 ;
F_105 ( F_104 ( V_99 , V_5 ) , V_117 ,
F_2 ( V_99 ) -> V_3 -
V_31 ) ;
V_99 -> V_98 = F_2 ( V_99 ) -> V_121 = F_2 ( V_99 ) -> V_3 ;
return 0 ;
}
static void F_109 ( T_3 * V_50 , struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_122 , int V_91 )
{
F_27 ( V_50 , V_1 , V_91 ) ;
F_26 ( V_1 , V_5 , V_122 , 0 , V_91 ) ;
F_22 ( V_1 , V_44 ) ;
}
static int F_110 ( T_3 * V_50 ,
struct V_1 * V_1 ,
struct V_89 * V_123 ,
void * V_122 ,
int V_91 )
{
int V_112 , V_124 = 0 , V_125 = 0 ;
struct V_103 * V_104 ;
struct V_126 * V_127 ;
void * V_128 = V_123 -> V_129 ;
V_104 = (struct V_103 * ) V_128 ;
V_104 = F_111 ( V_1 , V_104 ,
V_1 -> V_13 -> V_130 , V_124 ,
F_14 ( ( (struct V_103 * ) V_122 ) -> V_1 ) , 1 ) ;
V_125 = ( void * ) V_104 - V_128 ;
memcpy ( ( void * ) V_104 , V_122 + V_131 ,
V_91 - V_131 ) ;
if ( F_112 ( V_1 -> V_13 ) )
V_124 = sizeof( struct V_126 ) ;
V_1 -> V_98 = V_1 -> V_13 -> V_130 ;
F_90 ( V_1 , V_1 -> V_13 -> V_130 ) ;
F_2 ( V_1 ) -> V_121 = V_1 -> V_13 -> V_130 ;
F_105 ( V_123 -> V_129 ,
V_91 - V_131 + V_125 ,
V_1 -> V_13 -> V_130 - V_124 ) ;
if ( V_124 ) {
V_127 = F_113 ( V_123 -> V_129 ,
V_1 -> V_13 -> V_130 ) ;
F_114 ( V_127 , V_1 -> V_13 -> V_130 ) ;
}
F_115 ( V_123 ) ;
V_112 = F_116 ( V_50 , V_1 , V_123 ) ;
if ( V_112 )
goto V_25;
F_117 ( V_123 ) ;
V_25:
return V_112 ;
}
static int F_118 ( T_3 * V_50 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
int error ;
void * V_122 = NULL ;
struct V_89 * V_132 = NULL ;
struct V_133 V_134 ;
int V_91 ;
V_91 = F_1 ( V_1 ) ;
V_122 = F_119 ( V_91 , V_57 ) ;
if ( ! V_122 ) {
error = - V_79 ;
goto V_25;
}
error = F_23 ( V_1 , V_122 , V_91 , V_5 ) ;
if ( error < 0 )
goto V_25;
if ( F_45 ( V_1 -> V_62 ) ) {
error = F_120 ( V_1 , V_5 -> V_30 ,
V_122 + V_131 ,
V_91 - V_131 ) ;
if ( error )
goto V_25;
}
error = F_43 ( V_50 , V_1 ) ;
if ( error )
goto V_25;
V_134 . V_135 = 0 ;
V_134 . V_136 = 1 ;
V_134 . V_137 = 0 ;
error = V_133 ( V_50 , V_1 , & V_134 , V_138 ) ;
if ( error < 0 )
goto V_139;
if ( ! ( V_134 . V_137 & V_140 ) ) {
error = - V_141 ;
goto V_139;
}
V_132 = F_121 ( V_1 -> V_13 , V_134 . V_142 ) ;
if ( ! V_132 ) {
error = - V_79 ;
goto V_139;
}
F_122 ( V_132 ) ;
error = F_123 ( V_50 , V_132 ) ;
if ( error ) {
F_124 ( V_132 ) ;
error = - V_141 ;
goto V_139;
}
memset ( V_132 -> V_129 , 0 , V_1 -> V_13 -> V_130 ) ;
if ( ! F_45 ( V_1 -> V_62 ) ) {
memcpy ( V_132 -> V_129 , V_122 , V_91 ) ;
F_115 ( V_132 ) ;
error = F_125 ( V_50 ,
V_1 , V_132 ) ;
} else {
error = F_110 ( V_50 , V_1 , V_132 ,
V_122 , V_91 ) ;
}
F_124 ( V_132 ) ;
V_139:
if ( error )
F_109 ( V_50 , V_1 , V_5 , V_122 , V_91 ) ;
V_25:
F_20 ( V_132 ) ;
F_39 ( V_122 ) ;
return error ;
}
int F_126 ( T_3 * V_50 , struct V_108 * V_109 ,
struct V_110 * V_110 , struct V_1 * V_1 )
{
int V_58 , V_91 ;
void * V_100 ;
struct V_4 V_5 ;
struct V_1 * V_99 = F_98 ( V_110 -> V_111 ) ;
V_58 = F_16 ( V_99 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_41 ( & F_2 ( V_99 ) -> V_29 ) ;
if ( ! F_51 ( V_99 ) )
goto V_25;
V_100 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_131 ;
V_91 = V_31 - V_131 ;
V_58 = F_97 ( V_50 , V_109 , V_110 , V_1 , & V_5 ,
V_100 , V_91 ) ;
if ( V_58 != - V_54 )
goto V_25;
V_91 = F_2 ( V_99 ) -> V_3 -
V_31 ;
if ( ! V_91 ) {
V_58 = F_107 ( V_50 , V_99 , & V_5 ) ;
if ( V_58 && V_58 != - V_54 )
goto V_25;
V_91 = F_2 ( V_99 ) -> V_3 -
V_31 ;
}
if ( V_91 ) {
V_100 = F_104 ( V_99 , & V_5 ) ;
V_58 = F_97 ( V_50 , V_109 , V_110 ,
V_1 , & V_5 , V_100 ,
V_91 ) ;
if ( V_58 != - V_54 )
goto V_25;
}
V_58 = F_118 ( V_50 , V_99 , & V_5 ) ;
V_25:
F_103 ( V_50 , V_99 ) ;
F_42 ( & F_2 ( V_99 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_127 ( struct V_143 * V_144 ,
struct V_1 * V_99 , T_4 V_145 ,
struct V_146 * V_147 ,
V_20 V_148 , V_20 V_149 ,
int * V_150 )
{
int V_112 = 0 , V_151 = 0 ;
unsigned int V_152 ;
int V_49 ;
struct V_103 * V_104 ;
struct V_1 * V_1 = F_128 ( V_144 ) ;
int V_58 , V_91 = 0 ;
struct V_4 V_5 ;
void * V_153 = NULL ;
struct V_103 V_154 ;
struct V_155 V_156 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_150 = 0 ;
goto V_25;
}
V_91 = F_1 ( V_1 ) ;
V_153 = F_119 ( V_91 , V_57 ) ;
if ( ! V_153 ) {
V_58 = - V_79 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_23 ( V_1 , V_153 , V_91 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_49 = 0 ;
V_152 = F_14 ( ( (struct V_103 * ) V_153 ) -> V_1 ) ;
while ( V_49 < V_91 ) {
if ( V_49 == 0 ) {
V_154 . V_1 = F_129 ( V_1 -> V_28 ) ;
V_154 . V_107 = 1 ;
strcpy ( V_154 . V_41 , L_7 ) ;
V_154 . V_106 = F_106 (
F_108 ( V_154 . V_107 ) ,
V_91 ) ;
F_130 ( V_1 -> V_13 , & V_154 , V_157 ) ;
V_104 = & V_154 ;
V_49 = V_158 ;
} else if ( V_49 == V_158 ) {
V_154 . V_1 = F_129 ( V_152 ) ;
V_154 . V_107 = 2 ;
strcpy ( V_154 . V_41 , L_8 ) ;
V_154 . V_106 = F_106 (
F_108 ( V_154 . V_107 ) ,
V_91 ) ;
F_130 ( V_1 -> V_13 , & V_154 , V_157 ) ;
V_104 = & V_154 ;
V_49 = V_131 ;
} else {
V_104 = (struct V_103 * ) ( V_153 + V_49 ) ;
V_49 += F_94 ( V_104 -> V_106 , V_91 ) ;
if ( F_95 ( V_1 , V_144 , V_104 ,
V_5 . V_30 , V_153 ,
V_91 , V_49 ) ) {
V_58 = V_151 ;
goto V_25;
}
}
F_131 ( V_104 -> V_41 , V_104 -> V_107 , V_147 ) ;
if ( ( V_147 -> V_159 < V_148 ) ||
( ( V_147 -> V_159 == V_148 ) &&
( V_147 -> V_160 < V_149 ) ) )
continue;
if ( V_104 -> V_1 == 0 )
continue;
V_156 . V_41 = V_104 -> V_41 ;
V_156 . V_46 = V_104 -> V_107 ;
V_112 = F_132 ( V_144 , V_147 -> V_159 ,
V_147 -> V_160 , V_104 , & V_156 ) ;
if ( V_112 ) {
V_151 = V_112 ;
goto V_25;
}
V_151 ++ ;
}
V_58 = V_151 ;
V_25:
F_39 ( V_153 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_133 ( struct V_143 * V_143 ,
struct V_161 * V_162 ,
int * V_150 )
{
unsigned int V_101 , V_152 ;
int V_38 ;
struct V_103 * V_104 ;
struct V_163 * V_164 ;
struct V_1 * V_1 = F_128 ( V_143 ) ;
int V_58 , V_91 = 0 ;
struct V_4 V_5 ;
void * V_153 = NULL ;
int V_165 , V_166 , V_167 , V_168 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_150 = 0 ;
goto V_25;
}
V_91 = F_1 ( V_1 ) ;
V_153 = F_119 ( V_91 , V_57 ) ;
if ( ! V_153 ) {
V_58 = - V_79 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_23 ( V_1 , V_153 , V_91 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_58 = 0 ;
V_164 = V_1 -> V_13 ;
V_152 = F_14 ( ( (struct V_103 * ) V_153 ) -> V_1 ) ;
V_101 = V_162 -> V_49 ;
V_165 = F_108 ( 1 ) ;
V_166 = V_165 + F_108 ( 2 ) ;
V_167 = V_166 - V_131 ;
V_168 = V_167 + V_91 ;
if ( V_143 -> V_169 != V_1 -> V_115 ) {
for ( V_38 = 0 ; V_38 < V_168 && V_38 < V_101 ; ) {
if ( ! V_38 ) {
V_38 = V_165 ;
continue;
} else if ( V_38 == V_165 ) {
V_38 = V_166 ;
continue;
}
V_104 = (struct V_103 * )
( V_153 + V_38 - V_167 ) ;
if ( F_94 ( V_104 -> V_106 , V_168 )
< F_108 ( 1 ) )
break;
V_38 += F_94 ( V_104 -> V_106 ,
V_168 ) ;
}
V_101 = V_38 ;
V_162 -> V_49 = V_101 ;
V_143 -> V_169 = V_1 -> V_115 ;
}
while ( V_162 -> V_49 < V_168 ) {
if ( V_162 -> V_49 == 0 ) {
if ( ! F_134 ( V_162 , L_7 , 1 , V_1 -> V_28 , V_170 ) )
goto V_25;
V_162 -> V_49 = V_165 ;
continue;
}
if ( V_162 -> V_49 == V_165 ) {
if ( ! F_134 ( V_162 , L_8 , 2 , V_152 , V_170 ) )
goto V_25;
V_162 -> V_49 = V_166 ;
continue;
}
V_104 = (struct V_103 * )
( V_153 + V_162 -> V_49 - V_167 ) ;
if ( F_95 ( V_1 , V_143 , V_104 , V_5 . V_30 , V_153 ,
V_168 , V_162 -> V_49 ) )
goto V_25;
if ( F_14 ( V_104 -> V_1 ) ) {
if ( ! F_134 ( V_162 , V_104 -> V_41 , V_104 -> V_107 ,
F_14 ( V_104 -> V_1 ) ,
F_135 ( V_164 , V_104 -> V_171 ) ) )
goto V_25;
}
V_162 -> V_49 += F_94 ( V_104 -> V_106 , V_168 ) ;
}
V_25:
F_39 ( V_153 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_89 * F_136 ( struct V_1 * V_1 ,
struct V_103 * * V_172 ,
int * V_173 )
{
struct V_4 V_5 ;
* V_173 = F_16 ( V_1 , & V_5 ) ;
if ( * V_173 )
return NULL ;
* V_172 = (struct V_103 * ) F_8 ( & V_5 ) -> V_48 ;
return V_5 . V_30 ;
}
int F_137 ( T_3 * V_50 , struct V_1 * V_174 ,
struct V_1 * V_1 )
{
int V_58 , V_91 = V_31 ;
struct V_4 V_5 ;
struct V_103 * V_104 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_40 ( V_50 , V_1 , V_91 ) ;
if ( V_58 )
goto V_25;
V_104 = (struct V_103 * ) F_8 ( & V_5 ) -> V_48 ;
V_104 -> V_1 = F_129 ( V_174 -> V_28 ) ;
V_104 = (struct V_103 * ) ( ( void * ) V_104 + V_131 ) ;
V_104 -> V_1 = 0 ;
V_104 -> V_106 = F_106 (
V_91 - V_131 ,
V_91 ) ;
F_138 ( V_1 , 2 ) ;
V_1 -> V_98 = F_2 ( V_1 ) -> V_121 = V_91 ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_89 * F_139 ( struct V_1 * V_99 ,
struct V_108 * V_109 ,
const struct V_175 * V_176 ,
struct V_103 * * V_177 ,
int * V_150 )
{
int V_58 ;
struct V_4 V_5 ;
void * V_100 ;
int V_91 ;
if ( F_16 ( V_99 , & V_5 ) )
return NULL ;
F_18 ( & F_2 ( V_99 ) -> V_29 ) ;
if ( ! F_51 ( V_99 ) ) {
* V_150 = 0 ;
goto V_25;
}
V_100 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_131 ;
V_91 = V_31 - V_131 ;
V_58 = F_140 ( V_5 . V_30 , V_100 , V_91 ,
V_99 , V_109 , V_176 , 0 , V_177 ) ;
if ( V_58 == 1 )
goto V_178;
if ( V_58 < 0 )
goto V_25;
if ( F_1 ( V_99 ) == V_31 )
goto V_25;
V_100 = F_104 ( V_99 , & V_5 ) ;
V_91 = F_1 ( V_99 ) - V_31 ;
V_58 = F_140 ( V_5 . V_30 , V_100 , V_91 ,
V_99 , V_109 , V_176 , 0 , V_177 ) ;
if ( V_58 == 1 )
goto V_178;
V_25:
F_20 ( V_5 . V_30 ) ;
V_5 . V_30 = NULL ;
V_178:
F_19 ( & F_2 ( V_99 ) -> V_29 ) ;
return V_5 . V_30 ;
}
int F_141 ( T_3 * V_50 ,
struct V_1 * V_99 ,
struct V_103 * V_179 ,
struct V_89 * V_30 ,
int * V_150 )
{
int V_112 , V_91 ;
struct V_4 V_5 ;
void * V_100 ;
V_112 = F_16 ( V_99 , & V_5 ) ;
if ( V_112 )
return V_112 ;
F_41 ( & F_2 ( V_99 ) -> V_29 ) ;
if ( ! F_51 ( V_99 ) ) {
* V_150 = 0 ;
goto V_25;
}
if ( ( void * ) V_179 - ( ( void * ) F_8 ( & V_5 ) -> V_48 ) <
V_31 ) {
V_100 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_131 ;
V_91 = V_31 -
V_131 ;
} else {
V_100 = F_104 ( V_99 , & V_5 ) ;
V_91 = F_1 ( V_99 ) -
V_31 ;
}
F_28 ( V_30 , L_2 ) ;
V_112 = F_29 ( V_50 , V_30 ) ;
if ( V_112 )
goto V_25;
V_112 = F_142 ( V_50 , V_99 , V_179 , V_30 ,
V_100 , V_91 , 0 ) ;
if ( V_112 )
goto V_25;
F_28 ( V_30 , L_9 ) ;
V_112 = F_103 ( V_50 , V_99 ) ;
if ( F_82 ( V_112 ) )
goto V_25;
F_92 ( V_99 , V_5 . V_30 , V_100 , V_91 ) ;
V_25:
F_42 ( & F_2 ( V_99 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
if ( V_112 != - V_180 )
F_83 ( V_99 -> V_13 , V_112 ) ;
return V_112 ;
}
static inline struct V_103 *
F_143 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned int V_101 ,
void * * V_100 ,
int * V_91 )
{
void * V_181 ;
F_24 ( V_101 > F_1 ( V_1 ) ) ;
if ( V_101 < V_31 ) {
V_181 = ( void * ) F_8 ( V_5 ) -> V_48 ;
* V_91 = V_31 ;
} else {
V_181 = F_104 ( V_1 , V_5 ) ;
V_101 -= V_31 ;
* V_91 = F_1 ( V_1 ) -
V_31 ;
}
if ( V_100 )
* V_100 = V_181 ;
return (struct V_103 * ) ( V_181 + V_101 ) ;
}
int F_144 ( struct V_1 * V_99 , int * V_150 )
{
int V_112 , V_91 ;
struct V_4 V_5 ;
void * V_181 ;
unsigned int V_101 ;
struct V_103 * V_104 ;
int V_58 = 1 ;
V_112 = F_16 ( V_99 , & V_5 ) ;
if ( V_112 ) {
F_145 ( V_99 , L_10 ,
V_112 , V_99 -> V_28 ) ;
return 1 ;
}
F_18 ( & F_2 ( V_99 ) -> V_29 ) ;
if ( ! F_51 ( V_99 ) ) {
* V_150 = 0 ;
goto V_25;
}
V_104 = (struct V_103 * ) F_8 ( & V_5 ) -> V_48 ;
if ( ! F_14 ( V_104 -> V_1 ) ) {
F_52 ( V_99 -> V_13 ,
L_11 ,
V_99 -> V_28 ) ;
V_58 = 1 ;
goto V_25;
}
V_101 = V_131 ;
while ( V_101 < V_99 -> V_98 ) {
V_104 = F_143 ( V_99 , & V_5 , V_101 ,
& V_181 , & V_91 ) ;
if ( F_95 ( V_99 , NULL , V_104 ,
V_5 . V_30 , V_181 ,
V_91 , V_101 ) ) {
F_52 ( V_99 -> V_13 ,
L_12
L_13
L_14 ,
V_99 -> V_28 , F_14 ( V_104 -> V_1 ) ,
F_13 ( V_104 -> V_106 ) , V_104 -> V_107 ,
V_91 ) ;
V_58 = 1 ;
goto V_25;
}
if ( F_14 ( V_104 -> V_1 ) ) {
V_58 = 0 ;
goto V_25;
}
V_101 += F_94 ( V_104 -> V_106 , V_91 ) ;
}
V_25:
F_19 ( & F_2 ( V_99 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_146 ( T_3 * V_50 , struct V_1 * V_1 )
{
int V_58 ;
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
V_58 = F_43 ( V_50 , V_1 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_58 ;
}
int F_147 ( struct V_1 * V_1 ,
struct V_182 * V_183 ,
int * V_184 , T_5 V_185 , T_5 V_46 )
{
T_5 V_186 = 0 ;
T_5 V_187 ;
V_20 V_70 = V_188 | V_189 |
V_190 ;
int error = 0 ;
struct V_4 V_5 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
* V_184 = 0 ;
goto V_25;
}
V_187 = F_25 ( T_1 , F_1 ( V_1 ) ,
F_53 ( V_1 ) ) ;
if ( V_185 >= V_187 )
goto V_25;
if ( V_185 + V_46 < V_187 )
V_187 = V_185 + V_46 ;
V_187 -= V_185 ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
goto V_25;
V_186 = ( T_5 ) V_5 . V_30 -> V_191 << V_1 -> V_13 -> V_192 ;
V_186 += ( char * ) F_8 ( & V_5 ) - V_5 . V_30 -> V_129 ;
V_186 += F_148 ( struct V_10 , V_48 ) ;
if ( V_186 )
error = F_149 ( V_183 , V_185 , V_186 ,
V_187 , V_70 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return ( error < 0 ? error : 0 ) ;
}
int F_150 ( T_3 * V_50 ,
struct V_1 * V_1 ,
int V_193 )
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
if ( F_7 ( V_9 -> V_194 ) +
F_6 ( F_14 ( V_9 -> V_22 ) ) < V_193 ) {
error = - V_54 ;
goto V_25;
}
error = F_118 ( V_50 , V_1 , & V_5 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return error ;
}
void F_151 ( struct V_1 * V_1 , int * V_184 )
{
T_3 * V_50 ;
int V_91 , V_53 , V_71 ;
T_1 V_98 ;
void * V_51 = NULL ;
struct V_32 V_33 = {
. V_34 = { . V_35 = - V_36 , } ,
} ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_18 ,
} ;
V_71 = F_63 ( V_1 ) ;
V_50 = F_64 ( V_1 , V_86 , V_71 ) ;
if ( F_65 ( V_50 ) )
return;
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
* V_184 = 0 ;
F_75 ( V_50 ) ;
return;
}
if ( F_74 ( V_50 , V_1 ) )
goto V_25;
if ( F_16 ( V_1 , & V_33 . V_5 ) )
goto V_25;
F_41 ( & F_2 ( V_1 ) -> V_195 ) ;
V_98 = V_1 -> V_98 ;
V_91 = F_1 ( V_1 ) ;
F_2 ( V_1 ) -> V_121 = V_98 ;
if ( V_98 < V_91 ) {
if ( V_91 > V_31 ) {
if ( V_32 ( V_1 , & V_38 , & V_33 ) )
goto V_196;
F_24 ( V_33 . V_34 . V_35 ) ;
V_53 = F_14 ( V_33 . V_34 . V_43 -> V_22 ) ;
V_51 = F_119 ( V_53 , V_57 ) ;
if ( ! V_51 )
goto V_196;
if ( F_38 ( V_1 , V_38 . V_39 , V_38 . V_41 ,
V_51 , V_53 ) )
goto V_196;
V_38 . V_51 = V_51 ;
V_38 . V_53 = V_98 > V_31 ?
V_98 - V_31 : 0 ;
if ( F_30 ( V_50 , V_1 , & V_38 , & V_33 ) )
goto V_196;
}
if ( V_98 < V_31 ) {
void * V_197 = ( void * ) F_8 ( & V_33 . V_5 ) -> V_48 ;
memset ( V_197 + V_98 , 0 ,
V_31 - V_98 ) ;
}
F_2 ( V_1 ) -> V_3 = V_98 <
V_31 ?
V_31 : V_98 ;
}
V_196:
F_42 ( & F_2 ( V_1 ) -> V_195 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
F_39 ( V_51 ) ;
if ( V_1 -> V_83 )
F_77 ( V_50 , V_1 ) ;
V_1 -> V_113 = V_1 -> V_114 = F_101 ( V_1 ) ;
F_103 ( V_50 , V_1 ) ;
if ( F_152 ( V_1 ) )
F_153 ( V_50 ) ;
F_75 ( V_50 ) ;
return;
}
int F_154 ( struct V_1 * V_1 )
{
int error , V_71 ;
T_3 * V_50 ;
struct V_4 V_5 ;
if ( ! F_51 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
return 0 ;
}
V_71 = F_63 ( V_1 ) ;
V_5 . V_30 = NULL ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
return error ;
V_50 = F_64 ( V_1 , V_77 , V_71 ) ;
if ( F_65 ( V_50 ) ) {
error = F_66 ( V_50 ) ;
goto V_198;
}
F_41 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_51 ( V_1 ) ) {
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
error = F_118 ( V_50 , V_1 , & V_5 ) ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
F_75 ( V_50 ) ;
V_198:
F_20 ( V_5 . V_30 ) ;
return error ;
}
