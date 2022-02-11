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
V_51 = F_64 ( V_1 , V_78 , V_72 ) ;
if ( F_65 ( V_51 ) ) {
V_58 = F_66 ( V_51 ) ;
V_51 = NULL ;
goto V_25;
}
V_71 |= V_79 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_80 ;
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
V_58 = F_69 ( V_64 , V_75 , V_76 , V_81 ) ;
else
V_58 = F_69 ( V_64 , V_75 , V_76 , V_82 ) ;
if ( ! V_58 && F_70 ( V_1 ) ) {
V_58 = F_71 ( V_51 , F_72 ( V_64 ) ,
V_75 , V_76 , NULL ,
V_83 ) ;
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
if ( V_1 -> V_84 )
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
V_51 = F_64 ( V_1 , V_87 , 1 ) ;
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
if ( ! F_21 ( V_1 ) ) {
V_58 = 0 ;
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
goto V_88;
}
if ( ! F_60 ( V_64 ) ) {
V_58 = F_50 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_88;
}
V_58 = 1 ;
V_51 = NULL ;
V_88:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
V_25:
if ( V_51 )
F_75 ( V_51 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
V_86:
return F_62 ( V_70 ,
V_1 , V_71 ) ;
}
int F_81 ( struct V_1 * V_1 , T_2 V_50 , unsigned V_47 ,
unsigned V_89 , struct V_64 * V_64 )
{
int V_58 ;
void * V_65 ;
struct V_4 V_5 ;
if ( F_82 ( V_89 < V_47 ) ) {
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
return V_89 ;
}
struct V_90 *
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
void * * V_91 )
{
int V_58 = 0 , V_92 ;
struct V_64 * V_64 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 )
return - V_80 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_32 ( V_1 , V_45 ) ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
if ( ! F_60 ( V_64 ) ) {
V_58 = F_50 ( V_1 , V_64 ) ;
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
F_32 ( V_1 , V_45 ) ;
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
T_2 V_50 , unsigned V_47 ,
unsigned V_71 ,
struct V_64 * * V_85 ,
void * * V_91 )
{
int V_58 , V_92 ;
T_3 * V_51 ;
struct V_64 * V_64 ;
struct V_4 V_5 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_51 = F_64 ( V_1 , V_87 , 1 ) ;
if ( F_65 ( V_51 ) ) {
V_58 = F_66 ( V_51 ) ;
V_51 = NULL ;
goto V_25;
}
V_92 = F_15 ( V_1 ) ;
V_58 = - V_55 ;
if ( V_92 >= V_50 + V_47 ) {
V_58 = F_41 ( V_51 , V_1 , V_50 + V_47 ) ;
if ( V_58 && V_58 != - V_55 )
goto V_25;
}
if ( V_58 == - V_55 ) {
V_58 = F_86 ( V_70 ,
V_1 ,
V_71 ,
V_91 ) ;
goto V_25;
}
V_71 |= V_79 ;
V_64 = F_67 ( V_70 , 0 , V_71 ) ;
if ( ! V_64 ) {
V_58 = - V_80 ;
goto V_25;
}
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
V_58 = 0 ;
goto V_95;
}
if ( ! F_60 ( V_64 ) ) {
V_58 = F_50 ( V_1 , V_64 ) ;
if ( V_58 < 0 )
goto V_95;
}
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_85 = V_64 ;
V_51 = NULL ;
F_20 ( V_5 . V_30 ) ;
return 1 ;
V_95:
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
unsigned V_47 , unsigned V_89 ,
struct V_64 * V_64 )
{
int V_96 = 0 ;
V_89 = F_81 ( V_1 , V_50 , V_47 , V_89 , V_64 ) ;
if ( V_50 + V_89 > V_1 -> V_97 ) {
F_90 ( V_1 , V_50 + V_89 ) ;
V_96 = 1 ;
}
F_61 ( V_64 ) ;
F_73 ( V_64 ) ;
if ( V_96 )
F_91 ( V_1 ) ;
return V_89 ;
}
void F_92 ( struct V_1 * V_98 , struct V_90 * V_30 ,
void * V_99 , int V_92 )
{
int V_100 ;
unsigned short V_101 ;
struct V_102 * V_103 = V_99 ;
void * V_104 = V_99 + V_92 ;
F_93 ( L_4 , V_98 -> V_28 ) ;
V_100 = 0 ;
while ( ( void * ) V_103 < V_104 ) {
V_101 = F_94 ( V_103 -> V_105 , V_92 ) ;
F_93 ( L_5 ,
V_100 , V_101 , V_103 -> V_106 , V_103 -> V_42 ,
V_103 -> V_106 , F_14 ( V_103 -> V_1 ) ) ;
if ( F_95 ( V_98 , NULL , V_103 , V_30 ,
V_99 , V_92 , V_100 ) )
F_96 () ;
V_100 += V_101 ;
V_103 = (struct V_102 * ) ( ( char * ) V_103 + V_101 ) ;
}
}
static int F_97 ( T_3 * V_51 ,
struct V_107 * V_107 ,
struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_99 , int V_92 )
{
struct V_1 * V_98 = V_107 -> V_108 -> V_109 ;
const char * V_42 = V_107 -> V_110 . V_42 ;
int V_111 = V_107 -> V_110 . V_47 ;
int V_112 ;
struct V_102 * V_103 ;
V_112 = F_98 ( V_98 , V_1 , V_5 -> V_30 ,
V_99 , V_92 ,
V_42 , V_111 , & V_103 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_30 ( V_51 , V_5 -> V_30 ) ;
if ( V_112 )
return V_112 ;
F_99 ( V_1 , V_103 , V_92 , V_42 , V_111 ) ;
F_92 ( V_98 , V_5 -> V_30 , V_99 , V_92 ) ;
V_98 -> V_113 = V_98 -> V_114 = F_100 ( V_98 ) ;
F_101 ( V_98 ) ;
V_98 -> V_115 ++ ;
F_102 ( V_51 , V_98 ) ;
return 1 ;
}
static void * F_103 ( struct V_1 * V_1 ,
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
static void F_104 ( void * V_116 , int V_117 , int V_118 )
{
struct V_102 * V_103 , * V_119 ;
void * V_120 ;
int V_101 ;
V_103 = (struct V_102 * ) V_116 ;
if ( V_117 ) {
V_120 = V_116 + V_117 ;
do {
V_119 = V_103 ;
V_101 = F_94 ( V_103 -> V_105 , V_117 ) ;
V_116 += V_101 ;
V_103 = (struct V_102 * ) V_116 ;
} while ( V_116 < V_120 );
V_119 -> V_105 = F_105 ( V_101 + V_118 -
V_117 , V_118 ) ;
} else {
V_103 -> V_1 = 0 ;
V_103 -> V_105 = F_105 ( V_118 , V_118 ) ;
}
}
static int F_106 ( T_3 * V_51 , struct V_1 * V_98 ,
struct V_4 * V_5 )
{
int V_58 ;
int V_117 = F_2 ( V_98 ) -> V_3 - V_31 ;
int V_118 = F_3 ( V_98 , V_5 ) ;
if ( V_118 - V_117 <= F_107 ( 1 ) )
return - V_55 ;
V_58 = F_37 ( V_51 , V_98 ,
V_118 + V_31 ) ;
if ( V_58 )
return V_58 ;
F_104 ( F_103 ( V_98 , V_5 ) , V_117 ,
F_2 ( V_98 ) -> V_3 -
V_31 ) ;
V_98 -> V_97 = F_2 ( V_98 ) -> V_121 = F_2 ( V_98 ) -> V_3 ;
return 0 ;
}
static void F_108 ( T_3 * V_51 , struct V_1 * V_1 ,
struct V_4 * V_5 ,
void * V_122 , int V_92 )
{
F_29 ( V_51 , V_1 , V_92 ) ;
F_28 ( V_1 , V_5 , V_122 , 0 , V_92 ) ;
F_24 ( V_1 , V_45 ) ;
}
static int F_109 ( T_3 * V_51 ,
struct V_1 * V_1 ,
struct V_90 * V_123 ,
void * V_122 ,
int V_92 )
{
int V_112 , V_124 = 0 , V_125 = 0 ;
struct V_102 * V_103 ;
struct V_126 * V_127 ;
void * V_128 = V_123 -> V_129 ;
V_103 = (struct V_102 * ) V_128 ;
V_103 = F_110 ( V_1 , V_103 ,
V_1 -> V_13 -> V_130 , V_124 ,
F_14 ( ( (struct V_102 * ) V_122 ) -> V_1 ) , 1 ) ;
V_125 = ( void * ) V_103 - V_128 ;
memcpy ( ( void * ) V_103 , V_122 + V_131 ,
V_92 - V_131 ) ;
if ( F_111 ( V_1 -> V_13 ,
V_132 ) )
V_124 = sizeof( struct V_126 ) ;
V_1 -> V_97 = V_1 -> V_13 -> V_130 ;
F_90 ( V_1 , V_1 -> V_13 -> V_130 ) ;
F_2 ( V_1 ) -> V_121 = V_1 -> V_13 -> V_130 ;
F_104 ( V_123 -> V_129 ,
V_92 - V_131 + V_125 ,
V_1 -> V_13 -> V_130 - V_124 ) ;
if ( V_124 ) {
V_127 = F_112 ( V_123 -> V_129 ,
V_1 -> V_13 -> V_130 ) ;
F_113 ( V_127 , V_1 -> V_13 -> V_130 ) ;
}
F_114 ( V_123 ) ;
V_112 = F_115 ( V_51 , V_1 , V_123 ) ;
if ( V_112 )
goto V_25;
F_116 ( V_123 ) ;
V_25:
return V_112 ;
}
static int F_117 ( T_3 * V_51 ,
struct V_1 * V_1 ,
struct V_4 * V_5 )
{
int error ;
void * V_122 = NULL ;
struct V_90 * V_133 = NULL ;
struct V_134 V_135 ;
int V_92 ;
V_92 = F_1 ( V_1 ) ;
V_122 = F_118 ( V_92 , V_57 ) ;
if ( ! V_122 ) {
error = - V_80 ;
goto V_25;
}
error = F_25 ( V_1 , V_122 , V_92 , V_5 ) ;
if ( error < 0 )
goto V_25;
error = F_44 ( V_51 , V_1 ) ;
if ( error )
goto V_25;
V_135 . V_136 = 0 ;
V_135 . V_137 = 1 ;
V_135 . V_138 = 0 ;
error = V_134 ( V_51 , V_1 , & V_135 , V_139 ) ;
if ( error < 0 )
goto V_140;
if ( ! ( V_135 . V_138 & V_141 ) ) {
error = - V_142 ;
goto V_140;
}
V_133 = F_119 ( V_1 -> V_13 , V_135 . V_143 ) ;
if ( ! V_133 ) {
error = - V_80 ;
goto V_140;
}
F_120 ( V_133 ) ;
error = F_121 ( V_51 , V_133 ) ;
if ( error ) {
F_122 ( V_133 ) ;
error = - V_142 ;
goto V_140;
}
memset ( V_133 -> V_129 , 0 , V_1 -> V_13 -> V_130 ) ;
if ( ! F_46 ( V_1 -> V_63 ) ) {
memcpy ( V_133 -> V_129 , V_122 , V_92 ) ;
F_114 ( V_133 ) ;
error = F_123 ( V_51 ,
V_1 , V_133 ) ;
} else {
error = F_109 ( V_51 , V_1 , V_133 ,
V_122 , V_92 ) ;
}
F_122 ( V_133 ) ;
V_140:
if ( error )
F_108 ( V_51 , V_1 , V_5 , V_122 , V_92 ) ;
V_25:
F_20 ( V_133 ) ;
F_40 ( V_122 ) ;
return error ;
}
int F_124 ( T_3 * V_51 , struct V_107 * V_107 ,
struct V_1 * V_1 )
{
int V_58 , V_92 ;
void * V_99 ;
struct V_4 V_5 ;
struct V_1 * V_98 = V_107 -> V_108 -> V_109 ;
V_58 = F_16 ( V_98 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_42 ( & F_2 ( V_98 ) -> V_29 ) ;
if ( ! F_21 ( V_98 ) )
goto V_25;
V_99 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_131 ;
V_92 = V_31 - V_131 ;
V_58 = F_97 ( V_51 , V_107 , V_1 , & V_5 ,
V_99 , V_92 ) ;
if ( V_58 != - V_55 )
goto V_25;
V_92 = F_2 ( V_98 ) -> V_3 -
V_31 ;
if ( ! V_92 ) {
V_58 = F_106 ( V_51 , V_98 , & V_5 ) ;
if ( V_58 && V_58 != - V_55 )
goto V_25;
V_92 = F_2 ( V_98 ) -> V_3 -
V_31 ;
}
if ( V_92 ) {
V_99 = F_103 ( V_98 , & V_5 ) ;
V_58 = F_97 ( V_51 , V_107 , V_1 , & V_5 ,
V_99 , V_92 ) ;
if ( V_58 != - V_55 )
goto V_25;
}
V_58 = F_117 ( V_51 , V_98 , & V_5 ) ;
V_25:
F_102 ( V_51 , V_98 ) ;
F_43 ( & F_2 ( V_98 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_125 ( struct V_144 * V_145 ,
struct V_1 * V_98 , T_4 V_146 ,
struct V_147 * V_148 ,
V_20 V_149 , V_20 V_150 ,
int * V_151 )
{
int V_112 = 0 , V_152 = 0 ;
unsigned int V_153 ;
int V_50 ;
struct V_102 * V_103 ;
struct V_1 * V_1 = F_126 ( V_145 ) ;
int V_58 , V_92 = 0 ;
struct V_4 V_5 ;
void * V_154 = NULL ;
struct V_102 V_155 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_151 = 0 ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
V_154 = F_118 ( V_92 , V_57 ) ;
if ( ! V_154 ) {
V_58 = - V_80 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_25 ( V_1 , V_154 , V_92 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_50 = 0 ;
V_153 = F_14 ( ( (struct V_102 * ) V_154 ) -> V_1 ) ;
while ( V_50 < V_92 ) {
if ( V_50 == 0 ) {
V_155 . V_1 = F_127 ( V_1 -> V_28 ) ;
V_155 . V_106 = 1 ;
strcpy ( V_155 . V_42 , L_6 ) ;
V_155 . V_105 = F_105 (
F_107 ( V_155 . V_106 ) ,
V_92 ) ;
F_128 ( V_1 -> V_13 , & V_155 , V_156 ) ;
V_103 = & V_155 ;
V_50 = V_157 ;
} else if ( V_50 == V_157 ) {
V_155 . V_1 = F_127 ( V_153 ) ;
V_155 . V_106 = 2 ;
strcpy ( V_155 . V_42 , L_7 ) ;
V_155 . V_105 = F_105 (
F_107 ( V_155 . V_106 ) ,
V_92 ) ;
F_128 ( V_1 -> V_13 , & V_155 , V_156 ) ;
V_103 = & V_155 ;
V_50 = V_131 ;
} else {
V_103 = (struct V_102 * ) ( V_154 + V_50 ) ;
V_50 += F_94 ( V_103 -> V_105 , V_92 ) ;
if ( F_95 ( V_1 , V_145 , V_103 ,
V_5 . V_30 , V_154 ,
V_92 , V_50 ) ) {
V_58 = V_152 ;
goto V_25;
}
}
F_129 ( V_103 -> V_42 , V_103 -> V_106 , V_148 ) ;
if ( ( V_148 -> V_158 < V_149 ) ||
( ( V_148 -> V_158 == V_149 ) &&
( V_148 -> V_159 < V_150 ) ) )
continue;
if ( V_103 -> V_1 == 0 )
continue;
V_112 = F_130 ( V_145 ,
V_148 -> V_158 , V_148 -> V_159 , V_103 ) ;
if ( V_112 ) {
V_152 = V_112 ;
goto V_25;
}
V_152 ++ ;
}
V_58 = V_152 ;
V_25:
F_40 ( V_154 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_131 ( struct V_144 * V_144 ,
struct V_160 * V_161 ,
int * V_151 )
{
unsigned int V_100 , V_153 ;
int V_39 ;
struct V_102 * V_103 ;
struct V_162 * V_163 ;
struct V_1 * V_1 = F_126 ( V_144 ) ;
int V_58 , V_92 = 0 ;
struct V_4 V_5 ;
void * V_154 = NULL ;
int V_164 , V_165 , V_166 , V_167 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
* V_151 = 0 ;
goto V_25;
}
V_92 = F_1 ( V_1 ) ;
V_154 = F_118 ( V_92 , V_57 ) ;
if ( ! V_154 ) {
V_58 = - V_80 ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
goto V_25;
}
V_58 = F_25 ( V_1 , V_154 , V_92 , & V_5 ) ;
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( V_58 < 0 )
goto V_25;
V_58 = 0 ;
V_163 = V_1 -> V_13 ;
V_153 = F_14 ( ( (struct V_102 * ) V_154 ) -> V_1 ) ;
V_100 = V_161 -> V_50 ;
V_164 = F_107 ( 1 ) ;
V_165 = V_164 + F_107 ( 2 ) ;
V_166 = V_165 - V_131 ;
V_167 = V_166 + V_92 ;
if ( V_144 -> V_168 != V_1 -> V_115 ) {
for ( V_39 = 0 ; V_39 < V_167 && V_39 < V_100 ; ) {
if ( ! V_39 ) {
V_39 = V_164 ;
continue;
} else if ( V_39 == V_164 ) {
V_39 = V_165 ;
continue;
}
V_103 = (struct V_102 * )
( V_154 + V_39 - V_166 ) ;
if ( F_94 ( V_103 -> V_105 , V_167 )
< F_107 ( 1 ) )
break;
V_39 += F_94 ( V_103 -> V_105 ,
V_167 ) ;
}
V_100 = V_39 ;
V_161 -> V_50 = V_100 ;
V_144 -> V_168 = V_1 -> V_115 ;
}
while ( V_161 -> V_50 < V_167 ) {
if ( V_161 -> V_50 == 0 ) {
if ( ! F_132 ( V_161 , L_6 , 1 , V_1 -> V_28 , V_169 ) )
goto V_25;
V_161 -> V_50 = V_164 ;
continue;
}
if ( V_161 -> V_50 == V_164 ) {
if ( ! F_132 ( V_161 , L_7 , 2 , V_153 , V_169 ) )
goto V_25;
V_161 -> V_50 = V_165 ;
continue;
}
V_103 = (struct V_102 * )
( V_154 + V_161 -> V_50 - V_166 ) ;
if ( F_95 ( V_1 , V_144 , V_103 , V_5 . V_30 , V_154 ,
V_167 , V_161 -> V_50 ) )
goto V_25;
if ( F_14 ( V_103 -> V_1 ) ) {
if ( ! F_132 ( V_161 , V_103 -> V_42 , V_103 -> V_106 ,
F_14 ( V_103 -> V_1 ) ,
F_133 ( V_163 , V_103 -> V_170 ) ) )
goto V_25;
}
V_161 -> V_50 += F_94 ( V_103 -> V_105 , V_167 ) ;
}
V_25:
F_40 ( V_154 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_90 * F_134 ( struct V_1 * V_1 ,
struct V_102 * * V_171 ,
int * V_172 )
{
struct V_4 V_5 ;
* V_172 = F_16 ( V_1 , & V_5 ) ;
if ( * V_172 )
return NULL ;
* V_171 = (struct V_102 * ) F_8 ( & V_5 ) -> V_49 ;
return V_5 . V_30 ;
}
int F_135 ( T_3 * V_51 , struct V_1 * V_173 ,
struct V_1 * V_1 )
{
int V_58 , V_92 = V_31 ;
struct V_4 V_5 ;
struct V_102 * V_103 ;
V_58 = F_16 ( V_1 , & V_5 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_41 ( V_51 , V_1 , V_92 ) ;
if ( V_58 )
goto V_25;
V_103 = (struct V_102 * ) F_8 ( & V_5 ) -> V_49 ;
V_103 -> V_1 = F_127 ( V_173 -> V_28 ) ;
V_103 = (struct V_102 * ) ( ( void * ) V_103 + V_131 ) ;
V_103 -> V_1 = 0 ;
V_103 -> V_105 = F_105 (
V_92 - V_131 ,
V_92 ) ;
F_136 ( V_1 , 2 ) ;
V_1 -> V_97 = F_2 ( V_1 ) -> V_121 = V_92 ;
V_25:
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
struct V_90 * F_137 ( struct V_1 * V_98 ,
const struct V_174 * V_110 ,
struct V_102 * * V_175 ,
int * V_151 )
{
int V_58 ;
struct V_4 V_5 ;
void * V_99 ;
int V_92 ;
if ( F_16 ( V_98 , & V_5 ) )
return NULL ;
F_18 ( & F_2 ( V_98 ) -> V_29 ) ;
if ( ! F_21 ( V_98 ) ) {
* V_151 = 0 ;
goto V_25;
}
V_99 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_131 ;
V_92 = V_31 - V_131 ;
V_58 = F_138 ( V_5 . V_30 , V_99 , V_92 ,
V_98 , V_110 , 0 , V_175 ) ;
if ( V_58 == 1 )
goto V_176;
if ( V_58 < 0 )
goto V_25;
if ( F_1 ( V_98 ) == V_31 )
goto V_25;
V_99 = F_103 ( V_98 , & V_5 ) ;
V_92 = F_1 ( V_98 ) - V_31 ;
V_58 = F_138 ( V_5 . V_30 , V_99 , V_92 ,
V_98 , V_110 , 0 , V_175 ) ;
if ( V_58 == 1 )
goto V_176;
V_25:
F_20 ( V_5 . V_30 ) ;
V_5 . V_30 = NULL ;
V_176:
F_19 ( & F_2 ( V_98 ) -> V_29 ) ;
return V_5 . V_30 ;
}
int F_139 ( T_3 * V_51 ,
struct V_1 * V_98 ,
struct V_102 * V_177 ,
struct V_90 * V_30 ,
int * V_151 )
{
int V_112 , V_92 ;
struct V_4 V_5 ;
void * V_99 ;
V_112 = F_16 ( V_98 , & V_5 ) ;
if ( V_112 )
return V_112 ;
F_42 ( & F_2 ( V_98 ) -> V_29 ) ;
if ( ! F_21 ( V_98 ) ) {
* V_151 = 0 ;
goto V_25;
}
if ( ( void * ) V_177 - ( ( void * ) F_8 ( & V_5 ) -> V_49 ) <
V_31 ) {
V_99 = ( void * ) F_8 ( & V_5 ) -> V_49 +
V_131 ;
V_92 = V_31 -
V_131 ;
} else {
V_99 = F_103 ( V_98 , & V_5 ) ;
V_92 = F_1 ( V_98 ) -
V_31 ;
}
V_112 = F_30 ( V_51 , V_30 ) ;
if ( V_112 )
goto V_25;
V_112 = F_140 ( V_51 , V_98 , V_177 , V_30 ,
V_99 , V_92 , 0 ) ;
if ( V_112 )
goto V_25;
F_141 ( V_30 , L_8 ) ;
V_112 = F_102 ( V_51 , V_98 ) ;
if ( F_82 ( V_112 ) )
goto V_25;
F_92 ( V_98 , V_5 . V_30 , V_99 , V_92 ) ;
V_25:
F_43 ( & F_2 ( V_98 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
if ( V_112 != - V_178 )
F_83 ( V_98 -> V_13 , V_112 ) ;
return V_112 ;
}
static inline struct V_102 *
F_142 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned int V_100 ,
void * * V_99 ,
int * V_92 )
{
void * V_179 ;
F_26 ( V_100 > F_1 ( V_1 ) ) ;
if ( V_100 < V_31 ) {
V_179 = ( void * ) F_8 ( V_5 ) -> V_49 ;
* V_92 = V_31 ;
} else {
V_179 = F_103 ( V_1 , V_5 ) ;
V_100 -= V_31 ;
* V_92 = F_1 ( V_1 ) -
V_31 ;
}
if ( V_99 )
* V_99 = V_179 ;
return (struct V_102 * ) ( V_179 + V_100 ) ;
}
int F_143 ( struct V_1 * V_98 , int * V_151 )
{
int V_112 , V_92 ;
struct V_4 V_5 ;
void * V_179 ;
unsigned int V_100 ;
struct V_102 * V_103 ;
int V_58 = 1 ;
V_112 = F_16 ( V_98 , & V_5 ) ;
if ( V_112 ) {
F_144 ( V_98 , L_9 ,
V_112 , V_98 -> V_28 ) ;
return 1 ;
}
F_18 ( & F_2 ( V_98 ) -> V_29 ) ;
if ( ! F_21 ( V_98 ) ) {
* V_151 = 0 ;
goto V_25;
}
V_103 = (struct V_102 * ) F_8 ( & V_5 ) -> V_49 ;
if ( ! F_14 ( V_103 -> V_1 ) ) {
F_52 ( V_98 -> V_13 ,
L_10 ,
V_98 -> V_28 ) ;
V_58 = 1 ;
goto V_25;
}
V_100 = V_131 ;
while ( V_100 < V_98 -> V_97 ) {
V_103 = F_142 ( V_98 , & V_5 , V_100 ,
& V_179 , & V_92 ) ;
if ( F_95 ( V_98 , NULL , V_103 ,
V_5 . V_30 , V_179 ,
V_92 , V_100 ) ) {
F_52 ( V_98 -> V_13 ,
L_11
L_12
L_13 ,
V_98 -> V_28 , F_14 ( V_103 -> V_1 ) ,
F_13 ( V_103 -> V_105 ) , V_103 -> V_106 ,
V_92 ) ;
V_58 = 1 ;
goto V_25;
}
if ( F_14 ( V_103 -> V_1 ) ) {
V_58 = 0 ;
goto V_25;
}
V_100 += F_94 ( V_103 -> V_105 , V_92 ) ;
}
V_25:
F_19 ( & F_2 ( V_98 ) -> V_29 ) ;
F_20 ( V_5 . V_30 ) ;
return V_58 ;
}
int F_145 ( T_3 * V_51 , struct V_1 * V_1 )
{
int V_58 ;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
V_58 = F_44 ( V_51 , V_1 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
return V_58 ;
}
int F_146 ( struct V_1 * V_1 ,
struct V_180 * V_181 ,
int * V_182 )
{
T_5 V_183 = 0 ;
T_5 V_184 ;
V_20 V_71 = V_185 | V_186 ;
int error = 0 ;
struct V_4 V_5 ;
F_18 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
* V_182 = 0 ;
goto V_25;
}
error = F_16 ( V_1 , & V_5 ) ;
if ( error )
goto V_25;
V_183 = ( T_5 ) V_5 . V_30 -> V_187 << V_1 -> V_13 -> V_188 ;
V_183 += ( char * ) F_8 ( & V_5 ) - V_5 . V_30 -> V_129 ;
V_183 += F_147 ( struct V_10 , V_49 ) ;
V_184 = F_53 ( V_1 ) ;
if ( V_183 )
error = F_148 ( V_181 , 0 , V_183 ,
V_184 , V_71 ) ;
F_20 ( V_5 . V_30 ) ;
V_25:
F_19 ( & F_2 ( V_1 ) -> V_29 ) ;
return ( error < 0 ? error : 0 ) ;
}
int F_149 ( T_3 * V_51 ,
struct V_1 * V_1 ,
int V_189 )
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
if ( F_7 ( V_9 -> V_190 ) +
F_6 ( F_14 ( V_9 -> V_22 ) ) < V_189 ) {
error = - V_55 ;
goto V_25;
}
error = F_117 ( V_51 , V_1 , & V_5 ) ;
V_25:
F_20 ( V_5 . V_30 ) ;
return error ;
}
void F_150 ( struct V_1 * V_1 , int * V_182 )
{
T_3 * V_51 ;
int V_92 , V_54 , V_72 ;
T_1 V_97 ;
void * V_52 = NULL ;
struct V_33 V_34 = {
. V_35 = { . V_36 = - V_37 , } ,
} ;
struct V_38 V_39 = {
. V_40 = V_41 ,
. V_42 = V_18 ,
} ;
V_72 = F_63 ( V_1 ) ;
V_51 = F_64 ( V_1 , V_87 , V_72 ) ;
if ( F_65 ( V_51 ) )
return;
F_42 ( & F_2 ( V_1 ) -> V_29 ) ;
if ( ! F_21 ( V_1 ) ) {
* V_182 = 0 ;
F_75 ( V_51 ) ;
return;
}
if ( F_74 ( V_51 , V_1 ) )
goto V_25;
if ( F_16 ( V_1 , & V_34 . V_5 ) )
goto V_25;
F_42 ( & F_2 ( V_1 ) -> V_191 ) ;
V_97 = V_1 -> V_97 ;
V_92 = F_1 ( V_1 ) ;
F_2 ( V_1 ) -> V_121 = V_97 ;
if ( V_97 < V_92 ) {
if ( V_92 > V_31 ) {
if ( V_33 ( V_1 , & V_39 , & V_34 ) )
goto V_192;
F_26 ( V_34 . V_35 . V_36 ) ;
V_54 = F_14 ( V_34 . V_35 . V_44 -> V_22 ) ;
V_52 = F_118 ( V_54 , V_57 ) ;
if ( ! V_52 )
goto V_192;
if ( F_39 ( V_1 , V_39 . V_40 , V_39 . V_42 ,
V_52 , V_54 ) )
goto V_192;
V_39 . V_52 = V_52 ;
V_39 . V_54 = V_97 > V_31 ?
V_97 - V_31 : 0 ;
if ( F_31 ( V_51 , V_1 , & V_39 , & V_34 ) )
goto V_192;
}
if ( V_97 < V_31 )
memset ( F_8 ( & V_34 . V_5 ) -> V_49 + V_97 , 0 ,
V_31 - V_97 ) ;
F_2 ( V_1 ) -> V_3 = V_97 <
V_31 ?
V_31 : V_97 ;
}
V_192:
F_43 ( & F_2 ( V_1 ) -> V_191 ) ;
V_25:
F_20 ( V_34 . V_5 . V_30 ) ;
F_43 ( & F_2 ( V_1 ) -> V_29 ) ;
F_40 ( V_52 ) ;
if ( V_1 -> V_84 )
F_77 ( V_51 , V_1 ) ;
V_1 -> V_113 = V_1 -> V_114 = F_100 ( V_1 ) ;
F_102 ( V_51 , V_1 ) ;
if ( F_151 ( V_1 ) )
F_152 ( V_51 ) ;
F_75 ( V_51 ) ;
return;
}
int F_153 ( struct V_1 * V_1 )
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
V_51 = F_64 ( V_1 , V_78 , V_72 ) ;
if ( F_65 ( V_51 ) ) {
error = F_66 ( V_51 ) ;
goto V_193;
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
V_193:
F_20 ( V_5 . V_30 ) ;
return error ;
}
