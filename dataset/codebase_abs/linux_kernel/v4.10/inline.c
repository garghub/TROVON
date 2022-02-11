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
F_34 ( V_1 ) ;
F_35 ( V_33 . V_5 . V_30 ) ;
error = F_36 ( V_50 , V_1 , & V_33 . V_5 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
return error ;
}
static int F_37 ( T_3 * V_50 , struct V_1 * V_1 ,
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
V_51 = F_38 ( V_46 , V_57 ) ;
if ( ! V_51 ) {
error = - V_58 ;
goto V_25;
}
error = F_39 ( V_1 , V_38 . V_39 , V_38 . V_41 ,
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
F_35 ( V_33 . V_5 . V_30 ) ;
error = F_36 ( V_50 , V_1 , & V_33 . V_5 ) ;
V_25:
F_40 ( V_51 ) ;
F_20 ( V_33 . V_5 . V_30 ) ;
return error ;
}
static int F_41 ( T_3 * V_50 , struct V_1 * V_1 ,
unsigned int V_46 )
{
int V_59 , V_60 ;
struct V_61 * V_62 = F_2 ( V_1 ) ;
if ( ! F_5 ( V_1 , V_44 ) )
return - V_54 ;
V_60 = F_15 ( V_1 ) ;
if ( V_60 < V_46 )
return - V_54 ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_62 -> V_2 )
V_59 = F_37 ( V_50 , V_1 , V_46 ) ;
else
V_59 = F_27 ( V_50 , V_1 , V_46 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_59 ;
}
static int F_44 ( T_3 * V_50 ,
struct V_1 * V_1 )
{
struct V_61 * V_62 = F_2 ( V_1 ) ;
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
if ( ! V_62 -> V_2 )
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
if ( F_45 ( V_1 -> V_13 ) ) {
if ( F_46 ( V_1 -> V_63 ) ||
F_47 ( V_1 -> V_63 ) || F_48 ( V_1 -> V_63 ) ) {
F_33 ( V_1 , V_55 ) ;
F_49 ( V_50 , V_1 ) ;
}
}
F_32 ( V_1 , V_56 ) ;
F_34 ( V_1 ) ;
F_35 ( V_33 . V_5 . V_30 ) ;
error = F_36 ( V_50 , V_1 , & V_33 . V_5 ) ;
F_2 ( V_1 ) -> V_2 = 0 ;
F_2 ( V_1 ) -> V_3 = 0 ;
F_31 ( V_1 , V_44 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
if ( error == - V_36 )
error = 0 ;
return error ;
}
static int F_50 ( struct V_1 * V_1 , struct V_64 * V_64 )
{
void * V_65 ;
int V_59 = 0 ;
T_1 V_46 ;
struct V_4 V_5 ;
F_24 ( ! F_51 ( V_64 ) ) ;
F_24 ( ! F_52 ( V_1 ) ) ;
F_24 ( V_64 -> V_66 ) ;
if ( ! F_2 ( V_1 ) -> V_2 ) {
F_53 ( V_1 -> V_13 , L_4 ,
V_1 -> V_28 ) ;
goto V_25;
}
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
goto V_25;
V_46 = F_25 ( T_1 , F_1 ( V_1 ) , F_54 ( V_1 ) ) ;
V_65 = F_55 ( V_64 ) ;
V_59 = F_23 ( V_1 , V_65 , V_46 , & V_5 ) ;
F_56 ( V_64 ) ;
F_57 ( V_65 ) ;
F_58 ( V_64 , V_46 , V_67 ) ;
F_59 ( V_64 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_59 ;
}
int F_60 ( struct V_1 * V_1 , struct V_64 * V_64 )
{
int V_59 = 0 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return - V_68 ;
}
if ( ! V_64 -> V_66 )
V_59 = F_50 ( V_1 , V_64 ) ;
else if ( ! F_61 ( V_64 ) ) {
F_58 ( V_64 , 0 , V_67 ) ;
F_59 ( V_64 ) ;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_62 ( V_64 ) ;
return V_59 >= 0 ? 0 : V_59 ;
}
static int F_63 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
unsigned V_71 )
{
int V_59 , V_72 ;
T_3 * V_50 = NULL ;
int V_73 = 0 , V_74 = 0 ;
struct V_64 * V_64 = NULL ;
unsigned V_75 , V_76 ;
struct V_4 V_5 ;
if ( ! F_52 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
return 0 ;
}
V_72 = F_64 ( V_1 ) ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_77:
V_50 = F_65 ( V_1 , V_78 , V_72 ) ;
if ( F_66 ( V_50 ) ) {
V_59 = F_67 ( V_50 ) ;
V_50 = NULL ;
goto V_25;
}
V_71 |= V_79 ;
V_64 = F_68 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_59 = - V_58 ;
goto V_25;
}
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_74 = 1 ;
if ( ! F_52 ( V_1 ) ) {
V_59 = 0 ;
goto V_25;
}
V_75 = 0 ;
V_76 = F_1 ( V_1 ) ;
if ( ! F_61 ( V_64 ) ) {
V_59 = F_50 ( V_1 , V_64 ) ;
if ( V_59 < 0 )
goto V_25;
}
V_59 = F_44 ( V_50 , V_1 ) ;
if ( V_59 )
goto V_25;
if ( F_69 ( V_1 ) ) {
V_59 = F_70 ( V_64 , V_75 , V_76 ,
V_80 ) ;
} else
V_59 = F_70 ( V_64 , V_75 , V_76 , V_81 ) ;
if ( ! V_59 && F_71 ( V_1 ) ) {
V_59 = F_72 ( V_50 , F_73 ( V_64 ) ,
V_75 , V_76 , NULL ,
V_82 ) ;
}
if ( V_59 ) {
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
V_64 = NULL ;
F_75 ( V_50 , V_1 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
V_74 = 0 ;
F_76 ( V_50 ) ;
V_50 = NULL ;
F_77 ( V_1 ) ;
if ( V_1 -> V_83 )
F_78 ( NULL , V_1 ) ;
}
if ( V_59 == - V_54 && F_79 ( V_1 -> V_13 , & V_73 ) )
goto V_77;
if ( V_64 )
F_80 ( V_64 , V_75 , V_76 ) ;
V_25:
if ( V_64 ) {
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
}
if ( V_74 )
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_50 )
F_76 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_81 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
T_2 V_49 , unsigned V_46 ,
unsigned V_71 ,
struct V_64 * * V_84 )
{
int V_59 ;
T_3 * V_50 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
if ( V_49 + V_46 > F_15 ( V_1 ) )
goto V_85;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_50 = F_65 ( V_1 , V_86 , 1 ) ;
if ( F_66 ( V_50 ) ) {
V_59 = F_67 ( V_50 ) ;
V_50 = NULL ;
goto V_25;
}
V_59 = F_41 ( V_50 , V_1 , V_49 + V_46 ) ;
if ( V_59 && V_59 != - V_54 )
goto V_25;
if ( V_59 == - V_54 ) {
F_76 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
goto V_85;
}
V_71 |= V_79 ;
V_64 = F_68 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_59 = - V_58 ;
goto V_25;
}
* V_84 = V_64 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
V_59 = 0 ;
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
goto V_87;
}
if ( ! F_61 ( V_64 ) ) {
V_59 = F_50 ( V_1 , V_64 ) ;
if ( V_59 < 0 )
goto V_87;
}
V_59 = 1 ;
V_50 = NULL ;
V_87:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
if ( V_50 )
F_76 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
V_85:
return F_63 ( V_70 ,
V_1 , V_71 ) ;
}
int F_82 ( struct V_1 * V_1 , T_2 V_49 , unsigned V_46 ,
unsigned V_88 , struct V_64 * V_64 )
{
int V_59 ;
void * V_65 ;
struct V_4 V_5 ;
if ( F_83 ( V_88 < V_46 ) ) {
if ( ! F_61 ( V_64 ) ) {
V_88 = 0 ;
goto V_25;
}
}
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 ) {
F_84 ( V_1 -> V_13 , V_59 ) ;
V_88 = 0 ;
goto V_25;
}
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
F_24 ( ! F_52 ( V_1 ) ) ;
V_65 = F_55 ( V_64 ) ;
F_26 ( V_1 , & V_5 , V_65 , V_49 , V_46 ) ;
F_57 ( V_65 ) ;
F_59 ( V_64 ) ;
F_85 ( V_64 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_88 ;
}
struct V_89 *
F_86 ( struct V_1 * V_1 ,
unsigned V_46 ,
struct V_64 * V_64 )
{
int V_59 ;
void * V_65 ;
struct V_4 V_5 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 ) {
F_84 ( V_1 -> V_13 , V_59 ) ;
return NULL ;
}
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_65 = F_55 ( V_64 ) ;
F_26 ( V_1 , & V_5 , V_65 , 0 , V_46 ) ;
F_57 ( V_65 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_5 . V_30 ;
}
static int F_87 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
unsigned V_71 ,
void * * V_90 )
{
int V_59 = 0 , V_91 ;
struct V_64 * V_64 ;
V_64 = F_68 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 )
return - V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
goto V_25;
}
V_91 = F_1 ( V_1 ) ;
if ( ! F_61 ( V_64 ) ) {
V_59 = F_50 ( V_1 , V_64 ) ;
if ( V_59 < 0 )
goto V_25;
}
V_59 = F_70 ( V_64 , 0 , V_91 ,
V_92 ) ;
if ( V_59 ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
F_77 ( V_1 ) ;
return V_59 ;
}
F_88 ( V_64 ) ;
F_59 ( V_64 ) ;
F_31 ( V_1 , V_44 ) ;
* V_90 = ( void * ) V_93 ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_64 ) {
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
}
return V_59 ;
}
int F_89 ( struct V_69 * V_70 ,
struct V_1 * V_1 ,
T_2 V_49 , unsigned V_46 ,
unsigned V_71 ,
struct V_64 * * V_84 ,
void * * V_90 )
{
int V_59 , V_91 ;
T_3 * V_50 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
int V_73 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_94:
V_50 = F_65 ( V_1 , V_86 , 1 ) ;
if ( F_66 ( V_50 ) ) {
V_59 = F_67 ( V_50 ) ;
goto V_25;
}
V_91 = F_15 ( V_1 ) ;
V_59 = - V_54 ;
if ( V_91 >= V_49 + V_46 ) {
V_59 = F_41 ( V_50 , V_1 , V_49 + V_46 ) ;
if ( V_59 && V_59 != - V_54 )
goto V_95;
}
V_71 |= V_79 ;
if ( V_59 == - V_54 ) {
V_59 = F_87 ( V_70 ,
V_1 ,
V_71 ,
V_90 ) ;
F_76 ( V_50 ) ;
if ( V_59 == - V_54 &&
F_79 ( V_1 -> V_13 , & V_73 ) )
goto V_94;
goto V_25;
}
V_64 = F_68 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_59 = - V_58 ;
goto V_95;
}
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
V_59 = 0 ;
goto V_96;
}
if ( ! F_61 ( V_64 ) ) {
V_59 = F_50 ( V_1 , V_64 ) ;
if ( V_59 < 0 )
goto V_96;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_84 = V_64 ;
F_20 ( V_5 . V_30 ) ;
return 1 ;
V_96:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
V_95:
F_76 ( V_50 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_90 ( struct V_1 * V_1 , T_2 V_49 ,
unsigned V_46 , unsigned V_88 ,
struct V_64 * V_64 )
{
int V_97 = 0 ;
V_88 = F_82 ( V_1 , V_49 , V_46 , V_88 , V_64 ) ;
if ( V_49 + V_88 > V_1 -> V_98 ) {
F_91 ( V_1 , V_49 + V_88 ) ;
V_97 = 1 ;
}
F_62 ( V_64 ) ;
F_74 ( V_64 ) ;
if ( V_97 )
F_92 ( V_1 ) ;
return V_88 ;
}
void F_93 ( struct V_1 * V_99 , struct V_89 * V_30 ,
void * V_100 , int V_91 )
{
int V_101 ;
unsigned short V_102 ;
struct V_103 * V_104 = V_100 ;
void * V_105 = V_100 + V_91 ;
F_94 ( L_5 , V_99 -> V_28 ) ;
V_101 = 0 ;
while ( ( void * ) V_104 < V_105 ) {
V_102 = F_95 ( V_104 -> V_106 , V_91 ) ;
F_94 ( L_6 ,
V_101 , V_102 , V_104 -> V_107 , V_104 -> V_41 ,
V_104 -> V_107 , F_14 ( V_104 -> V_1 ) ) ;
if ( F_96 ( V_99 , NULL , V_104 , V_30 ,
V_100 , V_91 , V_101 ) )
F_97 () ;
V_101 += V_102 ;
V_104 = (struct V_103 * ) ( ( char * ) V_104 + V_102 ) ;
}
}
static int F_98 ( T_3 * V_50 ,
struct V_108 * V_109 ,
struct V_1 * V_99 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_100 , int V_91 )
{
int V_110 ;
struct V_103 * V_104 ;
V_110 = F_99 ( V_99 , V_1 , V_5 -> V_30 , V_100 ,
V_91 , V_109 , & V_104 ) ;
if ( V_110 )
return V_110 ;
F_28 ( V_5 -> V_30 , L_2 ) ;
V_110 = F_29 ( V_50 , V_5 -> V_30 ) ;
if ( V_110 )
return V_110 ;
F_100 ( V_99 , V_1 , V_104 , V_91 , V_109 ) ;
F_93 ( V_99 , V_5 -> V_30 , V_100 , V_91 ) ;
V_99 -> V_111 = V_99 -> V_112 = F_101 ( V_99 ) ;
F_102 ( V_99 ) ;
V_99 -> V_113 ++ ;
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
static void F_105 ( void * V_114 , int V_115 , int V_116 )
{
struct V_103 * V_104 , * V_117 ;
void * V_118 ;
int V_102 ;
V_104 = (struct V_103 * ) V_114 ;
if ( V_115 ) {
V_118 = V_114 + V_115 ;
do {
V_117 = V_104 ;
V_102 = F_95 ( V_104 -> V_106 , V_115 ) ;
V_114 += V_102 ;
V_104 = (struct V_103 * ) V_114 ;
} while ( V_114 < V_118 );
V_117 -> V_106 = F_106 ( V_102 + V_116 -
V_115 , V_116 ) ;
} else {
V_104 -> V_1 = 0 ;
V_104 -> V_106 = F_106 ( V_116 , V_116 ) ;
}
}
static int F_107 ( T_3 * V_50 , struct V_1 * V_99 ,
struct V_4 * V_5 )
{
int V_59 ;
int V_115 = F_2 ( V_99 ) -> V_3 - V_31 ;
int V_116 = F_3 ( V_99 , V_5 ) ;
if ( V_116 - V_115 <= F_108 ( 1 ) )
return - V_54 ;
V_59 = F_37 ( V_50 , V_99 ,
V_116 + V_31 ) ;
if ( V_59 )
return V_59 ;
F_105 ( F_104 ( V_99 , V_5 ) , V_115 ,
F_2 ( V_99 ) -> V_3 -
V_31 ) ;
V_99 -> V_98 = F_2 ( V_99 ) -> V_119 = F_2 ( V_99 ) -> V_3 ;
return 0 ;
}
static void F_109 ( T_3 * V_50 , struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_120 , int V_91 )
{
F_27 ( V_50 , V_1 , V_91 ) ;
F_26 ( V_1 , V_5 , V_120 , 0 , V_91 ) ;
F_22 ( V_1 , V_44 ) ;
}
static int F_110 ( T_3 * V_50 ,
struct V_1 * V_1 ,
struct V_89 * V_121 ,
void * V_120 ,
int V_91 )
{
int V_110 , V_122 = 0 , V_123 = 0 ;
struct V_103 * V_104 ;
struct V_124 * V_125 ;
void * V_126 = V_121 -> V_127 ;
V_104 = (struct V_103 * ) V_126 ;
V_104 = F_111 ( V_1 , V_104 ,
V_1 -> V_13 -> V_128 , V_122 ,
F_14 ( ( (struct V_103 * ) V_120 ) -> V_1 ) , 1 ) ;
V_123 = ( void * ) V_104 - V_126 ;
memcpy ( ( void * ) V_104 , V_120 + V_129 ,
V_91 - V_129 ) ;
if ( F_112 ( V_1 -> V_13 ) )
V_122 = sizeof( struct V_124 ) ;
V_1 -> V_98 = V_1 -> V_13 -> V_128 ;
F_91 ( V_1 , V_1 -> V_13 -> V_128 ) ;
F_2 ( V_1 ) -> V_119 = V_1 -> V_13 -> V_128 ;
F_105 ( V_121 -> V_127 ,
V_91 - V_129 + V_123 ,
V_1 -> V_13 -> V_128 - V_122 ) ;
if ( V_122 ) {
V_125 = F_113 ( V_121 -> V_127 ,
V_1 -> V_13 -> V_128 ) ;
F_114 ( V_125 , V_1 -> V_13 -> V_128 ) ;
}
F_115 ( V_121 ) ;
V_110 = F_116 ( V_50 , V_1 , V_121 ) ;
if ( V_110 )
goto V_25;
F_117 ( V_121 ) ;
V_25:
return V_110 ;
}
static int F_118 ( T_3 * V_50 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
int error ;
void * V_120 = NULL ;
struct V_89 * V_130 = NULL ;
struct V_131 V_132 ;
int V_91 ;
V_91 = F_1 ( V_1 ) ;
V_120 = F_119 ( V_91 , V_57 ) ;
if ( ! V_120 ) {
error = - V_58 ;
goto V_25;
}
error = F_23 ( V_1 , V_120 , V_91 , V_5 ) ;
if ( error < 0 )
goto V_25;
if ( F_46 ( V_1 -> V_63 ) ) {
error = F_120 ( V_1 , V_5 -> V_30 ,
V_120 + V_129 ,
V_91 - V_129 ) ;
if ( error )
goto V_25;
}
error = F_44 ( V_50 , V_1 ) ;
if ( error )
goto V_25;
V_132 . V_133 = 0 ;
V_132 . V_134 = 1 ;
V_132 . V_135 = 0 ;
error = V_131 ( V_50 , V_1 , & V_132 , V_136 ) ;
if ( error < 0 )
goto V_137;
if ( ! ( V_132 . V_135 & V_138 ) ) {
error = - V_139 ;
goto V_137;
}
V_130 = F_121 ( V_1 -> V_13 , V_132 . V_140 ) ;
if ( ! V_130 ) {
error = - V_58 ;
goto V_137;
}
F_122 ( V_130 ) ;
error = F_123 ( V_50 , V_130 ) ;
if ( error ) {
F_124 ( V_130 ) ;
error = - V_139 ;
goto V_137;
}
memset ( V_130 -> V_127 , 0 , V_1 -> V_13 -> V_128 ) ;
if ( ! F_46 ( V_1 -> V_63 ) ) {
memcpy ( V_130 -> V_127 , V_120 , V_91 ) ;
F_115 ( V_130 ) ;
error = F_125 ( V_50 ,
V_1 , V_130 ) ;
} else {
error = F_110 ( V_50 , V_1 , V_130 ,
V_120 , V_91 ) ;
}
F_124 ( V_130 ) ;
V_137:
if ( error )
F_109 ( V_50 , V_1 , V_5 , V_120 , V_91 ) ;
V_25:
F_20 ( V_130 ) ;
F_40 ( V_120 ) ;
return error ;
}
int F_126 ( T_3 * V_50 , struct V_108 * V_109 ,
struct V_1 * V_99 , struct V_1 * V_1 )
{
int V_59 , V_91 ;
void * V_100 ;
struct V_4 V_5 ;
V_59 = F_16 ( V_99 , & V_5 ) ;
if ( V_59 )
return V_59 ;
F_42 ( & F_2 ( V_99 ) -> V_29 ) ;
if ( ! F_52 ( V_99 ) )
goto V_25;
V_100 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_129 ;
V_91 = V_31 - V_129 ;
V_59 = F_98 ( V_50 , V_109 , V_99 , V_1 , & V_5 ,
V_100 , V_91 ) ;
if ( V_59 != - V_54 )
goto V_25;
V_91 = F_2 ( V_99 ) -> V_3 -
V_31 ;
if ( ! V_91 ) {
V_59 = F_107 ( V_50 , V_99 , & V_5 ) ;
if ( V_59 && V_59 != - V_54 )
goto V_25;
V_91 = F_2 ( V_99 ) -> V_3 -
V_31 ;
}
if ( V_91 ) {
V_100 = F_104 ( V_99 , & V_5 ) ;
V_59 = F_98 ( V_50 , V_109 , V_99 ,
V_1 , & V_5 , V_100 ,
V_91 ) ;
if ( V_59 != - V_54 )
goto V_25;
}
V_59 = F_118 ( V_50 , V_99 , & V_5 ) ;
V_25:
F_103 ( V_50 , V_99 ) ;
F_43 ( & F_2 ( V_99 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_127 ( struct V_141 * V_142 ,
struct V_1 * V_99 , T_4 V_143 ,
struct V_144 * V_145 ,
V_20 V_146 , V_20 V_147 ,
int * V_148 )
{
int V_110 = 0 , V_149 = 0 ;
unsigned int V_150 ;
int V_49 ;
struct V_103 * V_104 ;
struct V_1 * V_1 = F_128 ( V_142 ) ;
int V_59 , V_91 = 0 ;
struct V_4 V_5 ;
void * V_151 = NULL ;
struct V_103 V_152 ;
struct V_153 V_154 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_148 = 0 ;
goto V_25;
}
V_91 = F_1 ( V_1 ) ;
V_151 = F_119 ( V_91 , V_57 ) ;
if ( ! V_151 ) {
V_59 = - V_58 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_59 = F_23 ( V_1 , V_151 , V_91 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_59 < 0 )
goto V_25;
V_49 = 0 ;
V_150 = F_14 ( ( (struct V_103 * ) V_151 ) -> V_1 ) ;
while ( V_49 < V_91 ) {
if ( V_49 == 0 ) {
V_152 . V_1 = F_129 ( V_1 -> V_28 ) ;
V_152 . V_107 = 1 ;
strcpy ( V_152 . V_41 , L_7 ) ;
V_152 . V_106 = F_106 (
F_108 ( V_152 . V_107 ) ,
V_91 ) ;
F_130 ( V_1 -> V_13 , & V_152 , V_155 ) ;
V_104 = & V_152 ;
V_49 = V_156 ;
} else if ( V_49 == V_156 ) {
V_152 . V_1 = F_129 ( V_150 ) ;
V_152 . V_107 = 2 ;
strcpy ( V_152 . V_41 , L_8 ) ;
V_152 . V_106 = F_106 (
F_108 ( V_152 . V_107 ) ,
V_91 ) ;
F_130 ( V_1 -> V_13 , & V_152 , V_155 ) ;
V_104 = & V_152 ;
V_49 = V_129 ;
} else {
V_104 = (struct V_103 * ) ( V_151 + V_49 ) ;
V_49 += F_95 ( V_104 -> V_106 , V_91 ) ;
if ( F_96 ( V_1 , V_142 , V_104 ,
V_5 . V_30 , V_151 ,
V_91 , V_49 ) ) {
V_59 = V_149 ;
goto V_25;
}
}
F_131 ( V_104 -> V_41 , V_104 -> V_107 , V_145 ) ;
if ( ( V_145 -> V_157 < V_146 ) ||
( ( V_145 -> V_157 == V_146 ) &&
( V_145 -> V_158 < V_147 ) ) )
continue;
if ( V_104 -> V_1 == 0 )
continue;
V_154 . V_41 = V_104 -> V_41 ;
V_154 . V_46 = V_104 -> V_107 ;
V_110 = F_132 ( V_142 , V_145 -> V_157 ,
V_145 -> V_158 , V_104 , & V_154 ) ;
if ( V_110 ) {
V_149 = V_110 ;
goto V_25;
}
V_149 ++ ;
}
V_59 = V_149 ;
V_25:
F_40 ( V_151 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_133 ( struct V_141 * V_141 ,
struct V_159 * V_160 ,
int * V_148 )
{
unsigned int V_101 , V_150 ;
int V_38 ;
struct V_103 * V_104 ;
struct V_161 * V_162 ;
struct V_1 * V_1 = F_128 ( V_141 ) ;
int V_59 , V_91 = 0 ;
struct V_4 V_5 ;
void * V_151 = NULL ;
int V_163 , V_164 , V_165 , V_166 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_148 = 0 ;
goto V_25;
}
V_91 = F_1 ( V_1 ) ;
V_151 = F_119 ( V_91 , V_57 ) ;
if ( ! V_151 ) {
V_59 = - V_58 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_59 = F_23 ( V_1 , V_151 , V_91 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_59 < 0 )
goto V_25;
V_59 = 0 ;
V_162 = V_1 -> V_13 ;
V_150 = F_14 ( ( (struct V_103 * ) V_151 ) -> V_1 ) ;
V_101 = V_160 -> V_49 ;
V_163 = F_108 ( 1 ) ;
V_164 = V_163 + F_108 ( 2 ) ;
V_165 = V_164 - V_129 ;
V_166 = V_165 + V_91 ;
if ( V_141 -> V_167 != V_1 -> V_113 ) {
for ( V_38 = 0 ; V_38 < V_166 && V_38 < V_101 ; ) {
if ( ! V_38 ) {
V_38 = V_163 ;
continue;
} else if ( V_38 == V_163 ) {
V_38 = V_164 ;
continue;
}
V_104 = (struct V_103 * )
( V_151 + V_38 - V_165 ) ;
if ( F_95 ( V_104 -> V_106 , V_166 )
< F_108 ( 1 ) )
break;
V_38 += F_95 ( V_104 -> V_106 ,
V_166 ) ;
}
V_101 = V_38 ;
V_160 -> V_49 = V_101 ;
V_141 -> V_167 = V_1 -> V_113 ;
}
while ( V_160 -> V_49 < V_166 ) {
if ( V_160 -> V_49 == 0 ) {
if ( ! F_134 ( V_160 , L_7 , 1 , V_1 -> V_28 , V_168 ) )
goto V_25;
V_160 -> V_49 = V_163 ;
continue;
}
if ( V_160 -> V_49 == V_163 ) {
if ( ! F_134 ( V_160 , L_8 , 2 , V_150 , V_168 ) )
goto V_25;
V_160 -> V_49 = V_164 ;
continue;
}
V_104 = (struct V_103 * )
( V_151 + V_160 -> V_49 - V_165 ) ;
if ( F_96 ( V_1 , V_141 , V_104 , V_5 . V_30 , V_151 ,
V_166 , V_160 -> V_49 ) )
goto V_25;
if ( F_14 ( V_104 -> V_1 ) ) {
if ( ! F_134 ( V_160 , V_104 -> V_41 , V_104 -> V_107 ,
F_14 ( V_104 -> V_1 ) ,
F_135 ( V_162 , V_104 -> V_169 ) ) )
goto V_25;
}
V_160 -> V_49 += F_95 ( V_104 -> V_106 , V_166 ) ;
}
V_25:
F_40 ( V_151 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
struct V_89 * F_136 ( struct V_1 * V_1 ,
struct V_103 * * V_170 ,
int * V_171 )
{
struct V_4 V_5 ;
* V_171 = F_16 ( V_1 , & V_5 ) ;
if ( * V_171 )
return NULL ;
* V_170 = (struct V_103 * ) F_8 ( & V_5 ) -> V_48 ;
return V_5 . V_30 ;
}
int F_137 ( T_3 * V_50 , struct V_1 * V_172 ,
struct V_1 * V_1 )
{
int V_59 , V_91 = V_31 ;
struct V_4 V_5 ;
struct V_103 * V_104 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_41 ( V_50 , V_1 , V_91 ) ;
if ( V_59 )
goto V_25;
V_104 = (struct V_103 * ) F_8 ( & V_5 ) -> V_48 ;
V_104 -> V_1 = F_129 ( V_172 -> V_28 ) ;
V_104 = (struct V_103 * ) ( ( void * ) V_104 + V_129 ) ;
V_104 -> V_1 = 0 ;
V_104 -> V_106 = F_106 (
V_91 - V_129 ,
V_91 ) ;
F_138 ( V_1 , 2 ) ;
V_1 -> V_98 = F_2 ( V_1 ) -> V_119 = V_91 ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
struct V_89 * F_139 ( struct V_1 * V_99 ,
struct V_108 * V_109 ,
const struct V_173 * V_174 ,
struct V_103 * * V_175 ,
int * V_148 )
{
int V_59 ;
struct V_4 V_5 ;
void * V_100 ;
int V_91 ;
if ( F_16 ( V_99 , & V_5 ) )
return NULL ;
F_18 ( & F_2 ( V_99 ) -> V_29 ) ;
if ( ! F_52 ( V_99 ) ) {
* V_148 = 0 ;
goto V_25;
}
V_100 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_129 ;
V_91 = V_31 - V_129 ;
V_59 = F_140 ( V_5 . V_30 , V_100 , V_91 ,
V_99 , V_109 , V_174 , 0 , V_175 ) ;
if ( V_59 == 1 )
goto V_176;
if ( V_59 < 0 )
goto V_25;
if ( F_1 ( V_99 ) == V_31 )
goto V_25;
V_100 = F_104 ( V_99 , & V_5 ) ;
V_91 = F_1 ( V_99 ) - V_31 ;
V_59 = F_140 ( V_5 . V_30 , V_100 , V_91 ,
V_99 , V_109 , V_174 , 0 , V_175 ) ;
if ( V_59 == 1 )
goto V_176;
V_25:
F_20 ( V_5 . V_30 ) ;
V_5 . V_30 = NULL ;
V_176:
F_19 ( & F_2 ( V_99 ) -> V_29 ) ;
return V_5 . V_30 ;
}
int F_141 ( T_3 * V_50 ,
struct V_1 * V_99 ,
struct V_103 * V_177 ,
struct V_89 * V_30 ,
int * V_148 )
{
int V_110 , V_91 ;
struct V_4 V_5 ;
void * V_100 ;
V_110 = F_16 ( V_99 , & V_5 ) ;
if ( V_110 )
return V_110 ;
F_42 ( & F_2 ( V_99 ) -> V_29 ) ;
if ( ! F_52 ( V_99 ) ) {
* V_148 = 0 ;
goto V_25;
}
if ( ( void * ) V_177 - ( ( void * ) F_8 ( & V_5 ) -> V_48 ) <
V_31 ) {
V_100 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_129 ;
V_91 = V_31 -
V_129 ;
} else {
V_100 = F_104 ( V_99 , & V_5 ) ;
V_91 = F_1 ( V_99 ) -
V_31 ;
}
F_28 ( V_30 , L_2 ) ;
V_110 = F_29 ( V_50 , V_30 ) ;
if ( V_110 )
goto V_25;
V_110 = F_142 ( V_50 , V_99 , V_177 , V_30 ,
V_100 , V_91 , 0 ) ;
if ( V_110 )
goto V_25;
V_110 = F_103 ( V_50 , V_99 ) ;
if ( F_83 ( V_110 ) )
goto V_25;
F_93 ( V_99 , V_5 . V_30 , V_100 , V_91 ) ;
V_25:
F_43 ( & F_2 ( V_99 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
if ( V_110 != - V_178 )
F_84 ( V_99 -> V_13 , V_110 ) ;
return V_110 ;
}
static inline struct V_103 *
F_143 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned int V_101 ,
void * * V_100 ,
int * V_91 )
{
void * V_179 ;
F_24 ( V_101 > F_1 ( V_1 ) ) ;
if ( V_101 < V_31 ) {
V_179 = ( void * ) F_8 ( V_5 ) -> V_48 ;
* V_91 = V_31 ;
} else {
V_179 = F_104 ( V_1 , V_5 ) ;
V_101 -= V_31 ;
* V_91 = F_1 ( V_1 ) -
V_31 ;
}
if ( V_100 )
* V_100 = V_179 ;
return (struct V_103 * ) ( V_179 + V_101 ) ;
}
bool F_144 ( struct V_1 * V_99 , int * V_148 )
{
int V_110 , V_91 ;
struct V_4 V_5 ;
void * V_179 ;
unsigned int V_101 ;
struct V_103 * V_104 ;
bool V_59 = true ;
V_110 = F_16 ( V_99 , & V_5 ) ;
if ( V_110 ) {
F_145 ( V_99 , L_9 ,
V_110 , V_99 -> V_28 ) ;
return true ;
}
F_18 ( & F_2 ( V_99 ) -> V_29 ) ;
if ( ! F_52 ( V_99 ) ) {
* V_148 = 0 ;
goto V_25;
}
V_104 = (struct V_103 * ) F_8 ( & V_5 ) -> V_48 ;
if ( ! F_14 ( V_104 -> V_1 ) ) {
F_53 ( V_99 -> V_13 ,
L_10 ,
V_99 -> V_28 ) ;
V_59 = true ;
goto V_25;
}
V_101 = V_129 ;
while ( V_101 < V_99 -> V_98 ) {
V_104 = F_143 ( V_99 , & V_5 , V_101 ,
& V_179 , & V_91 ) ;
if ( F_96 ( V_99 , NULL , V_104 ,
V_5 . V_30 , V_179 ,
V_91 , V_101 ) ) {
F_53 ( V_99 -> V_13 ,
L_11
L_12
L_13 ,
V_99 -> V_28 , F_14 ( V_104 -> V_1 ) ,
F_13 ( V_104 -> V_106 ) , V_104 -> V_107 ,
V_91 ) ;
V_59 = true ;
goto V_25;
}
if ( F_14 ( V_104 -> V_1 ) ) {
V_59 = false ;
goto V_25;
}
V_101 += F_95 ( V_104 -> V_106 , V_91 ) ;
}
V_25:
F_19 ( & F_2 ( V_99 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_146 ( T_3 * V_50 , struct V_1 * V_1 )
{
int V_59 ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_59 = F_44 ( V_50 , V_1 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_59 ;
}
int F_147 ( struct V_1 * V_1 ,
struct V_180 * V_181 ,
int * V_182 , T_5 V_183 , T_5 V_46 )
{
T_5 V_184 = 0 ;
T_5 V_185 ;
V_20 V_71 = V_186 | V_187 |
V_188 ;
int error = 0 ;
struct V_4 V_5 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
* V_182 = 0 ;
goto V_25;
}
V_185 = F_25 ( T_1 , F_1 ( V_1 ) ,
F_54 ( V_1 ) ) ;
if ( V_183 >= V_185 )
goto V_25;
if ( V_183 + V_46 < V_185 )
V_185 = V_183 + V_46 ;
V_185 -= V_183 ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
goto V_25;
V_184 = ( T_5 ) V_5 . V_30 -> V_189 << V_1 -> V_13 -> V_190 ;
V_184 += ( char * ) F_8 ( & V_5 ) - V_5 . V_30 -> V_127 ;
V_184 += F_148 ( struct V_10 , V_48 ) ;
if ( V_184 )
error = F_149 ( V_181 , V_183 , V_184 ,
V_185 , V_71 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return ( error < 0 ? error : 0 ) ;
}
int F_150 ( T_3 * V_50 ,
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
error = - V_54 ;
goto V_25;
}
error = F_118 ( V_50 , V_1 , & V_5 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return error ;
}
void F_151 ( struct V_1 * V_1 , int * V_182 )
{
T_3 * V_50 ;
int V_91 , V_53 , V_72 ;
T_1 V_98 ;
void * V_51 = NULL ;
struct V_32 V_33 = {
. V_34 = { . V_35 = - V_36 , } ,
} ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_18 ,
} ;
V_72 = F_64 ( V_1 ) ;
V_50 = F_65 ( V_1 , V_86 , V_72 ) ;
if ( F_66 ( V_50 ) )
return;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
* V_182 = 0 ;
F_76 ( V_50 ) ;
return;
}
if ( F_75 ( V_50 , V_1 ) )
goto V_25;
if ( F_16 ( V_1 , & V_33 . V_5 ) )
goto V_25;
F_42 ( & F_2 ( V_1 ) -> V_193 ) ;
V_98 = V_1 -> V_98 ;
V_91 = F_1 ( V_1 ) ;
F_2 ( V_1 ) -> V_119 = V_98 ;
if ( V_98 < V_91 ) {
if ( V_91 > V_31 ) {
if ( V_32 ( V_1 , & V_38 , & V_33 ) )
goto V_194;
F_24 ( V_33 . V_34 . V_35 ) ;
V_53 = F_14 ( V_33 . V_34 . V_43 -> V_22 ) ;
V_51 = F_119 ( V_53 , V_57 ) ;
if ( ! V_51 )
goto V_194;
if ( F_39 ( V_1 , V_38 . V_39 , V_38 . V_41 ,
V_51 , V_53 ) )
goto V_194;
V_38 . V_51 = V_51 ;
V_38 . V_53 = V_98 > V_31 ?
V_98 - V_31 : 0 ;
if ( F_30 ( V_50 , V_1 , & V_38 , & V_33 ) )
goto V_194;
}
if ( V_98 < V_31 ) {
void * V_195 = ( void * ) F_8 ( & V_33 . V_5 ) -> V_48 ;
memset ( V_195 + V_98 , 0 ,
V_31 - V_98 ) ;
}
F_2 ( V_1 ) -> V_3 = V_98 <
V_31 ?
V_31 : V_98 ;
}
V_194:
F_43 ( & F_2 ( V_1 ) -> V_193 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
F_40 ( V_51 ) ;
if ( V_1 -> V_83 )
F_78 ( V_50 , V_1 ) ;
V_1 -> V_111 = V_1 -> V_112 = F_101 ( V_1 ) ;
F_103 ( V_50 , V_1 ) ;
if ( F_152 ( V_1 ) )
F_153 ( V_50 ) ;
F_76 ( V_50 ) ;
return;
}
int F_154 ( struct V_1 * V_1 )
{
int error , V_72 ;
T_3 * V_50 ;
struct V_4 V_5 ;
if ( ! F_52 ( V_1 ) ) {
F_31 ( V_1 , V_44 ) ;
return 0 ;
}
V_72 = F_64 ( V_1 ) ;
V_5 . V_30 = NULL ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
return error ;
V_50 = F_65 ( V_1 , V_78 , V_72 ) ;
if ( F_66 ( V_50 ) ) {
error = F_67 ( V_50 ) ;
goto V_196;
}
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_52 ( V_1 ) ) {
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
error = F_118 ( V_50 , V_1 , & V_5 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
F_76 ( V_50 ) ;
V_196:
F_20 ( V_5 . V_30 ) ;
return error ;
}
