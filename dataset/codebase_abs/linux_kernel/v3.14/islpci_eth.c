void
F_1 ( T_1 * V_1 ,
T_2 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_5 ;
while ( V_1 -> V_6 !=
F_2 ( V_2 ->
V_7 [ V_8 ] ) ) {
V_5 = V_1 -> V_6 % V_9 ;
if ( V_1 -> V_10 [ V_5 ] ) {
V_4 = V_1 -> V_11 [ V_5 ] ;
#if V_12 > V_13
F_3 ( V_14 ,
L_1 ,
V_4 , V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_17 ) ;
#endif
F_4 ( V_1 -> V_18 ,
V_1 -> V_10 [ V_5 ] ,
V_4 -> V_16 , V_19 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
V_1 -> V_6 ++ ;
}
}
T_4
F_6 ( struct V_3 * V_4 , struct V_20 * V_21 )
{
T_1 * V_1 = F_7 ( V_21 ) ;
T_2 * V_22 = V_1 -> V_2 ;
T_3 V_5 ;
T_5 V_23 ;
int V_24 ;
T_6 * V_25 ;
int V_26 ;
struct V_3 * V_27 ;
int V_28 ;
unsigned long V_29 ;
unsigned char V_30 [ 6 ] ;
T_3 V_31 ;
#if V_12 > V_13
F_3 ( V_32 , L_2 ) ;
#endif
F_8 ( & V_1 -> V_33 , V_29 ) ;
V_31 = F_2 ( V_22 -> V_34 [ V_8 ] ) ;
if ( F_9 ( V_31 - V_1 -> V_6 >= V_9 ) ) {
F_10 ( V_35 L_3 ,
V_21 -> V_36 ) ;
F_11 ( V_21 ) ;
F_12 ( V_1 -> V_37 , V_38 ,
V_39 ) ;
F_13 ( V_40 ) ;
goto V_41;
}
if ( F_14 ( ( ( long ) V_4 -> V_15 & 0x03 ) | V_42 ) ) {
V_26 = ( 4 - ( long ) V_4 -> V_15 ) & 0x03 ;
V_26 += V_42 ? 6 : 0 ;
if ( ! F_15 ( V_4 ) && ( F_16 ( V_4 ) >= V_26 ) ) {
unsigned char * V_43 = V_4 -> V_15 ;
#if V_12 > V_13
F_3 ( V_14 , L_4 , V_26 ,
V_42 ) ;
#endif
F_17 ( V_4 , ( 4 - ( long ) V_4 -> V_15 ) & 0x03 ) ;
if ( V_42 ) {
F_18 ( V_4 , 6 ) ;
#ifdef F_19
F_10 ( L_5 ) ;
#endif
memmove ( V_4 -> V_15 + 6 , V_43 , V_4 -> V_16 ) ;
F_20 ( V_4 , V_30 , 6 ) ;
} else {
memmove ( V_4 -> V_15 , V_43 , V_4 -> V_16 ) ;
}
#if V_12 > V_13
F_3 ( V_14 , L_6 , V_4 -> V_15 ,
V_43 , V_4 -> V_16 ) ;
#endif
} else {
V_27 =
F_21 ( V_42 ? V_4 -> V_16 + 6 : V_4 -> V_16 ) ;
if ( F_9 ( V_27 == NULL ) ) {
F_10 ( V_35 L_7 ,
V_21 -> V_36 ) ;
goto V_41;
}
V_28 = ( 4 - ( long ) V_27 -> V_15 ) & 0x03 ;
if ( V_28 )
F_17 ( V_27 , V_28 ) ;
F_18 ( V_27 , V_42 ? V_4 -> V_16 + 6 : V_4 -> V_16 ) ;
if ( V_42 ) {
F_22 ( V_4 ,
V_27 -> V_15 + 6 ,
V_4 -> V_16 ) ;
F_20 ( V_27 , V_30 , 6 ) ;
#ifdef F_19
F_10 ( L_5 ) ;
#endif
} else
F_22 ( V_4 , V_27 -> V_15 ,
V_4 -> V_16 ) ;
#if V_12 > V_13
F_3 ( V_14 , L_8 ,
V_27 -> V_15 , V_4 -> V_15 , V_4 -> V_16 , V_42 ) ;
#endif
V_27 -> V_44 = V_4 -> V_44 ;
F_5 ( V_4 ) ;
V_4 = V_27 ;
}
}
#if V_12 > V_13
F_3 ( V_45 , L_9 , V_4 -> V_15 ) ;
F_23 ( ( char * ) V_4 -> V_15 , V_4 -> V_16 ) ;
#endif
V_23 = F_24 ( V_1 -> V_18 ,
( void * ) V_4 -> V_15 , V_4 -> V_16 ,
V_19 ) ;
if ( F_9 ( V_23 == 0 ) ) {
F_10 ( V_46 L_10 ,
V_21 -> V_36 ) ;
goto V_41;
}
V_5 = V_31 % V_9 ;
V_25 = & V_22 -> V_47 [ V_5 ] ;
V_1 -> V_10 [ V_5 ] = V_23 ;
V_1 -> V_11 [ V_5 ] = V_4 ;
V_24 = V_4 -> V_16 ;
V_25 -> V_48 = F_25 ( V_24 ) ;
V_25 -> V_29 = F_25 ( 0 ) ;
V_25 -> V_49 = F_26 ( V_23 ) ;
V_31 ++ ;
F_27 () ;
V_22 -> V_34 [ V_8 ] = F_26 ( V_31 ) ;
if ( V_31 - V_1 -> V_6 + V_50
> V_9 ) {
F_11 ( V_21 ) ;
V_1 -> V_51 = 1 ;
}
V_21 -> V_52 . V_53 ++ ;
V_21 -> V_52 . V_54 += V_4 -> V_16 ;
F_28 ( V_1 ) ;
F_29 ( & V_1 -> V_33 , V_29 ) ;
return V_55 ;
V_41:
V_21 -> V_52 . V_56 ++ ;
F_29 ( & V_1 -> V_33 , V_29 ) ;
F_30 ( V_4 ) ;
return V_55 ;
}
static inline int
F_31 ( T_1 * V_1 , struct V_3 * * V_4 )
{
struct V_57 * V_58 = (struct V_57 * ) ( * V_4 ) -> V_15 ;
if ( V_58 -> V_29 & 0x01 )
return - 1 ;
if ( V_1 -> V_21 -> type == V_59 ) {
struct V_60 * V_61 ;
T_3 clock = F_2 ( V_58 -> clock ) ;
T_7 V_62 = V_58 -> V_62 ;
T_8 V_63 = F_32 ( V_58 -> V_63 ) ;
T_7 V_64 = V_58 -> V_64 ;
F_33 ( * V_4 , sizeof ( struct V_57 ) ) ;
if ( F_34 ( * V_4 ) < sizeof ( struct V_60 ) ) {
struct V_3 * V_27 = F_35 ( * V_4 ,
sizeof ( struct
V_60 ) ,
0 , V_65 ) ;
if ( V_27 ) {
F_5 ( * V_4 ) ;
* V_4 = V_27 ;
} else
return - 1 ;
}
V_61 =
(struct V_60 * ) F_36 ( * V_4 ,
sizeof ( struct
V_60 ) ) ;
V_61 -> V_66 = F_37 ( V_67 ) ;
V_61 -> V_68 = F_37 ( sizeof ( struct V_60 ) ) ;
V_61 -> V_69 = F_38 ( clock ) ;
V_61 -> V_70 = F_38 ( V_71 ) ;
V_61 -> V_72 = F_37 ( 6 ) ;
V_61 -> V_73 = F_37 ( F_39 ( V_63 ) ) ;
V_61 -> V_74 = F_37 ( V_62 * 5 ) ;
V_61 -> V_75 = F_37 ( 0 ) ;
V_61 -> V_76 = F_37 ( 0 ) ;
V_61 -> V_77 = F_37 ( 3 ) ;
V_61 -> V_78 = F_37 ( V_64 & 0x7f ) ;
V_61 -> V_79 = F_37 ( V_1 -> V_80 . V_81 . V_82 ) ;
V_61 -> V_83 = F_37 ( 0 ) ;
V_61 -> V_84 = F_37 ( 0 ) ;
} else
F_33 ( * V_4 , sizeof ( struct V_57 ) ) ;
( * V_4 ) -> V_85 = F_40 ( V_86 ) ;
F_41 ( * V_4 ) ;
( * V_4 ) -> V_87 = V_88 ;
return 0 ;
}
int
F_42 ( T_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_21 ;
T_2 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 ;
T_8 V_48 ;
T_3 V_5 , V_26 ;
unsigned char * V_43 ;
int V_89 = 0 ;
#if V_12 > V_13
F_3 ( V_32 , L_11 ) ;
#endif
V_5 = V_1 -> V_90 % V_91 ;
V_48 = F_32 ( V_2 -> V_92 [ V_5 ] . V_48 ) ;
V_4 = V_1 -> V_93 [ V_5 ] ;
V_26 = ( ( unsigned long )
F_2 ( V_2 -> V_92 [ V_5 ] . V_49 ) -
( unsigned long ) V_4 -> V_15 ) & 3 ;
#if V_12 > V_13
F_3 ( V_14 ,
L_12 ,
V_2 -> V_92 [ V_1 -> V_90 ] . V_49 , V_4 -> V_15 ,
V_4 -> V_16 , V_26 , V_4 -> V_17 ) ;
#endif
F_4 ( V_1 -> V_18 ,
V_1 -> V_94 [ V_5 ] ,
V_95 + 2 , V_96 ) ;
F_18 ( V_4 , V_48 ) ;
if ( V_26 ) {
F_33 ( V_4 , 2 ) ;
F_18 ( V_4 , 2 ) ;
}
#if V_12 > V_13
F_3 ( V_45 , L_13 , V_4 -> V_15 ) ;
F_23 ( ( char * ) V_4 -> V_15 , V_4 -> V_16 ) ;
#endif
if ( V_42 ) {
V_43 = V_4 -> V_15 + 6 ;
memmove ( V_4 -> V_15 , V_43 , V_4 -> V_16 - 6 ) ;
F_43 ( V_4 , V_4 -> V_16 - 6 ) ;
}
#if V_12 > V_13
F_3 ( V_14 , L_14 , V_48 , V_4 ) ;
F_3 ( V_14 , L_15 , V_4 -> V_15 , V_4 -> V_16 ) ;
F_3 ( V_45 , L_13 , V_4 -> V_15 ) ;
F_23 ( ( char * ) V_4 -> V_15 , V_4 -> V_16 ) ;
#endif
if ( F_9 ( V_1 -> V_97 == V_98 ) ) {
V_4 -> V_44 = V_21 ;
V_89 = F_31 ( V_1 , & V_4 ) ;
} else {
if ( F_9 ( V_4 -> V_15 [ 2 * V_99 ] == 0 ) ) {
struct V_100 V_101 ;
struct V_102 * V_103 =
(struct V_102 * ) V_4 -> V_15 ;
V_101 . V_104 = V_103 -> V_105 . V_64 ;
V_101 . V_82 = V_1 -> V_80 . V_81 . V_82 ;
V_101 . V_81 = V_101 . V_104 - V_101 . V_82 ;
V_101 . V_106 = 0x07 ;
F_44 ( V_21 , V_103 -> V_107 , & V_101 ) ;
F_22 ( V_4 ,
( V_4 -> V_15 +
sizeof( struct V_57 ) ) ,
2 * V_99 ) ;
F_33 ( V_4 , sizeof ( struct V_57 ) ) ;
}
V_4 -> V_85 = F_45 ( V_4 , V_21 ) ;
}
V_4 -> V_108 = V_109 ;
V_21 -> V_52 . V_110 ++ ;
V_21 -> V_52 . V_111 += V_48 ;
#ifdef F_19
F_10
( L_16 ,
V_4 -> V_15 [ 0 ] , V_4 -> V_15 [ 1 ] , V_4 -> V_15 [ 2 ] , V_4 -> V_15 [ 3 ] ,
V_4 -> V_15 [ 4 ] , V_4 -> V_15 [ 5 ] ) ;
#endif
if ( F_9 ( V_89 ) ) {
F_5 ( V_4 ) ;
V_4 = NULL ;
} else
F_46 ( V_4 ) ;
V_1 -> V_90 ++ ;
while ( V_5 =
F_2 ( V_2 ->
V_34 [ V_112 ] ) ,
V_5 - V_1 -> V_90 < V_91 ) {
V_4 = F_21 ( V_95 + 2 ) ;
if ( F_9 ( V_4 == NULL ) ) {
F_3 ( V_13 , L_17 ) ;
break;
}
F_17 ( V_4 , ( 4 - ( long ) V_4 -> V_15 ) & 0x03 ) ;
V_5 = V_5 % V_91 ;
V_1 -> V_93 [ V_5 ] = V_4 ;
#if V_12 > V_13
F_3 ( V_14 ,
L_18 ,
V_4 , V_4 -> V_15 , V_4 -> V_16 , V_5 , V_4 -> V_17 ) ;
#endif
V_1 -> V_94 [ V_5 ] =
F_24 ( V_1 -> V_18 , ( void * ) V_4 -> V_15 ,
V_95 + 2 ,
V_96 ) ;
if ( F_9 ( ! V_1 -> V_94 [ V_5 ] ) ) {
F_3 ( V_13 ,
L_19 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
break;
}
V_2 -> V_92 [ V_5 ] . V_49 =
F_26 ( ( T_3 ) V_1 -> V_94 [ V_5 ] ) ;
F_27 () ;
F_47 ( & V_2 ->
V_34 [ V_112 ] , 1 ) ;
}
F_28 ( V_1 ) ;
return 0 ;
}
void
F_48 ( struct V_113 * V_114 )
{
T_1 * V_1 = F_49 ( V_114 , T_1 , V_115 ) ;
F_50 ( V_1 , 1 ) ;
V_1 -> V_116 = 0 ;
F_51 () ;
F_52 ( V_1 -> V_21 ) ;
}
void
F_53 ( struct V_20 * V_21 )
{
T_1 * V_1 = F_7 ( V_21 ) ;
V_21 -> V_52 . V_117 ++ ;
if ( ! V_1 -> V_116 ) {
F_10 ( V_46
L_20 , V_21 -> V_36 ) ;
F_11 ( V_21 ) ;
V_1 -> V_116 = 1 ;
F_54 ( & V_1 -> V_115 ) ;
} else {
F_10 ( V_46
L_21 , V_21 -> V_36 ) ;
}
}
