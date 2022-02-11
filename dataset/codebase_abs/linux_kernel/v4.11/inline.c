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
if ( F_27 ( F_28 ( F_4 ( V_1 -> V_13 ) ) ) )
return;
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
static int F_29 ( T_3 * V_50 ,
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
F_30 ( V_33 . V_5 . V_30 , L_2 ) ;
error = F_31 ( V_50 , V_33 . V_5 . V_30 ) ;
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
error = F_32 ( V_50 , V_1 , & V_38 , & V_33 ) ;
if ( error ) {
if ( error == - V_54 )
F_33 ( V_1 ,
V_44 ) ;
goto V_25;
}
memset ( ( void * ) F_8 ( & V_33 . V_5 ) -> V_48 ,
0 , V_31 ) ;
F_2 ( V_1 ) -> V_2 = ( V_42 ) ( ( void * ) V_33 . V_34 . V_43 -
( void * ) F_8 ( & V_33 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_46 + V_31 ;
F_34 ( V_1 , V_55 ) ;
F_35 ( V_1 , V_56 ) ;
F_36 ( V_1 ) ;
F_37 ( V_33 . V_5 . V_30 ) ;
error = F_38 ( V_50 , V_1 , & V_33 . V_5 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
return error ;
}
static int F_39 ( T_3 * V_50 , struct V_1 * V_1 ,
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
V_51 = F_40 ( V_46 , V_57 ) ;
if ( ! V_51 ) {
error = - V_58 ;
goto V_25;
}
error = F_41 ( V_1 , V_38 . V_39 , V_38 . V_41 ,
V_51 , V_46 ) ;
if ( error == - V_36 )
goto V_25;
F_30 ( V_33 . V_5 . V_30 , L_2 ) ;
error = F_31 ( V_50 , V_33 . V_5 . V_30 ) ;
if ( error )
goto V_25;
V_38 . V_51 = V_51 ;
V_38 . V_53 = V_46 ;
error = F_32 ( V_50 , V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
F_2 ( V_1 ) -> V_2 = ( V_42 ) ( ( void * ) V_33 . V_34 . V_43 -
( void * ) F_8 ( & V_33 . V_5 ) ) ;
F_2 ( V_1 ) -> V_3 = V_31 +
F_14 ( V_33 . V_34 . V_43 -> V_22 ) ;
F_22 ( V_1 , V_44 ) ;
F_37 ( V_33 . V_5 . V_30 ) ;
error = F_38 ( V_50 , V_1 , & V_33 . V_5 ) ;
V_25:
F_42 ( V_51 ) ;
F_20 ( V_33 . V_5 . V_30 ) ;
return error ;
}
static int F_43 ( T_3 * V_50 , struct V_1 * V_1 ,
unsigned int V_46 )
{
int V_59 , V_60 , V_61 ;
struct V_62 * V_63 = F_2 ( V_1 ) ;
if ( ! F_5 ( V_1 , V_44 ) )
return - V_54 ;
V_60 = F_15 ( V_1 ) ;
if ( V_60 < V_46 )
return - V_54 ;
F_44 ( V_1 , & V_61 ) ;
if ( V_63 -> V_2 )
V_59 = F_39 ( V_50 , V_1 , V_46 ) ;
else
V_59 = F_29 ( V_50 , V_1 , V_46 ) ;
F_45 ( V_1 , & V_61 ) ;
return V_59 ;
}
static int F_46 ( T_3 * V_50 ,
struct V_1 * V_1 )
{
struct V_62 * V_63 = F_2 ( V_1 ) ;
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
if ( ! V_63 -> V_2 )
return 0 ;
error = F_16 ( V_1 , & V_33 . V_5 ) ;
if ( error )
return error ;
error = V_32 ( V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
F_30 ( V_33 . V_5 . V_30 , L_2 ) ;
error = F_31 ( V_50 , V_33 . V_5 . V_30 ) ;
if ( error )
goto V_25;
error = F_32 ( V_50 , V_1 , & V_38 , & V_33 ) ;
if ( error )
goto V_25;
memset ( ( void * ) F_8 ( & V_33 . V_5 ) -> V_48 ,
0 , V_31 ) ;
if ( F_47 ( V_1 -> V_13 ) ) {
if ( F_48 ( V_1 -> V_64 ) ||
F_49 ( V_1 -> V_64 ) || F_50 ( V_1 -> V_64 ) ) {
F_35 ( V_1 , V_55 ) ;
F_51 ( V_50 , V_1 ) ;
}
}
F_34 ( V_1 , V_56 ) ;
F_36 ( V_1 ) ;
F_37 ( V_33 . V_5 . V_30 ) ;
error = F_38 ( V_50 , V_1 , & V_33 . V_5 ) ;
F_2 ( V_1 ) -> V_2 = 0 ;
F_2 ( V_1 ) -> V_3 = 0 ;
F_33 ( V_1 , V_44 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
if ( error == - V_36 )
error = 0 ;
return error ;
}
static int F_52 ( struct V_1 * V_1 , struct V_65 * V_65 )
{
void * V_66 ;
int V_59 = 0 ;
T_1 V_46 ;
struct V_4 V_5 ;
F_24 ( ! F_53 ( V_65 ) ) ;
F_24 ( ! F_54 ( V_1 ) ) ;
F_24 ( V_65 -> V_67 ) ;
if ( ! F_2 ( V_1 ) -> V_2 ) {
F_55 ( V_1 -> V_13 , L_4 ,
V_1 -> V_28 ) ;
goto V_25;
}
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
goto V_25;
V_46 = F_25 ( T_1 , F_1 ( V_1 ) , F_56 ( V_1 ) ) ;
V_66 = F_57 ( V_65 ) ;
V_59 = F_23 ( V_1 , V_66 , V_46 , & V_5 ) ;
F_58 ( V_65 ) ;
F_59 ( V_66 ) ;
F_60 ( V_65 , V_46 , V_68 ) ;
F_61 ( V_65 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_59 ;
}
int F_62 ( struct V_1 * V_1 , struct V_65 * V_65 )
{
int V_59 = 0 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_54 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return - V_69 ;
}
if ( ! V_65 -> V_67 )
V_59 = F_52 ( V_1 , V_65 ) ;
else if ( ! F_63 ( V_65 ) ) {
F_60 ( V_65 , 0 , V_68 ) ;
F_61 ( V_65 ) ;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_64 ( V_65 ) ;
return V_59 >= 0 ? 0 : V_59 ;
}
static int F_65 ( struct V_70 * V_71 ,
struct V_1 * V_1 ,
unsigned V_72 )
{
int V_59 , V_73 , V_61 ;
T_3 * V_50 = NULL ;
int V_74 = 0 , V_75 = 0 ;
struct V_65 * V_65 = NULL ;
unsigned V_76 , V_77 ;
struct V_4 V_5 ;
if ( ! F_54 ( V_1 ) ) {
F_33 ( V_1 , V_44 ) ;
return 0 ;
}
V_73 = F_66 ( V_1 ) ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_78:
V_50 = F_67 ( V_1 , V_79 , V_73 ) ;
if ( F_68 ( V_50 ) ) {
V_59 = F_69 ( V_50 ) ;
V_50 = NULL ;
goto V_25;
}
V_72 |= V_80 ;
V_65 = F_70 ( V_71 , 0 , V_72 ) ;
if ( ! V_65 ) {
V_59 = - V_58 ;
goto V_25;
}
F_44 ( V_1 , & V_61 ) ;
V_75 = 1 ;
if ( ! F_54 ( V_1 ) ) {
V_59 = 0 ;
goto V_25;
}
V_76 = 0 ;
V_77 = F_1 ( V_1 ) ;
if ( ! F_63 ( V_65 ) ) {
V_59 = F_52 ( V_1 , V_65 ) ;
if ( V_59 < 0 )
goto V_25;
}
V_59 = F_46 ( V_50 , V_1 ) ;
if ( V_59 )
goto V_25;
if ( F_71 ( V_1 ) ) {
V_59 = F_72 ( V_65 , V_76 , V_77 ,
V_81 ) ;
} else
V_59 = F_72 ( V_65 , V_76 , V_77 , V_82 ) ;
if ( ! V_59 && F_73 ( V_1 ) ) {
V_59 = F_74 ( V_50 , F_75 ( V_65 ) ,
V_76 , V_77 , NULL ,
V_83 ) ;
}
if ( V_59 ) {
F_64 ( V_65 ) ;
F_76 ( V_65 ) ;
V_65 = NULL ;
F_77 ( V_50 , V_1 ) ;
F_45 ( V_1 , & V_61 ) ;
V_75 = 0 ;
F_78 ( V_50 ) ;
V_50 = NULL ;
F_79 ( V_1 ) ;
if ( V_1 -> V_84 )
F_80 ( NULL , V_1 ) ;
}
if ( V_59 == - V_54 && F_81 ( V_1 -> V_13 , & V_74 ) )
goto V_78;
if ( V_65 )
F_82 ( V_65 , V_76 , V_77 ) ;
V_25:
if ( V_65 ) {
F_64 ( V_65 ) ;
F_76 ( V_65 ) ;
}
if ( V_75 )
F_45 ( V_1 , & V_61 ) ;
if ( V_50 )
F_78 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_83 ( struct V_70 * V_71 ,
struct V_1 * V_1 ,
T_2 V_49 , unsigned V_46 ,
unsigned V_72 ,
struct V_65 * * V_85 )
{
int V_59 ;
T_3 * V_50 ;
struct V_65 * V_65 ;
struct V_4 V_5 ;
if ( V_49 + V_46 > F_15 ( V_1 ) )
goto V_86;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_50 = F_67 ( V_1 , V_87 , 1 ) ;
if ( F_68 ( V_50 ) ) {
V_59 = F_69 ( V_50 ) ;
V_50 = NULL ;
goto V_25;
}
V_59 = F_43 ( V_50 , V_1 , V_49 + V_46 ) ;
if ( V_59 && V_59 != - V_54 )
goto V_25;
if ( V_59 == - V_54 ) {
F_78 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
goto V_86;
}
V_72 |= V_80 ;
V_65 = F_70 ( V_71 , 0 , V_72 ) ;
if ( ! V_65 ) {
V_59 = - V_58 ;
goto V_25;
}
* V_85 = V_65 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_54 ( V_1 ) ) {
V_59 = 0 ;
F_64 ( V_65 ) ;
F_76 ( V_65 ) ;
goto V_88;
}
if ( ! F_63 ( V_65 ) ) {
V_59 = F_52 ( V_1 , V_65 ) ;
if ( V_59 < 0 )
goto V_88;
}
V_59 = 1 ;
V_50 = NULL ;
V_88:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
if ( V_50 )
F_78 ( V_50 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
V_86:
return F_65 ( V_71 ,
V_1 , V_72 ) ;
}
int F_84 ( struct V_1 * V_1 , T_2 V_49 , unsigned V_46 ,
unsigned V_89 , struct V_65 * V_65 )
{
int V_59 , V_61 ;
void * V_66 ;
struct V_4 V_5 ;
if ( F_27 ( V_89 < V_46 ) ) {
if ( ! F_63 ( V_65 ) ) {
V_89 = 0 ;
goto V_25;
}
}
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 ) {
F_85 ( V_1 -> V_13 , V_59 ) ;
V_89 = 0 ;
goto V_25;
}
F_44 ( V_1 , & V_61 ) ;
F_24 ( ! F_54 ( V_1 ) ) ;
V_66 = F_57 ( V_65 ) ;
F_26 ( V_1 , & V_5 , V_66 , V_49 , V_46 ) ;
F_59 ( V_66 ) ;
F_61 ( V_65 ) ;
F_86 ( V_65 ) ;
F_45 ( V_1 , & V_61 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
return V_89 ;
}
struct V_90 *
F_87 ( struct V_1 * V_1 ,
unsigned V_46 ,
struct V_65 * V_65 )
{
int V_59 , V_61 ;
void * V_66 ;
struct V_4 V_5 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 ) {
F_85 ( V_1 -> V_13 , V_59 ) ;
return NULL ;
}
F_44 ( V_1 , & V_61 ) ;
V_66 = F_57 ( V_65 ) ;
F_26 ( V_1 , & V_5 , V_66 , 0 , V_46 ) ;
F_59 ( V_66 ) ;
F_45 ( V_1 , & V_61 ) ;
return V_5 . V_30 ;
}
static int F_88 ( struct V_70 * V_71 ,
struct V_1 * V_1 ,
unsigned V_72 ,
void * * V_91 )
{
int V_59 = 0 , V_92 ;
struct V_65 * V_65 ;
V_65 = F_70 ( V_71 , 0 , V_72 ) ;
if ( ! V_65 )
return - V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_54 ( V_1 ) ) {
F_33 ( V_1 , V_44 ) ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
if ( ! F_63 ( V_65 ) ) {
V_59 = F_52 ( V_1 , V_65 ) ;
if ( V_59 < 0 )
goto V_25;
}
V_59 = F_72 ( V_65 , 0 , V_92 ,
V_93 ) ;
if ( V_59 ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_64 ( V_65 ) ;
F_76 ( V_65 ) ;
F_79 ( V_1 ) ;
return V_59 ;
}
F_89 ( V_65 ) ;
F_61 ( V_65 ) ;
F_33 ( V_1 , V_44 ) ;
* V_91 = ( void * ) V_94 ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_65 ) {
F_64 ( V_65 ) ;
F_76 ( V_65 ) ;
}
return V_59 ;
}
int F_90 ( struct V_70 * V_71 ,
struct V_1 * V_1 ,
T_2 V_49 , unsigned V_46 ,
unsigned V_72 ,
struct V_65 * * V_85 ,
void * * V_91 )
{
int V_59 , V_92 ;
T_3 * V_50 ;
struct V_65 * V_65 ;
struct V_4 V_5 ;
int V_74 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_95:
V_50 = F_67 ( V_1 , V_87 , 1 ) ;
if ( F_68 ( V_50 ) ) {
V_59 = F_69 ( V_50 ) ;
goto V_25;
}
V_92 = F_15 ( V_1 ) ;
V_59 = - V_54 ;
if ( V_92 >= V_49 + V_46 ) {
V_59 = F_43 ( V_50 , V_1 , V_49 + V_46 ) ;
if ( V_59 && V_59 != - V_54 )
goto V_96;
}
V_72 |= V_80 ;
if ( V_59 == - V_54 ) {
V_59 = F_88 ( V_71 ,
V_1 ,
V_72 ,
V_91 ) ;
F_78 ( V_50 ) ;
if ( V_59 == - V_54 &&
F_81 ( V_1 -> V_13 , & V_74 ) )
goto V_95;
goto V_25;
}
V_65 = F_70 ( V_71 , 0 , V_72 ) ;
if ( ! V_65 ) {
V_59 = - V_58 ;
goto V_96;
}
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_54 ( V_1 ) ) {
V_59 = 0 ;
goto V_97;
}
if ( ! F_63 ( V_65 ) ) {
V_59 = F_52 ( V_1 , V_65 ) ;
if ( V_59 < 0 )
goto V_97;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_85 = V_65 ;
F_20 ( V_5 . V_30 ) ;
return 1 ;
V_97:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
F_64 ( V_65 ) ;
F_76 ( V_65 ) ;
V_96:
F_78 ( V_50 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_91 ( struct V_1 * V_1 , T_2 V_49 ,
unsigned V_46 , unsigned V_89 ,
struct V_65 * V_65 )
{
int V_98 = 0 ;
int V_59 ;
V_59 = F_84 ( V_1 , V_49 , V_46 , V_89 , V_65 ) ;
if ( V_59 < 0 ) {
F_64 ( V_65 ) ;
F_76 ( V_65 ) ;
return V_59 ;
}
V_89 = V_59 ;
if ( V_49 + V_89 > V_1 -> V_99 ) {
F_92 ( V_1 , V_49 + V_89 ) ;
V_98 = 1 ;
}
F_64 ( V_65 ) ;
F_76 ( V_65 ) ;
if ( V_98 )
F_93 ( V_1 ) ;
return V_89 ;
}
void F_94 ( struct V_1 * V_100 , struct V_90 * V_30 ,
void * V_101 , int V_92 )
{
int V_102 ;
unsigned short V_103 ;
struct V_104 * V_105 = V_101 ;
void * V_106 = V_101 + V_92 ;
F_95 ( L_5 , V_100 -> V_28 ) ;
V_102 = 0 ;
while ( ( void * ) V_105 < V_106 ) {
V_103 = F_96 ( V_105 -> V_107 , V_92 ) ;
F_95 ( L_6 ,
V_102 , V_103 , V_105 -> V_108 , V_105 -> V_41 ,
V_105 -> V_108 , F_14 ( V_105 -> V_1 ) ) ;
if ( F_97 ( V_100 , NULL , V_105 , V_30 ,
V_101 , V_92 , V_102 ) )
F_98 () ;
V_102 += V_103 ;
V_105 = (struct V_104 * ) ( ( char * ) V_105 + V_103 ) ;
}
}
static int F_99 ( T_3 * V_50 ,
struct V_109 * V_110 ,
struct V_1 * V_100 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_101 , int V_92 )
{
int V_111 ;
struct V_104 * V_105 ;
V_111 = F_100 ( V_100 , V_1 , V_5 -> V_30 , V_101 ,
V_92 , V_110 , & V_105 ) ;
if ( V_111 )
return V_111 ;
F_30 ( V_5 -> V_30 , L_2 ) ;
V_111 = F_31 ( V_50 , V_5 -> V_30 ) ;
if ( V_111 )
return V_111 ;
F_101 ( V_100 , V_1 , V_105 , V_92 , V_110 ) ;
F_94 ( V_100 , V_5 -> V_30 , V_101 , V_92 ) ;
V_100 -> V_112 = V_100 -> V_113 = F_102 ( V_100 ) ;
F_103 ( V_100 ) ;
V_100 -> V_114 ++ ;
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
static void F_105 ( void * V_115 , int V_116 , int V_117 )
{
struct V_104 * V_105 , * V_118 ;
void * V_119 ;
int V_103 ;
V_105 = (struct V_104 * ) V_115 ;
if ( V_116 ) {
V_119 = V_115 + V_116 ;
do {
V_118 = V_105 ;
V_103 = F_96 ( V_105 -> V_107 , V_116 ) ;
V_115 += V_103 ;
V_105 = (struct V_104 * ) V_115 ;
} while ( V_115 < V_119 );
V_118 -> V_107 = F_106 ( V_103 + V_117 -
V_116 , V_117 ) ;
} else {
V_105 -> V_1 = 0 ;
V_105 -> V_107 = F_106 ( V_117 , V_117 ) ;
}
}
static int F_107 ( T_3 * V_50 , struct V_1 * V_100 ,
struct V_4 * V_5 )
{
int V_59 ;
int V_116 = F_2 ( V_100 ) -> V_3 - V_31 ;
int V_117 = F_3 ( V_100 , V_5 ) ;
if ( V_117 - V_116 <= F_108 ( 1 ) )
return - V_54 ;
V_59 = F_39 ( V_50 , V_100 ,
V_117 + V_31 ) ;
if ( V_59 )
return V_59 ;
F_105 ( F_104 ( V_100 , V_5 ) , V_116 ,
F_2 ( V_100 ) -> V_3 -
V_31 ) ;
V_100 -> V_99 = F_2 ( V_100 ) -> V_120 = F_2 ( V_100 ) -> V_3 ;
return 0 ;
}
static void F_109 ( T_3 * V_50 , struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_121 , int V_92 )
{
F_29 ( V_50 , V_1 , V_92 ) ;
F_26 ( V_1 , V_5 , V_121 , 0 , V_92 ) ;
F_22 ( V_1 , V_44 ) ;
}
static int F_110 ( T_3 * V_50 ,
struct V_1 * V_1 ,
struct V_90 * V_122 ,
void * V_121 ,
int V_92 )
{
int V_111 , V_123 = 0 , V_124 = 0 ;
struct V_104 * V_105 ;
struct V_125 * V_126 ;
void * V_127 = V_122 -> V_128 ;
V_105 = (struct V_104 * ) V_127 ;
V_105 = F_111 ( V_1 , V_105 ,
V_1 -> V_13 -> V_129 , V_123 ,
F_14 ( ( (struct V_104 * ) V_121 ) -> V_1 ) , 1 ) ;
V_124 = ( void * ) V_105 - V_127 ;
memcpy ( ( void * ) V_105 , V_121 + V_130 ,
V_92 - V_130 ) ;
if ( F_112 ( V_1 -> V_13 ) )
V_123 = sizeof( struct V_125 ) ;
V_1 -> V_99 = V_1 -> V_13 -> V_129 ;
F_92 ( V_1 , V_1 -> V_13 -> V_129 ) ;
F_2 ( V_1 ) -> V_120 = V_1 -> V_13 -> V_129 ;
F_105 ( V_122 -> V_128 ,
V_92 - V_130 + V_124 ,
V_1 -> V_13 -> V_129 - V_123 ) ;
if ( V_123 ) {
V_126 = F_113 ( V_122 -> V_128 ,
V_1 -> V_13 -> V_129 ) ;
F_114 ( V_126 , V_1 -> V_13 -> V_129 ) ;
}
F_115 ( V_122 ) ;
V_111 = F_116 ( V_50 , V_1 , V_122 ) ;
if ( V_111 )
return V_111 ;
F_117 ( V_122 ) ;
return F_118 ( V_50 , V_1 ) ;
}
static int F_119 ( T_3 * V_50 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
int error ;
void * V_121 = NULL ;
struct V_90 * V_131 = NULL ;
struct V_132 V_133 ;
int V_92 ;
V_92 = F_1 ( V_1 ) ;
V_121 = F_120 ( V_92 , V_57 ) ;
if ( ! V_121 ) {
error = - V_58 ;
goto V_25;
}
error = F_23 ( V_1 , V_121 , V_92 , V_5 ) ;
if ( error < 0 )
goto V_25;
if ( F_48 ( V_1 -> V_64 ) ) {
error = F_121 ( V_1 , V_5 -> V_30 ,
V_121 + V_130 ,
V_92 - V_130 ) ;
if ( error )
goto V_25;
}
error = F_46 ( V_50 , V_1 ) ;
if ( error )
goto V_25;
V_133 . V_134 = 0 ;
V_133 . V_135 = 1 ;
V_133 . V_136 = 0 ;
error = V_132 ( V_50 , V_1 , & V_133 , V_137 ) ;
if ( error < 0 )
goto V_138;
if ( ! ( V_133 . V_136 & V_139 ) ) {
error = - V_140 ;
goto V_138;
}
V_131 = F_122 ( V_1 -> V_13 , V_133 . V_141 ) ;
if ( ! V_131 ) {
error = - V_58 ;
goto V_138;
}
F_123 ( V_131 ) ;
error = F_124 ( V_50 , V_131 ) ;
if ( error ) {
F_125 ( V_131 ) ;
error = - V_140 ;
goto V_138;
}
memset ( V_131 -> V_128 , 0 , V_1 -> V_13 -> V_129 ) ;
if ( ! F_48 ( V_1 -> V_64 ) ) {
memcpy ( V_131 -> V_128 , V_121 , V_92 ) ;
F_115 ( V_131 ) ;
error = F_126 ( V_50 ,
V_1 , V_131 ) ;
} else {
error = F_110 ( V_50 , V_1 , V_131 ,
V_121 , V_92 ) ;
}
F_125 ( V_131 ) ;
V_138:
if ( error )
F_109 ( V_50 , V_1 , V_5 , V_121 , V_92 ) ;
V_25:
F_20 ( V_131 ) ;
F_42 ( V_121 ) ;
return error ;
}
int F_127 ( T_3 * V_50 , struct V_109 * V_110 ,
struct V_1 * V_100 , struct V_1 * V_1 )
{
int V_59 , V_92 , V_61 ;
void * V_101 ;
struct V_4 V_5 ;
V_59 = F_16 ( V_100 , & V_5 ) ;
if ( V_59 )
return V_59 ;
F_44 ( V_100 , & V_61 ) ;
if ( ! F_54 ( V_100 ) )
goto V_25;
V_101 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_130 ;
V_92 = V_31 - V_130 ;
V_59 = F_99 ( V_50 , V_110 , V_100 , V_1 , & V_5 ,
V_101 , V_92 ) ;
if ( V_59 != - V_54 )
goto V_25;
V_92 = F_2 ( V_100 ) -> V_3 -
V_31 ;
if ( ! V_92 ) {
V_59 = F_107 ( V_50 , V_100 , & V_5 ) ;
if ( V_59 && V_59 != - V_54 )
goto V_25;
V_92 = F_2 ( V_100 ) -> V_3 -
V_31 ;
}
if ( V_92 ) {
V_101 = F_104 ( V_100 , & V_5 ) ;
V_59 = F_99 ( V_50 , V_110 , V_100 ,
V_1 , & V_5 , V_101 ,
V_92 ) ;
if ( V_59 != - V_54 )
goto V_25;
}
V_59 = F_119 ( V_50 , V_100 , & V_5 ) ;
V_25:
F_45 ( V_100 , & V_61 ) ;
F_118 ( V_50 , V_100 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_128 ( struct V_142 * V_143 ,
struct V_1 * V_100 , T_4 V_144 ,
struct V_145 * V_146 ,
V_20 V_147 , V_20 V_148 ,
int * V_149 )
{
int V_111 = 0 , V_150 = 0 ;
unsigned int V_151 ;
int V_49 ;
struct V_104 * V_105 ;
struct V_1 * V_1 = F_129 ( V_143 ) ;
int V_59 , V_92 = 0 ;
struct V_4 V_5 ;
void * V_152 = NULL ;
struct V_104 V_153 ;
struct V_154 V_155 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_54 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_149 = 0 ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
V_152 = F_120 ( V_92 , V_57 ) ;
if ( ! V_152 ) {
V_59 = - V_58 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_59 = F_23 ( V_1 , V_152 , V_92 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_59 < 0 )
goto V_25;
V_49 = 0 ;
V_151 = F_14 ( ( (struct V_104 * ) V_152 ) -> V_1 ) ;
while ( V_49 < V_92 ) {
if ( V_49 == 0 ) {
V_153 . V_1 = F_130 ( V_1 -> V_28 ) ;
V_153 . V_108 = 1 ;
strcpy ( V_153 . V_41 , L_7 ) ;
V_153 . V_107 = F_106 (
F_108 ( V_153 . V_108 ) ,
V_92 ) ;
F_131 ( V_1 -> V_13 , & V_153 , V_156 ) ;
V_105 = & V_153 ;
V_49 = V_157 ;
} else if ( V_49 == V_157 ) {
V_153 . V_1 = F_130 ( V_151 ) ;
V_153 . V_108 = 2 ;
strcpy ( V_153 . V_41 , L_8 ) ;
V_153 . V_107 = F_106 (
F_108 ( V_153 . V_108 ) ,
V_92 ) ;
F_131 ( V_1 -> V_13 , & V_153 , V_156 ) ;
V_105 = & V_153 ;
V_49 = V_130 ;
} else {
V_105 = (struct V_104 * ) ( V_152 + V_49 ) ;
V_49 += F_96 ( V_105 -> V_107 , V_92 ) ;
if ( F_97 ( V_1 , V_143 , V_105 ,
V_5 . V_30 , V_152 ,
V_92 , V_49 ) ) {
V_59 = V_150 ;
goto V_25;
}
}
F_132 ( V_105 -> V_41 , V_105 -> V_108 , V_146 ) ;
if ( ( V_146 -> V_158 < V_147 ) ||
( ( V_146 -> V_158 == V_147 ) &&
( V_146 -> V_159 < V_148 ) ) )
continue;
if ( V_105 -> V_1 == 0 )
continue;
V_155 . V_41 = V_105 -> V_41 ;
V_155 . V_46 = V_105 -> V_108 ;
V_111 = F_133 ( V_143 , V_146 -> V_158 ,
V_146 -> V_159 , V_105 , & V_155 ) ;
if ( V_111 ) {
V_150 = V_111 ;
goto V_25;
}
V_150 ++ ;
}
V_59 = V_150 ;
V_25:
F_42 ( V_152 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_134 ( struct V_142 * V_142 ,
struct V_160 * V_161 ,
int * V_149 )
{
unsigned int V_102 , V_151 ;
int V_38 ;
struct V_104 * V_105 ;
struct V_162 * V_163 ;
struct V_1 * V_1 = F_129 ( V_142 ) ;
int V_59 , V_92 = 0 ;
struct V_4 V_5 ;
void * V_152 = NULL ;
int V_164 , V_165 , V_166 , V_167 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_54 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_149 = 0 ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
V_152 = F_120 ( V_92 , V_57 ) ;
if ( ! V_152 ) {
V_59 = - V_58 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_59 = F_23 ( V_1 , V_152 , V_92 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_59 < 0 )
goto V_25;
V_59 = 0 ;
V_163 = V_1 -> V_13 ;
V_151 = F_14 ( ( (struct V_104 * ) V_152 ) -> V_1 ) ;
V_102 = V_161 -> V_49 ;
V_164 = F_108 ( 1 ) ;
V_165 = V_164 + F_108 ( 2 ) ;
V_166 = V_165 - V_130 ;
V_167 = V_166 + V_92 ;
if ( V_142 -> V_168 != V_1 -> V_114 ) {
for ( V_38 = 0 ; V_38 < V_167 && V_38 < V_102 ; ) {
if ( ! V_38 ) {
V_38 = V_164 ;
continue;
} else if ( V_38 == V_164 ) {
V_38 = V_165 ;
continue;
}
V_105 = (struct V_104 * )
( V_152 + V_38 - V_166 ) ;
if ( F_96 ( V_105 -> V_107 , V_167 )
< F_108 ( 1 ) )
break;
V_38 += F_96 ( V_105 -> V_107 ,
V_167 ) ;
}
V_102 = V_38 ;
V_161 -> V_49 = V_102 ;
V_142 -> V_168 = V_1 -> V_114 ;
}
while ( V_161 -> V_49 < V_167 ) {
if ( V_161 -> V_49 == 0 ) {
if ( ! F_135 ( V_161 , L_7 , 1 , V_1 -> V_28 , V_169 ) )
goto V_25;
V_161 -> V_49 = V_164 ;
continue;
}
if ( V_161 -> V_49 == V_164 ) {
if ( ! F_135 ( V_161 , L_8 , 2 , V_151 , V_169 ) )
goto V_25;
V_161 -> V_49 = V_165 ;
continue;
}
V_105 = (struct V_104 * )
( V_152 + V_161 -> V_49 - V_166 ) ;
if ( F_97 ( V_1 , V_142 , V_105 , V_5 . V_30 , V_152 ,
V_167 , V_161 -> V_49 ) )
goto V_25;
if ( F_14 ( V_105 -> V_1 ) ) {
if ( ! F_135 ( V_161 , V_105 -> V_41 , V_105 -> V_108 ,
F_14 ( V_105 -> V_1 ) ,
F_136 ( V_163 , V_105 -> V_170 ) ) )
goto V_25;
}
V_161 -> V_49 += F_96 ( V_105 -> V_107 , V_167 ) ;
}
V_25:
F_42 ( V_152 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
struct V_90 * F_137 ( struct V_1 * V_1 ,
struct V_104 * * V_171 ,
int * V_172 )
{
struct V_4 V_5 ;
* V_172 = F_16 ( V_1 , & V_5 ) ;
if ( * V_172 )
return NULL ;
* V_171 = (struct V_104 * ) F_8 ( & V_5 ) -> V_48 ;
return V_5 . V_30 ;
}
int F_138 ( T_3 * V_50 , struct V_1 * V_173 ,
struct V_1 * V_1 )
{
int V_59 , V_92 = V_31 ;
struct V_4 V_5 ;
struct V_104 * V_105 ;
V_59 = F_16 ( V_1 , & V_5 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_43 ( V_50 , V_1 , V_92 ) ;
if ( V_59 )
goto V_25;
V_105 = (struct V_104 * ) F_8 ( & V_5 ) -> V_48 ;
V_105 -> V_1 = F_130 ( V_173 -> V_28 ) ;
V_105 = (struct V_104 * ) ( ( void * ) V_105 + V_130 ) ;
V_105 -> V_1 = 0 ;
V_105 -> V_107 = F_106 (
V_92 - V_130 ,
V_92 ) ;
F_139 ( V_1 , 2 ) ;
V_1 -> V_99 = F_2 ( V_1 ) -> V_120 = V_92 ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
struct V_90 * F_140 ( struct V_1 * V_100 ,
struct V_109 * V_110 ,
const struct V_174 * V_175 ,
struct V_104 * * V_176 ,
int * V_149 )
{
int V_59 ;
struct V_4 V_5 ;
void * V_101 ;
int V_92 ;
if ( F_16 ( V_100 , & V_5 ) )
return NULL ;
F_18 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_54 ( V_100 ) ) {
* V_149 = 0 ;
goto V_25;
}
V_101 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_130 ;
V_92 = V_31 - V_130 ;
V_59 = F_141 ( V_5 . V_30 , V_101 , V_92 ,
V_100 , V_110 , V_175 , 0 , V_176 ) ;
if ( V_59 == 1 )
goto V_177;
if ( V_59 < 0 )
goto V_25;
if ( F_1 ( V_100 ) == V_31 )
goto V_25;
V_101 = F_104 ( V_100 , & V_5 ) ;
V_92 = F_1 ( V_100 ) - V_31 ;
V_59 = F_141 ( V_5 . V_30 , V_101 , V_92 ,
V_100 , V_110 , V_175 , 0 , V_176 ) ;
if ( V_59 == 1 )
goto V_177;
V_25:
F_20 ( V_5 . V_30 ) ;
V_5 . V_30 = NULL ;
V_177:
F_19 ( & F_2 ( V_100 ) -> V_29 ) ;
return V_5 . V_30 ;
}
int F_142 ( T_3 * V_50 ,
struct V_1 * V_100 ,
struct V_104 * V_178 ,
struct V_90 * V_30 ,
int * V_149 )
{
int V_111 , V_92 , V_61 ;
struct V_4 V_5 ;
void * V_101 ;
V_111 = F_16 ( V_100 , & V_5 ) ;
if ( V_111 )
return V_111 ;
F_44 ( V_100 , & V_61 ) ;
if ( ! F_54 ( V_100 ) ) {
* V_149 = 0 ;
goto V_25;
}
if ( ( void * ) V_178 - ( ( void * ) F_8 ( & V_5 ) -> V_48 ) <
V_31 ) {
V_101 = ( void * ) F_8 ( & V_5 ) -> V_48 +
V_130 ;
V_92 = V_31 -
V_130 ;
} else {
V_101 = F_104 ( V_100 , & V_5 ) ;
V_92 = F_1 ( V_100 ) -
V_31 ;
}
F_30 ( V_30 , L_2 ) ;
V_111 = F_31 ( V_50 , V_30 ) ;
if ( V_111 )
goto V_25;
V_111 = F_143 ( V_50 , V_100 , V_178 , V_30 ,
V_101 , V_92 , 0 ) ;
if ( V_111 )
goto V_25;
F_94 ( V_100 , V_5 . V_30 , V_101 , V_92 ) ;
V_25:
F_45 ( V_100 , & V_61 ) ;
if ( F_144 ( V_111 == 0 ) )
V_111 = F_118 ( V_50 , V_100 ) ;
F_20 ( V_5 . V_30 ) ;
if ( V_111 != - V_179 )
F_85 ( V_100 -> V_13 , V_111 ) ;
return V_111 ;
}
static inline struct V_104 *
F_145 ( struct V_1 * V_1 ,
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
V_180 = F_104 ( V_1 , V_5 ) ;
V_102 -= V_31 ;
* V_92 = F_1 ( V_1 ) -
V_31 ;
}
if ( V_101 )
* V_101 = V_180 ;
return (struct V_104 * ) ( V_180 + V_102 ) ;
}
bool F_146 ( struct V_1 * V_100 , int * V_149 )
{
int V_111 , V_92 ;
struct V_4 V_5 ;
void * V_180 ;
unsigned int V_102 ;
struct V_104 * V_105 ;
bool V_59 = true ;
V_111 = F_16 ( V_100 , & V_5 ) ;
if ( V_111 ) {
F_147 ( V_100 , L_9 ,
V_111 , V_100 -> V_28 ) ;
return true ;
}
F_18 ( & F_2 ( V_100 ) -> V_29 ) ;
if ( ! F_54 ( V_100 ) ) {
* V_149 = 0 ;
goto V_25;
}
V_105 = (struct V_104 * ) F_8 ( & V_5 ) -> V_48 ;
if ( ! F_14 ( V_105 -> V_1 ) ) {
F_55 ( V_100 -> V_13 ,
L_10 ,
V_100 -> V_28 ) ;
V_59 = true ;
goto V_25;
}
V_102 = V_130 ;
while ( V_102 < V_100 -> V_99 ) {
V_105 = F_145 ( V_100 , & V_5 , V_102 ,
& V_180 , & V_92 ) ;
if ( F_97 ( V_100 , NULL , V_105 ,
V_5 . V_30 , V_180 ,
V_92 , V_102 ) ) {
F_55 ( V_100 -> V_13 ,
L_11
L_12
L_13 ,
V_100 -> V_28 , F_14 ( V_105 -> V_1 ) ,
F_13 ( V_105 -> V_107 ) , V_105 -> V_108 ,
V_92 ) ;
V_59 = true ;
goto V_25;
}
if ( F_14 ( V_105 -> V_1 ) ) {
V_59 = false ;
goto V_25;
}
V_102 += F_96 ( V_105 -> V_107 , V_92 ) ;
}
V_25:
F_19 ( & F_2 ( V_100 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_59 ;
}
int F_148 ( T_3 * V_50 , struct V_1 * V_1 )
{
int V_59 , V_61 ;
F_44 ( V_1 , & V_61 ) ;
V_59 = F_46 ( V_50 , V_1 ) ;
F_45 ( V_1 , & V_61 ) ;
return V_59 ;
}
int F_149 ( struct V_1 * V_1 ,
struct V_181 * V_182 ,
int * V_183 , T_5 V_184 , T_5 V_46 )
{
T_5 V_185 = 0 ;
T_5 V_186 ;
V_20 V_72 = V_187 | V_188 |
V_189 ;
int error = 0 ;
struct V_4 V_5 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_54 ( V_1 ) ) {
* V_183 = 0 ;
goto V_25;
}
V_186 = F_25 ( T_1 , F_1 ( V_1 ) ,
F_56 ( V_1 ) ) ;
if ( V_184 >= V_186 )
goto V_25;
if ( V_184 + V_46 < V_186 )
V_186 = V_184 + V_46 ;
V_186 -= V_184 ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
goto V_25;
V_185 = ( T_5 ) V_5 . V_30 -> V_190 << V_1 -> V_13 -> V_191 ;
V_185 += ( char * ) F_8 ( & V_5 ) - V_5 . V_30 -> V_128 ;
V_185 += F_150 ( struct V_10 , V_48 ) ;
if ( V_185 )
error = F_151 ( V_182 , V_184 , V_185 ,
V_186 , V_72 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return ( error < 0 ? error : 0 ) ;
}
int F_152 ( T_3 * V_50 ,
struct V_1 * V_1 ,
int V_192 )
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
if ( F_7 ( V_9 -> V_193 ) +
F_6 ( F_14 ( V_9 -> V_22 ) ) < V_192 ) {
error = - V_54 ;
goto V_25;
}
error = F_119 ( V_50 , V_1 , & V_5 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return error ;
}
int F_153 ( struct V_1 * V_1 , int * V_183 )
{
T_3 * V_50 ;
int V_92 , V_53 , V_73 , V_61 , V_111 = 0 ;
T_1 V_99 ;
void * V_51 = NULL ;
struct V_32 V_33 = {
. V_34 = { . V_35 = - V_36 , } ,
} ;
struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_18 ,
} ;
V_73 = F_66 ( V_1 ) ;
V_50 = F_67 ( V_1 , V_87 , V_73 ) ;
if ( F_68 ( V_50 ) )
return F_69 ( V_50 ) ;
F_44 ( V_1 , & V_61 ) ;
if ( ! F_54 ( V_1 ) ) {
* V_183 = 0 ;
F_78 ( V_50 ) ;
return 0 ;
}
if ( ( V_111 = F_77 ( V_50 , V_1 ) ) != 0 )
goto V_25;
if ( ( V_111 = F_16 ( V_1 , & V_33 . V_5 ) ) != 0 )
goto V_25;
F_154 ( & F_2 ( V_1 ) -> V_194 ) ;
V_99 = V_1 -> V_99 ;
V_92 = F_1 ( V_1 ) ;
F_2 ( V_1 ) -> V_120 = V_99 ;
if ( V_99 < V_92 ) {
if ( V_92 > V_31 ) {
if ( ( V_111 = V_32 ( V_1 , & V_38 , & V_33 ) ) != 0 )
goto V_195;
F_24 ( V_33 . V_34 . V_35 ) ;
V_53 = F_14 ( V_33 . V_34 . V_43 -> V_22 ) ;
V_51 = F_120 ( V_53 , V_57 ) ;
if ( ! V_51 ) {
V_111 = - V_58 ;
goto V_195;
}
V_111 = F_41 ( V_1 , V_38 . V_39 ,
V_38 . V_41 , V_51 , V_53 ) ;
if ( V_111 <= 0 )
goto V_195;
V_38 . V_51 = V_51 ;
V_38 . V_53 = V_99 > V_31 ?
V_99 - V_31 : 0 ;
V_111 = F_32 ( V_50 , V_1 ,
& V_38 , & V_33 ) ;
if ( V_111 )
goto V_195;
}
if ( V_99 < V_31 ) {
void * V_196 = ( void * ) F_8 ( & V_33 . V_5 ) -> V_48 ;
memset ( V_196 + V_99 , 0 ,
V_31 - V_99 ) ;
}
F_2 ( V_1 ) -> V_3 = V_99 <
V_31 ?
V_31 : V_99 ;
}
V_195:
F_155 ( & F_2 ( V_1 ) -> V_194 ) ;
V_25:
F_20 ( V_33 . V_5 . V_30 ) ;
F_45 ( V_1 , & V_61 ) ;
F_42 ( V_51 ) ;
if ( V_1 -> V_84 )
F_80 ( V_50 , V_1 ) ;
if ( V_111 == 0 ) {
V_1 -> V_112 = V_1 -> V_113 = F_102 ( V_1 ) ;
V_111 = F_118 ( V_50 , V_1 ) ;
if ( F_156 ( V_1 ) )
F_157 ( V_50 ) ;
}
F_78 ( V_50 ) ;
return V_111 ;
}
int F_158 ( struct V_1 * V_1 )
{
int error , V_73 , V_61 ;
T_3 * V_50 ;
struct V_4 V_5 ;
if ( ! F_54 ( V_1 ) ) {
F_33 ( V_1 , V_44 ) ;
return 0 ;
}
V_73 = F_66 ( V_1 ) ;
V_5 . V_30 = NULL ;
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
return error ;
V_50 = F_67 ( V_1 , V_79 , V_73 ) ;
if ( F_68 ( V_50 ) ) {
error = F_69 ( V_50 ) ;
goto V_197;
}
F_44 ( V_1 , & V_61 ) ;
if ( F_54 ( V_1 ) )
error = F_119 ( V_50 , V_1 , & V_5 ) ;
F_45 ( V_1 , & V_61 ) ;
F_78 ( V_50 ) ;
V_197:
F_20 ( V_5 . V_30 ) ;
return error ;
}
