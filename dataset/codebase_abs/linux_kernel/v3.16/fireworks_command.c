static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const T_1 * V_5 , unsigned int V_6 ,
const T_1 * V_7 , unsigned int V_8 )
{
struct V_9 * V_10 ;
T_1 * V_11 ;
T_2 V_12 ;
unsigned int V_13 , V_14 ;
int V_15 ;
V_13 = sizeof( struct V_9 ) +
F_2 ( V_6 , V_8 ) ;
V_11 = F_3 ( V_13 , V_16 ) ;
if ( V_11 == NULL )
return - V_17 ;
F_4 ( & V_2 -> V_18 ) ;
if ( ( V_2 -> V_12 < V_19 ) ||
( V_2 -> V_12 >= V_20 - 2 ) )
V_2 -> V_12 = V_19 ;
else
V_2 -> V_12 += 2 ;
V_12 = V_2 -> V_12 ;
F_5 ( & V_2 -> V_18 ) ;
V_14 = sizeof( struct V_9 ) + V_6 ;
V_10 = (struct V_9 * ) V_11 ;
V_10 -> V_21 = F_6 ( V_14 / sizeof( T_1 ) ) ;
V_10 -> V_22 = F_6 ( 1 ) ;
V_10 -> V_12 = F_6 ( V_12 ) ;
V_10 -> V_3 = F_6 ( V_3 ) ;
V_10 -> V_4 = F_6 ( V_4 ) ;
V_10 -> V_23 = 0 ;
memcpy ( V_10 -> V_5 , V_5 , V_6 ) ;
V_15 = F_7 ( V_2 -> V_24 , V_11 , V_14 ,
V_11 , V_13 ) ;
if ( V_15 < 0 )
goto V_25;
if ( ( F_8 ( V_10 -> V_22 ) < 1 ) ||
( F_8 ( V_10 -> V_3 ) != V_3 ) ||
( F_8 ( V_10 -> V_4 ) != V_4 ) ||
( F_8 ( V_10 -> V_23 ) != V_26 ) ) {
F_9 ( & V_2 -> V_24 -> V_27 , L_1 ,
F_8 ( V_10 -> V_3 ) ,
F_8 ( V_10 -> V_4 ) ,
V_28 [ F_8 ( V_10 -> V_23 ) ] ) ;
V_15 = - V_29 ;
goto V_25;
}
if ( V_7 == NULL )
goto V_25;
memset ( ( void * ) V_7 , 0 , V_8 ) ;
V_8 = F_10 (unsigned int, resp_bytes,
be32_to_cpu(header->length) * sizeof(__be32) -
sizeof(struct snd_efw_transaction)) ;
memcpy ( ( void * ) V_7 , & V_11 [ 6 ] , V_8 ) ;
V_25:
F_11 ( V_11 ) ;
return V_15 ;
}
int F_12 ( struct V_1 * V_2 ,
T_3 V_30 , T_2 V_31 )
{
T_1 V_32 [ 2 ] ;
V_32 [ 0 ] = F_6 ( V_30 ) ;
V_32 [ 1 ] = F_6 ( V_31 ) ;
if ( ! V_2 -> V_33 )
return - V_34 ;
return F_1 ( V_2 , V_35 ,
V_36 ,
V_32 , sizeof( V_32 ) , NULL , 0 ) ;
}
int F_13 ( struct V_1 * V_2 ,
enum V_37 V_38 )
{
T_1 V_39 = F_6 ( V_38 ) ;
return F_1 ( V_2 , V_40 ,
V_41 ,
& V_39 , sizeof( V_39 ) , NULL , 0 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
int V_15 ;
V_15 = F_1 ( V_2 , V_44 ,
V_45 ,
NULL , 0 , ( T_1 * ) V_43 , sizeof( * V_43 ) ) ;
if ( V_15 < 0 )
goto V_25;
F_15 ( & V_43 -> V_46 ) ;
F_15 ( & V_43 -> V_47 ) ;
F_15 ( & V_43 -> V_48 ) ;
F_15 ( & V_43 -> type ) ;
F_15 ( & V_43 -> V_22 ) ;
F_15 ( & V_43 -> V_49 ) ;
F_15 ( & V_43 -> V_50 ) ;
F_15 ( & V_43 -> V_51 ) ;
F_15 ( & V_43 -> V_52 ) ;
F_15 ( & V_43 -> V_53 ) ;
F_15 ( & V_43 -> V_54 ) ;
F_15 ( & V_43 -> V_55 ) ;
F_15 ( & V_43 -> V_56 ) ;
F_15 ( & V_43 -> V_57 ) ;
F_15 ( & V_43 -> V_58 ) ;
F_15 ( & V_43 -> V_59 ) ;
F_15 ( & V_43 -> V_60 ) ;
F_15 ( & V_43 -> V_61 ) ;
F_15 ( & V_43 -> V_62 ) ;
F_15 ( & V_43 -> V_63 ) ;
F_15 ( & V_43 -> V_64 ) ;
F_15 ( & V_43 -> V_65 ) ;
F_15 ( & V_43 -> V_66 ) ;
F_15 ( & V_43 -> V_67 ) ;
F_15 ( & V_43 -> V_68 ) ;
V_43 -> V_69 [ V_70 - 1 ] = '\0' ;
V_43 -> V_71 [ V_70 - 1 ] = '\0' ;
V_25:
return V_15 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
unsigned int V_74 )
{
T_1 * V_11 = ( T_1 * ) V_73 ;
unsigned int V_75 ;
int V_15 ;
V_15 = F_1 ( V_2 , V_44 ,
V_76 ,
NULL , 0 , ( T_1 * ) V_73 , V_74 ) ;
if ( V_15 >= 0 )
for ( V_75 = 0 ; V_75 < V_74 / sizeof( T_2 ) ; V_75 ++ )
F_15 ( & V_11 [ V_75 ] ) ;
return V_15 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_77 * clock )
{
int V_15 ;
V_15 = F_1 ( V_2 , V_35 ,
V_78 ,
NULL , 0 ,
( T_1 * ) clock , sizeof( struct V_77 ) ) ;
if ( V_15 >= 0 ) {
F_15 ( & clock -> V_79 ) ;
F_15 ( & clock -> V_80 ) ;
F_15 ( & clock -> V_81 ) ;
}
return V_15 ;
}
static int
F_18 ( struct V_1 * V_2 ,
unsigned int V_79 , unsigned int V_82 )
{
struct V_77 clock = { 0 } ;
int V_15 ;
if ( ( V_79 == V_83 ) && ( V_82 == V_83 ) ) {
V_15 = - V_84 ;
goto V_25;
}
V_15 = F_17 ( V_2 , & clock ) ;
if ( V_15 < 0 )
goto V_25;
if ( ( clock . V_79 == V_79 ) && ( clock . V_80 == V_82 ) )
goto V_25;
if ( ( V_79 != V_83 ) && ( clock . V_79 != V_79 ) )
clock . V_79 = V_79 ;
if ( ( V_82 != V_83 ) && ( clock . V_80 != V_82 ) )
clock . V_80 = V_82 ;
clock . V_81 = 0 ;
F_19 ( & clock . V_79 ) ;
F_19 ( & clock . V_80 ) ;
F_19 ( & clock . V_81 ) ;
V_15 = F_1 ( V_2 , V_35 ,
V_85 ,
( T_1 * ) & clock , sizeof( struct V_77 ) ,
NULL , 0 ) ;
if ( V_15 < 0 )
goto V_25;
F_20 ( 150 ) ;
V_25:
return V_15 ;
}
int F_21 ( struct V_1 * V_2 ,
enum V_86 * V_79 )
{
int V_15 ;
struct V_77 clock = { 0 } ;
V_15 = F_17 ( V_2 , & clock ) ;
if ( V_15 >= 0 )
* V_79 = clock . V_79 ;
return V_15 ;
}
int F_22 ( struct V_1 * V_2 , unsigned int * V_82 )
{
int V_15 ;
struct V_77 clock = { 0 } ;
V_15 = F_17 ( V_2 , & clock ) ;
if ( V_15 >= 0 )
* V_82 = clock . V_80 ;
return V_15 ;
}
int F_23 ( struct V_1 * V_2 , unsigned int V_82 )
{
return F_18 ( V_2 , V_83 , V_82 ) ;
}
