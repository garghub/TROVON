static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
char * V_5 = L_1 ;
switch ( V_4 ) {
case - V_6 :
V_5 = L_2 ;
break;
case - V_7 :
V_5 = L_3 ;
break;
case - V_8 :
V_5 = L_4 ;
break;
case - V_9 :
V_5 = L_5 ;
break;
case - V_10 :
V_5 = L_6 ;
break;
case - V_11 :
V_5 = L_7 ;
break;
case - V_12 :
V_5 = L_8 ;
break;
case - V_13 :
V_5 = L_9 ;
break;
}
if ( V_3 < 0 )
F_2 ( V_14 L_10 ,
V_4 , V_5 ) ;
else
F_2 ( V_15 L_11 ,
V_3 , V_4 , V_5 ) ;
}
static inline
struct V_16 * F_3 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = NULL ;
unsigned long V_18 = 0 ;
F_4 ( V_2 -> V_19 . V_17 ) ;
F_5 ( & V_2 -> V_20 , V_18 ) ;
if ( ! F_6 ( & V_2 -> V_21 ) ) {
V_17 = F_7 ( & V_2 -> V_21 ,
struct V_16 , V_22 ) ;
F_8 ( & V_17 -> V_22 ) ;
}
F_9 ( & V_2 -> V_20 , V_18 ) ;
return V_17 ;
}
static inline
void F_10 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_19 . V_17 ;
V_17 -> V_23 . V_24 = V_2 -> V_24 ++ ;
V_17 -> V_23 . V_25 = V_26 ;
V_17 -> V_23 . V_27 . V_28 = F_11 () ;
F_12 ( & V_17 -> V_23 . V_27 , 0 , V_17 -> V_29 ) ;
F_13 ( & V_17 -> V_23 . V_27 , V_30 ) ;
V_2 -> V_19 . V_17 = NULL ;
}
static inline
void F_14 ( struct V_1 * V_2 , T_1 * V_31 , int V_32 )
{
int V_33 , V_34 , V_35 ;
int V_36 = V_2 -> V_37 * 2 ;
struct V_16 * V_17 = V_2 -> V_19 . V_17 ;
T_1 * V_38 = V_17 -> V_39 ;
int V_40 ;
V_32 -= 4 ;
V_31 += 4 ;
V_40 = V_32 ;
V_33 = V_17 -> V_41 / V_36 ;
V_34 = V_17 -> V_41 % V_36 ;
if ( ! V_17 -> V_42 )
V_38 += V_36 ;
V_38 += V_33 * V_36 * 2 + V_34 ;
if ( V_40 < ( V_36 - V_34 ) )
V_35 = V_40 ;
else
V_35 = V_36 - V_34 ;
if ( V_35 > V_17 -> V_29 - V_17 -> V_43 ) {
V_35 = V_17 -> V_29 - V_17 -> V_43 ;
V_40 = V_35 ;
}
if ( V_35 == 0 || V_40 == 0 )
return;
if ( V_35 < 0 ) {
F_15 ( L_12 ) ;
return;
}
if ( ( unsigned long ) V_38 + V_35 >
( unsigned long ) V_17 -> V_39 + V_17 -> V_43 ) {
F_2 ( V_14 L_13 ) ;
return;
}
memcpy ( V_38 , V_31 , V_35 ) ;
V_17 -> V_29 += V_35 ;
V_17 -> V_41 += V_35 ;
V_40 -= V_35 ;
while ( V_40 > 0 ) {
V_38 += V_35 + V_36 ;
V_31 += V_35 ;
if ( V_40 < V_36 )
V_35 = V_40 ;
else
V_35 = V_36 ;
if ( V_35 > V_17 -> V_29 - V_17 -> V_43 ) {
V_35 = V_17 -> V_29 - V_17 -> V_43 ;
V_40 = V_35 ;
}
if ( V_35 == 0 || V_40 == 0 )
return;
if ( V_35 < 0 ) {
F_2 ( V_14 L_14 ) ;
return;
}
if ( ( unsigned long ) V_38 + V_35 >
( unsigned long ) V_17 -> V_39 + V_17 -> V_43 ) {
F_2 ( V_14 L_13 ) ;
return;
}
memcpy ( V_38 , V_31 , V_35 ) ;
V_40 -= V_35 ;
V_17 -> V_29 += V_35 ;
V_17 -> V_41 += V_35 ;
}
}
static void F_16 ( struct V_1 * V_2 , struct V_44 * V_44 )
{
int V_45 , V_32 , V_4 ;
T_1 * V_46 ;
if ( ! V_2 ) {
F_17 ( L_15 , V_47 ) ;
return;
}
if ( V_44 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_44 -> V_4 ) ;
return;
}
for ( V_45 = 0 ; V_45 < V_44 -> V_48 ; V_45 ++ ) {
V_4 = V_44 -> V_49 [ V_45 ] . V_4 ;
if ( V_4 < 0 ) {
F_1 ( V_2 , V_45 , V_4 ) ;
continue;
}
V_46 = V_44 -> V_50 + V_44 -> V_49 [ V_45 ] . V_51 ;
V_32 = V_44 -> V_49 [ V_45 ] . V_52 ;
if ( V_32 <= 4 )
continue;
if ( V_46 [ 0 ] == 0xc0 ) {
if ( V_2 -> V_19 . V_17 != NULL )
F_10 ( V_2 ) ;
V_2 -> V_19 . V_17 = F_3 ( V_2 ) ;
if ( V_2 -> V_19 . V_17 == NULL )
return;
}
if ( V_2 -> V_19 . V_17 == NULL )
continue;
if ( V_46 [ 0 ] == 0xc0 || V_46 [ 0 ] == 0x80 ) {
V_2 -> V_19 . V_17 -> V_42 = * V_46 & 0x40 ;
V_2 -> V_19 . V_17 -> V_41 = 0 ;
continue;
}
F_14 ( V_2 , V_46 , V_32 ) ;
}
}
static void F_18 ( struct V_44 * V_44 )
{
int V_45 , V_53 ;
struct V_1 * V_2 = V_44 -> V_54 ;
switch ( V_44 -> V_4 ) {
case 0 :
break;
case - V_7 :
case - V_6 :
case - V_55 :
return;
default:
F_19 ( L_16 , V_44 -> V_4 ) ;
return;
}
F_16 ( V_2 , V_44 ) ;
for ( V_45 = 0 ; V_45 < V_44 -> V_48 ; V_45 ++ ) {
V_44 -> V_49 [ V_45 ] . V_4 = 0 ;
V_44 -> V_49 [ V_45 ] . V_52 = 0 ;
}
V_53 = F_20 ( V_44 , V_56 ) ;
if ( V_53 )
F_19 ( L_17 , V_53 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
int V_45 , V_57 = V_2 -> V_19 . V_57 ;
if ( ! V_57 )
return;
F_15 ( L_18 , V_57 ) ;
for ( V_45 = 0 ; V_45 < V_57 ; V_45 ++ ) {
F_22 ( V_2 -> V_19 . V_44 [ V_45 ] ) ;
}
F_15 ( L_19 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_44 * V_44 ;
int V_45 , V_57 = V_2 -> V_19 . V_57 ;
F_15 ( L_20 , V_57 ) ;
for ( V_45 = 0 ; V_45 < V_57 ; V_45 ++ ) {
V_44 = V_2 -> V_19 . V_44 [ V_45 ] ;
if ( V_44 ) {
if ( V_2 -> V_19 . V_50 [ V_45 ] ) {
#ifndef F_24
F_25 ( V_2 -> V_58 ,
V_44 -> V_59 ,
V_2 -> V_19 . V_50 [ V_45 ] ,
V_44 -> V_60 ) ;
#else
F_26 ( V_2 -> V_19 . V_50 [ V_45 ] ) ;
#endif
}
F_27 ( V_44 ) ;
V_2 -> V_19 . V_44 [ V_45 ] = NULL ;
}
V_2 -> V_19 . V_50 [ V_45 ] = NULL ;
}
F_26 ( V_2 -> V_19 . V_44 ) ;
F_26 ( V_2 -> V_19 . V_50 ) ;
V_2 -> V_19 . V_44 = NULL ;
V_2 -> V_19 . V_50 = NULL ;
V_2 -> V_19 . V_57 = 0 ;
F_15 ( L_21 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_44 * V_44 ;
int V_45 , V_61 , V_62 , V_63 , V_64 , V_57 ;
if ( V_2 -> V_19 . V_57 )
F_28 ( V_2 ) ;
F_15 ( L_22 ) ;
V_57 = V_65 ;
V_64 = V_66 ;
V_63 = V_64 * V_2 -> V_67 ;
V_2 -> V_19 . V_17 = NULL ;
V_2 -> V_19 . V_67 = V_2 -> V_67 ;
V_2 -> V_19 . V_44 = F_30 ( sizeof( void * ) * V_57 , V_68 ) ;
if ( ! V_2 -> V_19 . V_44 ) {
F_19 ( L_23 ) ;
return - V_69 ;
}
V_2 -> V_19 . V_50 = F_30 ( sizeof( void * ) * V_57 ,
V_68 ) ;
if ( ! V_2 -> V_19 . V_50 ) {
F_19 ( L_24 ) ;
F_26 ( V_2 -> V_19 . V_44 ) ;
return - V_69 ;
}
for ( V_45 = 0 ; V_45 < V_57 ; V_45 ++ ) {
V_44 = F_31 ( V_64 , V_68 ) ;
if ( ! V_44 ) {
F_19 ( L_25 , V_45 ) ;
goto V_70;
}
V_2 -> V_19 . V_44 [ V_45 ] = V_44 ;
#ifndef F_24
V_2 -> V_19 . V_50 [ V_45 ] = F_32 ( V_2 -> V_58 ,
V_63 , V_68 , & V_44 -> V_60 ) ;
#else
V_2 -> V_19 . V_50 [ V_45 ] = F_33 ( V_63 , V_68 ) ;
#endif
if ( ! V_2 -> V_19 . V_50 [ V_45 ] ) {
F_19 ( L_26 ,
V_63 , V_45 ) ;
if ( V_45 < V_71 )
goto V_70;
goto V_72;
}
memset ( V_2 -> V_19 . V_50 [ V_45 ] , 0 , V_63 ) ;
V_44 -> V_2 = V_2 -> V_58 ;
V_44 -> V_73 = F_34 ( V_2 -> V_58 , V_74 ) ;
V_44 -> V_50 = V_2 -> V_19 . V_50 [ V_45 ] ;
V_44 -> V_59 = V_63 ;
V_44 -> V_75 = F_18 ;
V_44 -> V_54 = V_2 ;
V_44 -> V_76 = 1 ;
V_44 -> V_77 = 0 ;
V_44 -> V_48 = V_64 ;
#ifndef F_24
V_44 -> V_78 = V_79 | V_80 ;
#else
V_44 -> V_78 = V_79 ;
#endif
V_62 = 0 ;
for ( V_61 = 0 ; V_61 < V_64 ; V_61 ++ ) {
V_44 -> V_49 [ V_61 ] . V_51 = V_62 ;
V_44 -> V_49 [ V_61 ] . V_43 =
V_2 -> V_19 . V_67 ;
V_62 += V_2 -> V_19 . V_67 ;
}
}
F_15 ( L_27 , V_57 ) ;
V_2 -> V_19 . V_57 = V_57 ;
return 0 ;
V_72:
F_27 ( V_2 -> V_19 . V_44 [ V_45 ] ) ;
V_2 -> V_19 . V_44 [ V_45 ] = NULL ;
F_17 ( L_28 , V_45 - 1 ) ;
V_2 -> V_19 . V_57 = V_45 - 1 ;
return 0 ;
V_70:
V_2 -> V_19 . V_57 = V_45 + 1 ;
F_23 ( V_2 ) ;
return - V_69 ;
}
