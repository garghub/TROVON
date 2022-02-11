static T_1 * F_1 ( T_2 * V_1 )
{
T_3 * V_2 ;
const unsigned char * V_3 ;
V_2 = F_2 ( V_1 ,
V_4 ) ;
if ( ! V_2 ) return NULL ;
V_3 = V_2 -> V_5 . V_6 -> V_7 ;
return F_3 ( NULL , & V_3 , V_2 -> V_5 . V_6 -> V_8 ) ;
}
static int F_4 ( T_4 * V_9 , T_5 * V_10 )
{
T_6 * V_11 ;
if ( ! V_9 || ! V_10 || F_5 ( V_9 -> V_11 ) != 1 ) return - 1 ;
V_11 = F_6 ( V_9 -> V_11 , 0 ) ;
if ( V_11 -> type != V_12
|| F_7 ( V_11 -> V_13 . V_14 , V_10 -> V_11 ) )
return - 1 ;
if ( F_8 ( V_9 -> V_15 , V_10 -> V_16 ) )
return - 1 ;
return 0 ;
}
int F_9 ( T_7 * V_17 , T_8 * V_18 )
{
T_9 * V_19 = F_10 ( V_18 ) ;
T_10 * V_20 = F_11 ( V_18 ) ;
int V_21 = 0 ;
if ( ! F_12 ( V_18 ) ) goto V_22;
if ( ! F_13 ( V_17 , V_19 , V_20 ) )
goto V_22;
V_21 = 1 ;
V_22:
return V_21 ;
}
int F_14 ( T_7 * V_17 , T_9 * V_19 )
{
T_10 * V_20 = F_15 ( V_19 ) ;
int V_21 = 0 ;
if ( V_20 )
{
V_21 = F_13 ( V_17 , V_19 , V_20 ) ;
F_16 ( V_20 ) ;
}
return V_21 ;
}
static int F_13 ( T_7 * V_17 ,
T_9 * V_19 , T_10 * V_20 )
{
T_11 * V_23 = NULL ;
T_6 * V_24 = F_17 ( V_20 ) ;
T_12 * V_25 = NULL ;
unsigned char * V_26 = NULL ;
unsigned V_27 = 0 ;
int V_21 = 0 ;
if ( ( V_17 -> V_28 & V_29 )
&& ! F_18 ( V_19 , V_17 -> V_30 , V_17 -> V_31 ,
& V_23 ) )
goto V_22;
if ( ( V_17 -> V_28 & V_32 )
&& F_19 ( V_20 ) != 1 )
{
F_20 ( V_33 , V_34 ) ;
goto V_22;
}
if ( ( V_17 -> V_28 & V_35 )
&& ! F_21 ( V_17 -> V_36 , V_20 ) )
goto V_22;
if ( ( V_17 -> V_28 & V_37 )
&& ! F_22 ( V_17 -> V_25 , V_17 -> V_26 , V_17 -> V_27 ,
V_20 ) )
goto V_22;
if ( ( V_17 -> V_28 & V_38 )
&& ( ! F_23 ( V_17 -> V_7 , V_20 ,
& V_25 , & V_26 , & V_27 )
|| ! F_22 ( V_25 , V_26 , V_27 , V_20 ) ) )
goto V_22;
if ( ( V_17 -> V_28 & V_39 )
&& ! F_24 ( V_17 -> V_40 , V_20 ) )
goto V_22;
if ( ( V_17 -> V_28 & V_41 )
&& V_24 && ! F_25 ( V_24 , V_23 ) )
{
F_20 ( V_33 , V_42 ) ;
goto V_22;
}
if ( ( V_17 -> V_28 & V_43 )
&& ! F_25 ( V_17 -> V_24 , V_23 ) )
{
F_20 ( V_33 , V_44 ) ;
goto V_22;
}
V_21 = 1 ;
V_22:
F_26 ( V_23 ) ;
F_27 ( V_25 ) ;
F_28 ( V_26 ) ;
return V_21 ;
}
static int F_12 ( T_8 * V_18 )
{
T_13 * V_45 = F_29 ( V_18 ) ;
long V_46 = F_30 ( V_45 -> V_46 ) ;
const char * V_47 = NULL ;
char * V_48 = NULL ;
char V_49 [ V_50 ] = L_1 ;
if ( V_46 == 0 || V_46 == 1 ) return 1 ;
if ( 0 <= V_46 && V_46 < ( long ) V_51 )
V_47 = V_52 [ V_46 ] ;
else
V_47 = L_2 ;
if ( F_31 ( V_45 -> V_53 ) > 0
&& ! ( V_48 = F_32 ( V_45 -> V_53 ) ) )
return 0 ;
if ( V_45 -> V_54 )
{
int V_55 ;
int V_56 = 1 ;
for ( V_55 = 0 ; V_55 < ( int ) V_57 ; ++ V_55 )
{
if ( F_33 ( V_45 -> V_54 ,
V_58 [ V_55 ] . V_59 ) )
{
if ( ! V_56 )
strcpy ( V_49 , L_3 ) ;
else
V_56 = 0 ;
strcat ( V_49 , V_58 [ V_55 ] . V_53 ) ;
}
}
}
if ( V_49 [ 0 ] == '\0' )
strcpy ( V_49 , L_4 ) ;
F_20 ( V_60 , V_61 ) ;
F_34 ( 6 ,
L_5 , V_47 ,
L_6 , V_48 ?
V_48 : L_4 ,
L_7 , V_49 ) ;
F_28 ( V_48 ) ;
return 0 ;
}
static int F_21 ( T_14 * V_62 , T_10 * V_20 )
{
T_14 * V_63 = F_35 ( V_20 ) ;
if ( F_36 ( V_62 , V_63 ) != 0 )
{
F_20 ( V_64 , V_65 ) ;
return 0 ;
}
return 1 ;
}
static int F_23 ( T_15 * V_7 , T_10 * V_20 ,
T_12 * * V_25 ,
unsigned char * * V_26 , unsigned * V_27 )
{
T_16 * V_66 = F_37 ( V_20 ) ;
T_12 * V_67 = F_38 ( V_66 ) ;
const T_17 * V_68 ;
T_18 V_69 ;
unsigned char V_70 [ 4096 ] ;
int V_8 ;
* V_25 = NULL ;
* V_26 = NULL ;
if ( ! ( * V_25 = F_39 ( V_67 ) ) ) goto V_22;
if ( ! ( V_68 = F_40 ( ( * V_25 ) -> V_71 ) ) )
{
F_20 ( V_72 , V_73 ) ;
goto V_22;
}
V_8 = F_41 ( V_68 ) ;
if ( V_8 < 0 )
goto V_22;
* V_27 = V_8 ;
if ( ! ( * V_26 = F_42 ( * V_27 ) ) )
{
F_20 ( V_72 , V_74 ) ;
goto V_22;
}
if ( ! F_43 ( & V_69 , V_68 ) )
goto V_22;
while ( ( V_8 = F_44 ( V_7 , V_70 , sizeof( V_70 ) ) ) > 0 )
{
if ( ! F_45 ( & V_69 , V_70 , V_8 ) )
goto V_22;
}
if ( ! F_46 ( & V_69 , * V_26 , NULL ) )
goto V_22;
return 1 ;
V_22:
F_27 ( * V_25 ) ;
F_28 ( * V_26 ) ;
* V_27 = 0 ;
return 0 ;
}
static int F_22 ( T_12 * V_75 ,
unsigned char * V_76 , unsigned V_77 ,
T_10 * V_20 )
{
T_16 * V_78 = F_37 ( V_20 ) ;
T_12 * V_79 = F_38 ( V_78 ) ;
int V_21 = 0 ;
if ( V_75 )
{
if ( F_36 ( V_75 -> V_71 , V_79 -> V_71 ) ) goto V_22;
if ( ( V_75 -> V_80
&& F_47 ( V_75 -> V_80 ) != V_81 )
|| ( V_79 -> V_80
&& F_47 ( V_79 -> V_80 ) != V_81 ) )
goto V_22;
}
V_21 = V_77 == ( unsigned ) F_48 ( V_78 -> V_82 ) &&
memcmp ( V_76 , F_49 ( V_78 -> V_82 ) , V_77 ) == 0 ;
V_22:
if ( ! V_21 )
F_20 ( V_83 , V_84 ) ;
return V_21 ;
}
static int F_24 ( const T_19 * V_85 , T_10 * V_20 )
{
const T_19 * V_78 = F_50 ( V_20 ) ;
if ( ! V_78 )
{
F_20 ( V_86 , V_87 ) ;
return 0 ;
}
if ( F_8 ( V_85 , V_78 ) != 0 )
{
F_20 ( V_86 , V_88 ) ;
return 0 ;
}
return 1 ;
}
static int F_25 ( T_6 * V_24 , T_11 * V_23 )
{
F_51 ( T_6 ) * V_89 = NULL ;
int V_90 = - 1 ;
int V_91 = 0 ;
if ( V_24 -> type == V_12
&& F_52 ( V_24 -> V_13 . V_14 , V_23 -> V_92 -> V_93 ) == 0 )
return 1 ;
V_89 = F_53 ( V_23 , V_94 ,
NULL , & V_90 ) ;
while ( V_89 != NULL
&& ! ( V_91 = F_54 ( V_89 , V_24 ) >= 0 ) )
{
F_55 ( V_89 ) ;
V_89 = F_53 ( V_23 , V_94 ,
NULL , & V_90 ) ;
}
if ( V_89 ) F_55 ( V_89 ) ;
return V_91 ;
}
