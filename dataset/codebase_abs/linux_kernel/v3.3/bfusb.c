static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 = NULL ;
F_2 ( L_1 , V_3 ) ;
V_5 = F_3 ( & V_3 -> V_6 ) ;
if ( V_5 ) {
V_1 = ( (struct V_7 * ) V_5 -> V_8 ) -> V_1 ;
F_4 ( V_5 ) ;
}
return V_1 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
F_2 ( L_1 , V_3 ) ;
while ( ( V_5 = F_3 ( & V_3 -> V_9 ) ) ) {
V_1 = ( (struct V_7 * ) V_5 -> V_8 ) -> V_1 ;
F_6 ( V_1 ) ;
F_7 ( & V_3 -> V_6 , V_5 ) ;
}
while ( ( V_1 = F_1 ( V_3 ) ) )
F_8 ( V_1 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_7 * V_10 = ( void * ) V_5 -> V_8 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 , V_12 ;
F_2 ( L_2 , V_3 , V_5 , V_5 -> V_13 ) ;
if ( ! V_1 && ! ( V_1 = F_10 ( 0 , V_14 ) ) )
return - V_15 ;
V_12 = F_11 ( V_3 -> V_16 , V_3 -> V_17 ) ;
F_12 ( V_1 , V_3 -> V_16 , V_12 , V_5 -> V_3 , V_5 -> V_13 ,
V_18 , V_5 ) ;
V_10 -> V_1 = V_1 ;
F_7 ( & V_3 -> V_9 , V_5 ) ;
V_11 = F_13 ( V_1 , V_14 ) ;
if ( V_11 ) {
F_14 ( L_3 ,
V_3 -> V_19 -> V_20 , V_1 , V_11 ) ;
F_15 ( V_5 , & V_3 -> V_9 ) ;
F_8 ( V_1 ) ;
} else
F_16 ( & V_3 -> V_21 ) ;
return V_11 ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 ( L_1 , V_3 ) ;
if ( F_18 ( V_22 , & V_3 -> V_23 ) ) {
F_19 ( V_24 , & V_3 -> V_23 ) ;
return;
}
do {
F_20 ( V_24 , & V_3 -> V_23 ) ;
while ( ( F_21 ( & V_3 -> V_21 ) < V_25 ) &&
( V_5 = F_3 ( & V_3 -> V_26 ) ) ) {
if ( F_9 ( V_3 , V_5 ) < 0 ) {
F_22 ( & V_3 -> V_26 , V_5 ) ;
break;
}
}
} while ( F_23 ( V_24 , & V_3 -> V_23 ) );
F_20 ( V_22 , & V_3 -> V_23 ) ;
}
static void V_18 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_27 ;
struct V_2 * V_3 = (struct V_2 * ) V_5 -> V_28 ;
F_2 ( L_4 , V_3 , V_1 , V_5 , V_5 -> V_13 ) ;
F_24 ( & V_3 -> V_21 ) ;
if ( ! F_23 ( V_29 , & V_3 -> V_19 -> V_30 ) )
return;
if ( ! V_1 -> V_31 )
V_3 -> V_19 -> V_32 . V_33 += V_5 -> V_13 ;
else
V_3 -> V_19 -> V_32 . V_34 ++ ;
F_25 ( & V_3 -> V_35 ) ;
F_15 ( V_5 , & V_3 -> V_9 ) ;
F_7 ( & V_3 -> V_6 , V_5 ) ;
F_17 ( V_3 ) ;
F_26 ( & V_3 -> V_35 ) ;
}
static int F_27 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_7 * V_10 ;
struct V_4 * V_5 ;
int V_11 , V_12 , V_36 = V_37 + 32 ;
F_2 ( L_5 , V_3 , V_1 ) ;
if ( ! V_1 && ! ( V_1 = F_10 ( 0 , V_14 ) ) )
return - V_15 ;
V_5 = F_28 ( V_36 , V_14 ) ;
if ( ! V_5 ) {
F_8 ( V_1 ) ;
return - V_15 ;
}
V_5 -> V_28 = ( void * ) V_3 ;
V_10 = (struct V_7 * ) V_5 -> V_8 ;
V_10 -> V_1 = V_1 ;
V_12 = F_29 ( V_3 -> V_16 , V_3 -> V_38 ) ;
F_12 ( V_1 , V_3 -> V_16 , V_12 , V_5 -> V_3 , V_36 ,
V_39 , V_5 ) ;
F_7 ( & V_3 -> V_9 , V_5 ) ;
V_11 = F_13 ( V_1 , V_14 ) ;
if ( V_11 ) {
F_14 ( L_6 ,
V_3 -> V_19 -> V_20 , V_1 , V_11 ) ;
F_15 ( V_5 , & V_3 -> V_9 ) ;
F_4 ( V_5 ) ;
F_8 ( V_1 ) ;
}
return V_11 ;
}
static inline int F_30 ( struct V_2 * V_3 , int V_40 , unsigned char * V_41 , int V_13 )
{
F_2 ( L_7 , V_3 , V_40 , V_41 , V_13 ) ;
if ( V_40 & 0x10 ) {
F_14 ( L_8 , V_3 -> V_19 -> V_20 ) ;
F_4 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
return - V_43 ;
}
if ( V_40 & 0x04 ) {
struct V_4 * V_5 ;
unsigned char V_44 ;
int V_45 = 0 ;
if ( V_3 -> V_42 ) {
F_14 ( L_9 , V_3 -> V_19 -> V_20 ) ;
F_4 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
}
if ( V_13 < 1 ) {
F_14 ( L_10 , V_3 -> V_19 -> V_20 ) ;
return - V_46 ;
}
V_44 = * V_41 ++ ; V_13 -- ;
switch ( V_44 ) {
case V_47 :
if ( V_13 >= V_48 ) {
struct V_49 * V_40 = (struct V_49 * ) V_41 ;
V_45 = V_48 + V_40 -> V_50 ;
} else {
F_14 ( L_11 , V_3 -> V_19 -> V_20 ) ;
return - V_51 ;
}
break;
case V_52 :
if ( V_13 >= V_53 ) {
struct V_54 * V_40 = (struct V_54 * ) V_41 ;
V_45 = V_53 + F_31 ( V_40 -> V_55 ) ;
} else {
F_14 ( L_12 , V_3 -> V_19 -> V_20 ) ;
return - V_51 ;
}
break;
case V_56 :
if ( V_13 >= V_57 ) {
struct V_58 * V_40 = (struct V_58 * ) V_41 ;
V_45 = V_57 + V_40 -> V_55 ;
} else {
F_14 ( L_13 , V_3 -> V_19 -> V_20 ) ;
return - V_51 ;
}
break;
}
V_5 = F_28 ( V_45 , V_14 ) ;
if ( ! V_5 ) {
F_14 ( L_14 , V_3 -> V_19 -> V_20 ) ;
return - V_15 ;
}
V_5 -> V_28 = ( void * ) V_3 -> V_19 ;
F_32 ( V_5 ) -> V_44 = V_44 ;
V_3 -> V_42 = V_5 ;
} else {
if ( ! V_3 -> V_42 ) {
F_14 ( L_15 , V_3 -> V_19 -> V_20 ) ;
return - V_43 ;
}
}
if ( V_13 > 0 )
memcpy ( F_33 ( V_3 -> V_42 , V_13 ) , V_41 , V_13 ) ;
if ( V_40 & 0x08 ) {
F_34 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
}
return 0 ;
}
static void V_39 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 -> V_27 ;
struct V_2 * V_3 = (struct V_2 * ) V_5 -> V_28 ;
unsigned char * V_41 = V_1 -> V_59 ;
int V_60 = V_1 -> V_61 ;
int V_11 , V_40 , V_13 ;
F_2 ( L_4 , V_3 , V_1 , V_5 , V_5 -> V_13 ) ;
F_25 ( & V_3 -> V_35 ) ;
if ( ! F_23 ( V_29 , & V_3 -> V_19 -> V_30 ) )
goto V_62;
if ( V_1 -> V_31 || ! V_60 )
goto V_63;
V_3 -> V_19 -> V_32 . V_64 += V_60 ;
F_33 ( V_5 , V_60 ) ;
while ( V_60 ) {
V_40 = V_41 [ 0 ] | ( V_41 [ 1 ] << 8 ) ;
if ( V_40 & 0x4000 ) {
V_13 = 0 ;
V_60 -= 2 ;
V_41 += 2 ;
} else {
V_13 = ( V_41 [ 2 ] == 0 ) ? 256 : V_41 [ 2 ] ;
V_60 -= 3 ;
V_41 += 3 ;
}
if ( V_60 < V_13 ) {
F_14 ( L_16 ,
V_3 -> V_19 -> V_20 ) ;
}
if ( ( V_40 & 0xe1 ) == 0xc1 )
F_30 ( V_3 , V_40 , V_41 , V_13 ) ;
V_60 -= V_13 ;
V_41 += V_13 ;
}
F_15 ( V_5 , & V_3 -> V_9 ) ;
F_4 ( V_5 ) ;
F_27 ( V_3 , V_1 ) ;
F_26 ( & V_3 -> V_35 ) ;
return;
V_63:
V_1 -> V_28 = V_3 -> V_16 ;
V_11 = F_13 ( V_1 , V_14 ) ;
if ( V_11 ) {
F_14 ( L_17 ,
V_3 -> V_19 -> V_20 , V_1 , V_11 ) ;
}
V_62:
F_26 ( & V_3 -> V_35 ) ;
}
static int F_35 ( struct V_65 * V_19 )
{
struct V_2 * V_3 = V_19 -> V_66 ;
unsigned long V_30 ;
int V_67 , V_11 ;
F_2 ( L_18 , V_19 , V_3 ) ;
if ( F_18 ( V_29 , & V_19 -> V_30 ) )
return 0 ;
F_36 ( & V_3 -> V_35 , V_30 ) ;
V_11 = F_27 ( V_3 , NULL ) ;
if ( ! V_11 ) {
for ( V_67 = 1 ; V_67 < V_68 ; V_67 ++ )
F_27 ( V_3 , NULL ) ;
} else {
F_20 ( V_29 , & V_19 -> V_30 ) ;
}
F_37 ( & V_3 -> V_35 , V_30 ) ;
return V_11 ;
}
static int F_38 ( struct V_65 * V_19 )
{
struct V_2 * V_3 = V_19 -> V_66 ;
F_2 ( L_18 , V_19 , V_3 ) ;
F_39 ( & V_3 -> V_26 ) ;
return 0 ;
}
static int F_40 ( struct V_65 * V_19 )
{
struct V_2 * V_3 = V_19 -> V_66 ;
unsigned long V_30 ;
F_2 ( L_18 , V_19 , V_3 ) ;
if ( ! F_41 ( V_29 , & V_19 -> V_30 ) )
return 0 ;
F_36 ( & V_3 -> V_35 , V_30 ) ;
F_37 ( & V_3 -> V_35 , V_30 ) ;
F_5 ( V_3 ) ;
F_38 ( V_19 ) ;
return 0 ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_65 * V_19 = (struct V_65 * ) V_5 -> V_28 ;
struct V_2 * V_3 ;
struct V_4 * V_69 ;
unsigned char V_41 [ 3 ] ;
int V_70 = 0 , V_36 , V_60 ;
F_2 ( L_19 , V_19 , V_5 , F_32 ( V_5 ) -> V_44 , V_5 -> V_13 ) ;
if ( ! V_19 ) {
F_14 ( L_20 ) ;
return - V_71 ;
}
if ( ! F_23 ( V_29 , & V_19 -> V_30 ) )
return - V_72 ;
V_3 = V_19 -> V_66 ;
switch ( F_32 ( V_5 ) -> V_44 ) {
case V_73 :
V_19 -> V_32 . V_74 ++ ;
break;
case V_52 :
V_19 -> V_32 . V_75 ++ ;
break;
case V_56 :
V_19 -> V_32 . V_76 ++ ;
break;
} ;
memcpy ( F_43 ( V_5 , 1 ) , & F_32 ( V_5 ) -> V_44 , 1 ) ;
V_60 = V_5 -> V_13 ;
V_69 = F_28 ( V_60 + 32 , V_14 ) ;
if ( ! V_69 ) {
F_14 ( L_21 ) ;
return - V_15 ;
}
V_69 -> V_28 = ( void * ) V_3 ;
while ( V_60 ) {
V_36 = F_44 ( V_77 , V_60 , V_78 ) ;
V_41 [ 0 ] = 0xc1 | ( ( V_70 == 0 ) ? 0x04 : 0 ) | ( ( V_60 == V_36 ) ? 0x08 : 0 ) ;
V_41 [ 1 ] = 0x00 ;
V_41 [ 2 ] = ( V_36 == V_78 ) ? 0 : V_36 ;
memcpy ( F_33 ( V_69 , 3 ) , V_41 , 3 ) ;
F_45 ( V_5 , V_70 , F_33 ( V_69 , V_36 ) , V_36 ) ;
V_70 += V_36 ;
V_60 -= V_36 ;
}
if ( ( V_69 -> V_13 % V_3 -> V_79 ) == 0 ) {
V_41 [ 0 ] = 0xdd ;
V_41 [ 1 ] = 0x00 ;
memcpy ( F_33 ( V_69 , 2 ) , V_41 , 2 ) ;
}
F_25 ( & V_3 -> V_35 ) ;
F_7 ( & V_3 -> V_26 , V_69 ) ;
F_17 ( V_3 ) ;
F_26 ( & V_3 -> V_35 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
static void F_46 ( struct V_65 * V_19 )
{
struct V_2 * V_3 = V_19 -> V_66 ;
F_2 ( L_18 , V_19 , V_3 ) ;
F_47 ( V_3 ) ;
}
static int F_48 ( struct V_65 * V_19 , unsigned int V_80 , unsigned long V_81 )
{
return - V_82 ;
}
static int F_49 ( struct V_2 * V_3 ,
const unsigned char * V_83 , int V_60 )
{
unsigned char * V_41 ;
int V_11 , V_12 , V_13 , V_36 , V_70 = 0 ;
F_2 ( L_22 , V_3 , V_3 -> V_16 ) ;
F_50 ( L_23 ) ;
V_41 = F_51 ( V_78 + 3 , V_84 ) ;
if ( ! V_41 ) {
F_14 ( L_24 ) ;
return - V_15 ;
}
V_12 = F_52 ( V_3 -> V_16 , 0 ) ;
if ( F_53 ( V_3 -> V_16 , V_12 , V_85 ,
0 , 1 , 0 , NULL , 0 , V_86 ) < 0 ) {
F_14 ( L_25 ) ;
F_47 ( V_41 ) ;
return - V_72 ;
}
V_3 -> V_16 -> V_87 [ 0 ] = V_3 -> V_16 -> V_87 [ 1 ] = 0 ;
V_12 = F_11 ( V_3 -> V_16 , V_3 -> V_17 ) ;
while ( V_60 ) {
V_36 = F_44 ( V_77 , V_60 , V_78 + 3 ) ;
memcpy ( V_41 , V_83 + V_70 , V_36 ) ;
V_11 = F_54 ( V_3 -> V_16 , V_12 , V_41 , V_36 ,
& V_13 , V_88 ) ;
if ( V_11 || ( V_13 != V_36 ) ) {
F_14 ( L_26 ) ;
goto error;
}
V_70 += V_36 ;
V_60 -= V_36 ;
}
V_11 = F_54 ( V_3 -> V_16 , V_12 , NULL , 0 ,
& V_13 , V_88 ) ;
if ( V_11 < 0 ) {
F_14 ( L_27 ) ;
goto error;
}
V_12 = F_52 ( V_3 -> V_16 , 0 ) ;
V_11 = F_53 ( V_3 -> V_16 , V_12 , V_85 ,
0 , 2 , 0 , NULL , 0 , V_86 ) ;
if ( V_11 < 0 ) {
F_14 ( L_28 ) ;
goto error;
}
V_3 -> V_16 -> V_87 [ 0 ] = V_3 -> V_16 -> V_87 [ 1 ] = 0 ;
F_50 ( L_29 ) ;
F_47 ( V_41 ) ;
return 0 ;
error:
F_47 ( V_41 ) ;
V_12 = F_52 ( V_3 -> V_16 , 0 ) ;
F_53 ( V_3 -> V_16 , V_12 , V_85 ,
0 , 0 , 0 , NULL , 0 , V_86 ) ;
return V_11 ;
}
static int F_55 ( struct V_89 * V_90 , const struct V_91 * V_92 )
{
const struct V_83 * V_83 ;
struct V_93 * V_16 = F_56 ( V_90 ) ;
struct V_94 * V_17 ;
struct V_94 * V_38 ;
struct V_65 * V_19 ;
struct V_2 * V_3 ;
F_2 ( L_30 , V_90 , V_92 ) ;
if ( V_90 -> V_95 -> V_96 . V_97 < 2 )
return - V_43 ;
V_17 = & V_90 -> V_95 -> V_98 [ 0 ] ;
V_38 = & V_90 -> V_95 -> V_98 [ 1 ] ;
if ( ! V_17 || ! V_38 ) {
F_14 ( L_31 ) ;
goto V_99;
}
V_3 = F_57 ( sizeof( struct V_2 ) , V_84 ) ;
if ( ! V_3 ) {
F_14 ( L_32 ) ;
goto V_99;
}
V_3 -> V_16 = V_16 ;
V_3 -> V_38 = V_38 -> V_96 . V_100 ;
V_3 -> V_17 = V_17 -> V_96 . V_100 ;
V_3 -> V_79 = F_58 ( V_17 -> V_96 . V_101 ) ;
F_59 ( & V_3 -> V_35 ) ;
V_3 -> V_42 = NULL ;
F_60 ( & V_3 -> V_26 ) ;
F_60 ( & V_3 -> V_9 ) ;
F_60 ( & V_3 -> V_6 ) ;
if ( F_61 ( & V_83 , L_33 , & V_16 -> V_28 ) < 0 ) {
F_14 ( L_34 ) ;
goto error;
}
F_2 ( L_35 , V_83 -> V_3 , V_83 -> V_36 ) ;
if ( F_49 ( V_3 , V_83 -> V_3 , V_83 -> V_36 ) < 0 ) {
F_14 ( L_36 ) ;
goto V_102;
}
F_62 ( V_83 ) ;
V_19 = F_63 () ;
if ( ! V_19 ) {
F_14 ( L_37 ) ;
goto error;
}
V_3 -> V_19 = V_19 ;
V_19 -> V_103 = V_104 ;
V_19 -> V_66 = V_3 ;
F_64 ( V_19 , & V_90 -> V_28 ) ;
V_19 -> V_105 = F_35 ;
V_19 -> V_106 = F_40 ;
V_19 -> V_107 = F_38 ;
V_19 -> V_108 = F_42 ;
V_19 -> V_109 = F_46 ;
V_19 -> V_110 = F_48 ;
V_19 -> V_111 = V_112 ;
if ( F_65 ( V_19 ) < 0 ) {
F_14 ( L_38 ) ;
F_66 ( V_19 ) ;
goto error;
}
F_67 ( V_90 , V_3 ) ;
return 0 ;
V_102:
F_62 ( V_83 ) ;
error:
F_47 ( V_3 ) ;
V_99:
return - V_43 ;
}
static void F_68 ( struct V_89 * V_90 )
{
struct V_2 * V_3 = F_69 ( V_90 ) ;
struct V_65 * V_19 = V_3 -> V_19 ;
F_2 ( L_39 , V_90 ) ;
if ( ! V_19 )
return;
F_67 ( V_90 , NULL ) ;
F_40 ( V_19 ) ;
F_70 ( V_19 ) ;
F_66 ( V_19 ) ;
}
