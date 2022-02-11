static inline void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 - 1 )
V_2 -> V_3 = 0 ;
else
V_2 -> V_3 ++ ;
}
static struct V_5 * F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_7 , V_8 ;
V_7 = V_6 / V_9 ;
V_8 = V_6 % V_9 ;
return (struct V_5 * )
( V_2 -> V_10 [ V_7 ] + sizeof( struct V_5 ) * V_8 ) ;
}
static int F_3 ( T_1 type , struct V_5 * V_11 )
{
struct V_5 * V_12 ;
struct V_1 * V_2 = & V_13 ;
unsigned long V_14 ;
int V_15 = 0 ;
F_4 ( & V_2 -> V_16 , V_14 ) ;
V_12 = F_2 ( V_2 , V_2 -> V_3 ) ;
if ( ! V_12 -> V_17 . V_18 )
F_1 ( V_2 ) ;
else
V_15 = - V_19 ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_12 , V_11 , sizeof( * V_12 ) ) ;
V_12 -> V_17 . type = type ;
F_6 () ;
V_12 -> V_17 . V_18 = 1 ;
F_7 ( F_8 ( V_12 ) ) ;
F_9 ( & V_20 ) ;
return 0 ;
}
int F_10 ( struct V_21 * V_22 , T_2 V_23 ,
struct V_24 * V_25 , T_2 V_26 )
{
struct V_27 * V_28 = F_11 ( V_22 ) ;
struct V_5 V_12 ;
int V_15 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_11 . V_29 . V_30 = V_28 -> V_30 ;
V_12 . V_11 . V_29 . V_23 = V_23 ;
V_12 . V_11 . V_29 . V_31 = F_12 ( V_22 ) ;
memcpy ( V_12 . V_11 . V_29 . V_32 , V_22 -> V_33 , sizeof( V_12 . V_11 . V_29 . V_32 ) ) ;
memcpy ( V_12 . V_11 . V_29 . V_25 , V_25 , sizeof( V_12 . V_11 . V_29 . V_25 ) ) ;
V_12 . V_11 . V_29 . V_34 = V_22 -> V_26 ;
V_12 . V_11 . V_29 . V_26 = V_26 ;
F_13 ( L_1 , V_22 , V_28 -> V_30 ,
V_12 . V_11 . V_29 . V_31 , V_22 -> V_26 ,
( unsigned long long ) V_12 . V_11 . V_29 . V_26 ) ;
V_15 = F_3 ( V_35 , & V_12 ) ;
if ( V_15 )
F_14 ( L_2 ) ;
return V_15 ;
}
int F_15 ( struct V_21 * V_22 , T_2 V_23 , T_2 V_26 )
{
struct V_27 * V_28 = F_11 ( V_22 ) ;
struct V_5 V_12 ;
int V_15 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_11 . V_36 . V_30 = V_28 -> V_30 ;
V_12 . V_11 . V_36 . V_23 = V_23 ;
V_12 . V_11 . V_36 . V_26 = V_26 ;
V_12 . V_11 . V_36 . V_37 = V_22 -> V_37 ;
F_13 ( L_3 , V_22 , V_28 -> V_30 ,
( unsigned long long ) V_12 . V_11 . V_29 . V_26 ,
V_12 . V_11 . V_29 . V_31 , V_22 -> V_26 ) ;
V_15 = F_3 ( V_38 , & V_12 ) ;
if ( V_15 )
F_14 ( L_2 ) ;
return V_15 ;
}
int F_16 ( int V_30 , T_2 V_23 , int V_39 ,
T_2 V_26 , struct V_24 * V_40 , void * V_41 )
{
struct V_5 V_12 ;
int V_15 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_11 . V_42 . V_30 = V_30 ;
V_12 . V_11 . V_42 . V_23 = V_23 ;
V_12 . V_11 . V_42 . V_39 = V_39 ;
V_12 . V_11 . V_42 . V_26 = V_26 ;
memcpy ( V_12 . V_11 . V_42 . V_25 , V_40 , sizeof( V_12 . V_11 . V_42 . V_25 ) ) ;
V_12 . V_11 . V_42 . V_43 = ( T_2 ) ( unsigned long ) V_41 ;
F_13 ( L_4 , V_30 , V_39 , ( unsigned long long ) V_26 ,
( unsigned long long ) V_12 . V_11 . V_42 . V_43 ) ;
V_15 = F_3 ( V_44 , & V_12 ) ;
if ( V_15 )
F_14 ( L_2 ) ;
return V_15 ;
}
int F_17 ( int V_30 , T_2 V_23 ,
int V_39 , char * V_45 )
{
struct V_5 V_12 ;
int V_15 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_11 . V_46 . V_30 = V_30 ;
V_12 . V_11 . V_46 . V_39 = V_39 ;
V_12 . V_11 . V_46 . V_23 = V_23 ;
if ( V_45 )
strncpy ( V_12 . V_11 . V_46 . V_45 , V_45 ,
sizeof( V_12 . V_11 . V_46 . V_45 ) ) ;
F_13 ( L_5 , V_30 , V_39 , ( unsigned long long ) V_23 ) ;
V_15 = F_3 ( V_47 , & V_12 ) ;
if ( V_15 )
F_14 ( L_2 ) ;
return V_15 ;
}
static int F_18 ( struct V_5 * V_12 )
{
int V_15 = 0 ;
switch ( V_12 -> V_17 . type ) {
case V_48 :
V_15 = F_19 ( V_12 -> V_11 . V_49 . V_30 ,
V_12 -> V_11 . V_49 . V_23 ,
V_12 -> V_11 . V_49 . V_37 ,
V_12 -> V_11 . V_49 . V_26 ,
V_12 -> V_11 . V_49 . V_50 ,
V_12 -> V_11 . V_49 . V_51 ,
V_12 -> V_11 . V_49 . V_52 ,
V_12 -> V_11 . V_49 . V_53 ,
V_12 -> V_11 . V_49 . V_54 ) ;
break;
case V_55 :
V_15 = F_20 ( V_12 -> V_11 . V_56 . V_30 ,
V_12 -> V_11 . V_56 . V_23 ,
V_12 -> V_11 . V_56 . V_43 ,
V_12 -> V_11 . V_56 . V_37 ) ;
break;
case V_57 :
V_15 = F_21 ( V_12 -> V_11 . V_58 . V_30 ,
V_12 -> V_11 . V_58 . V_23 ,
V_12 -> V_11 . V_58 . V_37 ) ;
break;
default:
F_14 ( L_6 , V_12 -> V_17 . type ) ;
V_15 = - V_59 ;
}
return V_15 ;
}
static T_3 F_22 ( struct V_60 * V_60 , const char T_4 * V_61 ,
T_5 V_62 , T_6 * V_63 )
{
struct V_5 * V_12 ;
struct V_1 * V_2 = & V_64 ;
while ( 1 ) {
V_12 = F_2 ( V_2 , V_2 -> V_3 ) ;
F_7 ( F_8 ( V_12 ) ) ;
if ( ! V_12 -> V_17 . V_18 )
break;
F_1 ( V_2 ) ;
F_18 ( V_12 ) ;
V_12 -> V_17 . V_18 = 0 ;
} ;
return V_62 ;
}
static unsigned int F_23 ( struct V_60 * V_60 , struct V_65 * V_66 )
{
struct V_5 * V_12 ;
struct V_1 * V_2 = & V_13 ;
unsigned long V_14 ;
unsigned int V_67 = 0 ;
T_1 V_6 ;
F_24 ( V_60 , & V_20 , V_66 ) ;
F_4 ( & V_2 -> V_16 , V_14 ) ;
V_6 = V_2 -> V_3 ? V_2 -> V_3 - 1 : V_4 - 1 ;
V_12 = F_2 ( V_2 , V_6 ) ;
if ( V_12 -> V_17 . V_18 )
V_67 |= V_68 | V_69 ;
F_5 ( & V_2 -> V_16 , V_14 ) ;
return V_67 ;
}
static int F_25 ( struct V_70 * V_71 , unsigned long V_72 ,
struct V_1 * V_2 )
{
int V_73 , V_15 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
struct V_75 * V_75 = F_8 ( V_2 -> V_10 [ V_73 ] ) ;
V_15 = F_26 ( V_71 , V_72 , V_75 ) ;
if ( V_15 )
return V_15 ;
V_72 += V_76 ;
}
return 0 ;
}
static int F_27 ( struct V_60 * V_77 , struct V_70 * V_71 )
{
unsigned long V_72 ;
int V_15 ;
if ( V_71 -> V_78 )
return - V_59 ;
if ( V_71 -> V_79 - V_71 -> V_80 != V_81 * 2 ) {
F_14 ( L_7 ,
V_81 * 2 , V_71 -> V_79 - V_71 -> V_80 ) ;
return - V_59 ;
}
V_72 = V_71 -> V_80 ;
V_15 = F_25 ( V_71 , V_72 , & V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_25 ( V_71 , V_72 + V_81 , & V_64 ) ;
return V_15 ;
}
static int F_28 ( struct V_82 * V_82 , struct V_60 * V_60 )
{
V_13 . V_3 = V_64 . V_3 = 0 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_30 ( V_2 -> V_10 [ V_73 ] ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_73 ;
F_32 ( & V_2 -> V_16 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
V_2 -> V_10 [ V_73 ] = F_33 ( V_83 ) ;
if ( ! V_2 -> V_10 [ V_73 ] ) {
F_14 ( L_8 ) ;
return - V_84 ;
}
}
return 0 ;
}
void F_34 ( void )
{
F_29 ( & V_13 ) ;
F_29 ( & V_64 ) ;
F_35 ( & V_85 ) ;
}
int F_36 ( void )
{
int V_15 ;
V_15 = F_31 ( & V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_31 ( & V_64 ) ;
if ( V_15 )
goto V_86;
V_15 = F_37 ( & V_85 ) ;
if ( V_15 )
goto V_87;
return 0 ;
V_87:
F_29 ( & V_64 ) ;
V_86:
F_29 ( & V_13 ) ;
return V_15 ;
}
