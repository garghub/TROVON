static struct V_1 * T_1 F_1 ( struct V_2 * V_3 , T_2 V_4 , int V_5 )
{
struct V_1 * V_6 ;
if ( ! ( V_3 ) && ! ( V_5 ) ) {
F_2 ( L_1 ) ;
return NULL ;
}
V_6 = F_3 ( sizeof( struct V_1 ) , V_7 ) ;
if ( ! V_6 ) {
F_2 ( L_2 ) ;
return NULL ;
}
if ( V_5 )
V_6 -> V_4 = V_4 ;
else
V_6 -> V_4 = V_3 -> V_8 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
return V_6 ;
}
static struct V_11 * T_1 F_5 ( struct V_2 * V_3 )
{
struct V_11 * V_12 ;
if ( ! V_3 ) {
F_2 ( L_3 ) ;
return NULL ;
}
V_12 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_12 ) {
F_2 ( L_2 ) ;
return NULL ;
}
V_12 -> V_4 = V_3 -> V_8 ;
V_12 -> V_13 = V_3 -> V_14 ;
V_12 -> V_15 = V_3 -> V_16 ;
V_12 -> V_17 = V_3 -> V_18 ;
V_12 -> V_19 = V_3 -> V_18 - V_3 -> V_16 + 1 ;
return V_12 ;
}
static int T_1 F_6 ( struct V_1 * * V_20 , struct V_21 * * V_22 , struct V_2 * V_3 , int V_5 , T_2 V_23 )
{
struct V_1 * V_6 ;
struct V_21 * V_24 ;
T_2 V_25 = 0 ;
if ( V_23 ) {
V_6 = F_3 ( sizeof( struct V_1 ) , V_7 ) ;
if ( ! V_6 ) {
F_2 ( L_4 ) ;
return - V_26 ;
}
V_6 -> V_4 = V_3 -> V_8 ;
} else {
V_6 = * V_20 ;
switch ( V_5 ) {
case V_27 :
V_25 = V_6 -> V_28 ;
break;
case V_29 :
V_25 = V_6 -> V_30 ;
break;
case V_31 :
V_25 = V_6 -> V_32 ;
break;
}
}
V_24 = F_3 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_24 ) {
if ( V_23 )
F_7 ( V_6 ) ;
F_2 ( L_2 ) ;
return - V_26 ;
}
V_24 -> V_15 = V_3 -> V_16 ;
V_24 -> V_17 = V_3 -> V_18 ;
if ( V_23 || ( ! V_25 ) )
V_24 -> V_33 = 1 ;
else {
F_8 ( V_5 , V_24 , V_6 ) ;
F_9 ( L_5 , V_5 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
}
switch ( V_5 ) {
case V_27 :
V_6 -> V_34 = V_24 ;
if ( V_23 )
V_6 -> V_28 = 1 ;
else {
F_9 ( L_6 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
++ V_6 -> V_28 ;
F_10 ( V_6 ) ;
}
break;
case V_31 :
V_6 -> V_35 = V_24 ;
if ( V_23 )
V_6 -> V_32 = 1 ;
else {
F_9 ( L_7 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
++ V_6 -> V_32 ;
F_10 ( V_6 ) ;
}
break;
case V_29 :
V_6 -> V_36 = V_24 ;
if ( V_23 )
V_6 -> V_30 = 1 ;
else {
F_9 ( L_8 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
++ V_6 -> V_30 ;
F_10 ( V_6 ) ;
}
break;
}
* V_20 = V_6 ;
* V_22 = V_24 ;
return 0 ;
}
int T_1 F_11 ( void )
{
struct V_2 * V_3 ;
struct V_21 * V_24 = NULL ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_37 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
struct V_11 * V_41 = NULL ;
struct V_11 * V_42 = NULL ;
struct V_11 * V_43 = NULL ;
int V_44 ;
struct V_39 * V_45 ;
F_12 (tmp_ebda, &ibmphp_ebda_pci_rsrc_head) {
V_3 = F_13 ( V_45 , struct V_2 , V_46 ) ;
if ( ! ( V_3 -> V_47 & V_48 ) ) {
F_9 ( L_9 ) ;
}
if ( V_3 -> V_47 & V_49 ) {
if ( ( V_3 -> V_47 & V_50 ) == V_51 ) {
if ( F_14 ( & V_10 ) ) {
V_44 = F_6 ( & V_6 , & V_24 , V_3 , V_27 , 1 ) ;
if ( V_44 )
return V_44 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_10 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
} else {
V_37 = F_15 ( V_3 -> V_8 , & V_38 , 1 ) ;
if ( V_37 ) {
V_44 = F_6 ( & V_37 , & V_24 , V_3 , V_27 , 0 ) ;
if ( V_44 )
return V_44 ;
} else {
V_44 = F_6 ( & V_6 , & V_24 , V_3 , V_27 , 1 ) ;
if ( V_44 )
return V_44 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_11 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
}
}
} else if ( ( V_3 -> V_47 & V_50 ) == V_52 ) {
if ( F_14 ( & V_10 ) ) {
V_44 = F_6 ( & V_6 , & V_24 , V_3 , V_29 , 1 ) ;
if ( V_44 )
return V_44 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_12 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
} else {
V_37 = F_15 ( V_3 -> V_8 , & V_38 , 1 ) ;
if ( V_37 ) {
V_44 = F_6 ( & V_37 , & V_24 , V_3 , V_29 , 0 ) ;
if ( V_44 )
return V_44 ;
} else {
V_44 = F_6 ( & V_6 , & V_24 , V_3 , V_29 , 1 ) ;
if ( V_44 )
return V_44 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_13 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
}
}
} else if ( ( V_3 -> V_47 & V_50 ) == V_53 ) {
if ( F_14 ( & V_10 ) ) {
V_44 = F_6 ( & V_6 , & V_24 , V_3 , V_31 , 1 ) ;
if ( V_44 )
return V_44 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_14 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
} else {
V_37 = F_15 ( V_3 -> V_8 , & V_38 , 1 ) ;
if ( V_37 ) {
V_44 = F_6 ( & V_37 , & V_24 , V_3 , V_31 , 0 ) ;
if ( V_44 )
return V_44 ;
} else {
V_44 = F_6 ( & V_6 , & V_24 , V_3 , V_31 , 1 ) ;
if ( V_44 )
return V_44 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_15 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
}
}
} else {
;
}
} else {
if ( ( V_3 -> V_47 & V_50 ) == V_51 ) {
V_42 = F_5 ( V_3 ) ;
if ( ! V_42 )
return - V_26 ;
V_42 -> type = V_27 ;
if ( F_16 ( V_42 ) < 0 ) {
V_6 = F_1 ( V_3 , 0 , 0 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_54 = V_42 ;
++ V_6 -> V_55 ;
V_42 -> V_33 = - 1 ;
}
F_9 ( L_16 , V_42 -> V_13 , V_42 -> V_4 , V_42 -> V_15 , V_42 -> V_17 ) ;
} else if ( ( V_3 -> V_47 & V_50 ) == V_52 ) {
V_43 = F_5 ( V_3 ) ;
if ( ! V_43 )
return - V_26 ;
V_43 -> type = V_29 ;
V_43 -> V_56 = 0 ;
if ( F_16 ( V_43 ) < 0 ) {
V_6 = F_1 ( V_3 , 0 , 0 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_57 = V_43 ;
++ V_6 -> V_58 ;
V_43 -> V_33 = - 1 ;
}
F_9 ( L_17 , V_43 -> V_13 , V_43 -> V_4 , V_43 -> V_15 , V_43 -> V_17 ) ;
} else if ( ( V_3 -> V_47 & V_50 ) == V_53 ) {
V_41 = F_5 ( V_3 ) ;
if ( ! V_41 )
return - V_26 ;
V_41 -> type = V_31 ;
if ( F_16 ( V_41 ) < 0 ) {
V_6 = F_1 ( V_3 , 0 , 0 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_59 = V_41 ;
++ V_6 -> V_60 ;
V_41 -> V_33 = - 1 ;
}
F_9 ( L_18 , V_41 -> V_13 , V_41 -> V_4 , V_41 -> V_15 , V_41 -> V_17 ) ;
}
}
}
F_12 (tmp, &gbuses) {
V_37 = F_13 ( V_40 , struct V_1 , V_9 ) ;
V_44 = F_17 ( & V_37 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_18 () ;
if ( V_44 )
return V_44 ;
return 0 ;
}
static int F_8 ( int type , struct V_21 * V_61 , struct V_1 * V_37 )
{
struct V_21 * V_62 = NULL ;
struct V_21 * V_63 ;
int V_64 = 0 , V_65 ;
int V_66 = 0 ;
switch ( type ) {
case V_27 :
V_62 = V_37 -> V_34 ;
V_66 = V_37 -> V_28 ;
break;
case V_29 :
V_62 = V_37 -> V_36 ;
V_66 = V_37 -> V_30 ;
break;
case V_31 :
V_62 = V_37 -> V_35 ;
V_66 = V_37 -> V_32 ;
break;
}
V_63 = NULL ;
while ( V_62 ) {
if ( V_61 -> V_15 < V_62 -> V_15 )
break;
V_63 = V_62 ;
V_62 = V_62 -> V_67 ;
V_64 = V_64 + 1 ;
}
if ( ! V_64 ) {
switch ( type ) {
case V_27 :
V_37 -> V_34 = V_61 ;
break;
case V_29 :
V_37 -> V_36 = V_61 ;
break;
case V_31 :
V_37 -> V_35 = V_61 ;
break;
}
V_61 -> V_67 = V_62 ;
V_61 -> V_33 = 1 ;
V_65 = 0 ;
} else if ( ! V_62 ) {
V_61 -> V_67 = NULL ;
V_63 -> V_67 = V_61 ;
V_61 -> V_33 = V_63 -> V_33 + 1 ;
return 0 ;
} else {
V_63 -> V_67 = V_61 ;
V_61 -> V_67 = V_62 ;
V_61 -> V_33 = V_62 -> V_33 ;
V_65 = V_63 -> V_33 ;
}
for ( V_64 = V_65 ; V_64 < V_66 ; ++ V_64 ) {
++ V_62 -> V_33 ;
V_62 = V_62 -> V_67 ;
}
F_19 ( V_37 , type , V_65 + 1 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_37 , int type , int V_33 )
{
struct V_11 * V_68 = NULL ;
T_2 V_69 = 0 ;
switch ( type ) {
case V_27 :
if ( V_37 -> V_54 )
V_68 = V_37 -> V_54 ;
break;
case V_29 :
if ( V_37 -> V_57 )
V_68 = V_37 -> V_57 ;
break;
case V_31 :
if ( V_37 -> V_59 )
V_68 = V_37 -> V_59 ;
break;
}
if ( V_68 ) {
while ( V_68 ) {
if ( V_68 -> V_33 == V_33 )
break;
if ( V_68 -> V_67 )
V_68 = V_68 -> V_67 ;
else if ( V_68 -> V_70 )
V_68 = V_68 -> V_70 ;
else {
V_69 = 1 ;
break;
}
}
if ( ! V_69 ) {
while ( V_68 ) {
++ V_68 -> V_33 ;
V_68 = V_68 -> V_67 ;
}
}
}
}
static void F_20 ( struct V_11 * V_68 , struct V_1 * V_37 , struct V_21 * V_61 )
{
char * V_71 = L_19 ;
switch ( V_68 -> type ) {
case V_31 :
V_71 = L_20 ;
break;
case V_27 :
V_71 = L_21 ;
break;
case V_29 :
V_71 = L_22 ;
break;
}
while ( V_68 ) {
if ( V_68 -> V_33 == - 1 ) {
while ( V_61 ) {
if ( ( V_68 -> V_15 >= V_61 -> V_15 ) && ( V_68 -> V_17 <= V_61 -> V_17 ) ) {
V_68 -> V_33 = V_61 -> V_33 ;
F_9 ( L_23 , V_71 , V_68 -> V_33 ) ;
switch ( V_68 -> type ) {
case V_31 :
-- V_37 -> V_60 ;
break;
case V_27 :
-- V_37 -> V_55 ;
break;
case V_29 :
-- V_37 -> V_58 ;
break;
}
break;
}
V_61 = V_61 -> V_67 ;
}
}
if ( V_68 -> V_67 )
V_68 = V_68 -> V_67 ;
else
V_68 = V_68 -> V_70 ;
}
}
static void F_10 ( struct V_1 * V_37 )
{
struct V_21 * V_61 ;
struct V_11 * V_68 ;
F_9 ( L_24 , V_72 , V_37 -> V_4 ) ;
if ( V_37 -> V_60 ) {
V_68 = V_37 -> V_59 ;
V_61 = V_37 -> V_35 ;
F_20 ( V_68 , V_37 , V_61 ) ;
}
if ( V_37 -> V_55 ) {
V_68 = V_37 -> V_54 ;
V_61 = V_37 -> V_34 ;
F_20 ( V_68 , V_37 , V_61 ) ;
}
if ( V_37 -> V_58 ) {
V_68 = V_37 -> V_57 ;
V_61 = V_37 -> V_36 ;
F_20 ( V_68 , V_37 , V_61 ) ;
}
}
int F_16 ( struct V_11 * V_68 )
{
struct V_11 * V_73 ;
struct V_11 * V_74 ;
struct V_1 * V_37 ;
struct V_21 * V_62 = NULL ;
struct V_11 * V_75 = NULL ;
F_9 ( L_25 , V_72 ) ;
if ( ! V_68 ) {
F_2 ( L_26 ) ;
return - V_76 ;
}
V_37 = F_15 ( V_68 -> V_4 , NULL , 0 ) ;
if ( ! V_37 ) {
F_9 ( L_27 ) ;
return - V_76 ;
}
switch ( V_68 -> type ) {
case V_31 :
V_62 = V_37 -> V_35 ;
V_75 = V_37 -> V_59 ;
break;
case V_27 :
V_62 = V_37 -> V_34 ;
V_75 = V_37 -> V_54 ;
break;
case V_29 :
V_62 = V_37 -> V_36 ;
V_75 = V_37 -> V_57 ;
break;
default:
F_2 ( L_28 ) ;
return - V_77 ;
}
while ( V_62 ) {
if ( ( V_68 -> V_15 >= V_62 -> V_15 ) && ( V_68 -> V_17 <= V_62 -> V_17 ) ) {
V_68 -> V_33 = V_62 -> V_33 ;
break;
}
V_62 = V_62 -> V_67 ;
}
if ( ! V_62 ) {
switch ( V_68 -> type ) {
case V_31 :
++ V_37 -> V_60 ;
break;
case V_27 :
++ V_37 -> V_55 ;
break;
case V_29 :
++ V_37 -> V_58 ;
break;
}
V_68 -> V_33 = - 1 ;
}
F_9 ( L_29 , V_68 -> V_33 ) ;
if ( ! V_75 ) {
switch ( V_68 -> type ) {
case V_31 :
V_37 -> V_59 = V_68 ;
break;
case V_27 :
V_37 -> V_54 = V_68 ;
break;
case V_29 :
V_37 -> V_57 = V_68 ;
break;
}
V_68 -> V_67 = NULL ;
V_68 -> V_70 = NULL ;
} else {
V_73 = V_75 ;
V_74 = NULL ;
F_9 ( L_30 , V_73 -> V_33 ) ;
while ( V_73 ) {
if ( V_73 -> V_33 >= V_68 -> V_33 )
break;
V_74 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
}
if ( ! V_73 ) {
F_9 ( L_31 , V_68 -> V_15 , V_68 -> V_17 ) ;
V_74 -> V_70 = V_68 ;
V_68 -> V_67 = NULL ;
V_68 -> V_70 = NULL ;
} else if ( V_73 -> V_33 == V_68 -> V_33 ) {
while ( V_73 ) {
if ( V_68 -> V_15 < V_73 -> V_15 )
break;
V_74 = V_73 ;
V_73 = V_73 -> V_67 ;
}
if ( ! V_73 ) {
V_74 -> V_67 = V_68 ;
V_68 -> V_67 = NULL ;
V_68 -> V_70 = V_74 -> V_70 ;
V_74 -> V_70 = NULL ;
} else if ( V_68 -> V_15 < V_73 -> V_15 ) {
if ( ! V_74 ) {
switch ( V_68 -> type ) {
case V_31 :
V_37 -> V_59 = V_68 ;
break;
case V_27 :
V_37 -> V_54 = V_68 ;
break;
case V_29 :
V_37 -> V_57 = V_68 ;
break;
}
} else if ( V_74 -> V_33 == V_73 -> V_33 )
V_74 -> V_67 = V_68 ;
else
V_74 -> V_70 = V_68 ;
V_68 -> V_67 = V_73 ;
V_68 -> V_70 = NULL ;
}
} else {
if ( ! V_74 ) {
V_68 -> V_67 = NULL ;
switch ( V_68 -> type ) {
case V_31 :
V_68 -> V_70 = V_37 -> V_59 ;
V_37 -> V_59 = V_68 ;
break;
case V_27 :
V_68 -> V_70 = V_37 -> V_54 ;
V_37 -> V_54 = V_68 ;
break;
case V_29 :
V_68 -> V_70 = V_37 -> V_57 ;
V_37 -> V_57 = V_68 ;
break;
}
} else if ( V_73 -> V_33 > V_68 -> V_33 ) {
V_74 -> V_70 = V_68 ;
V_68 -> V_67 = NULL ;
V_68 -> V_70 = V_73 ;
}
}
}
F_9 ( L_32 , V_72 ) ;
return 0 ;
}
int F_21 ( struct V_11 * V_68 )
{
struct V_1 * V_37 ;
struct V_11 * V_73 = NULL ;
struct V_11 * V_74 ;
struct V_11 * V_78 ;
char * type = L_19 ;
if ( ! V_68 ) {
F_2 ( L_33 ) ;
return - V_76 ;
}
V_37 = F_15 ( V_68 -> V_4 , NULL , 0 ) ;
if ( ! V_37 ) {
F_2 ( L_34 ) ;
return - V_76 ;
}
switch ( V_68 -> type ) {
case V_31 :
V_73 = V_37 -> V_59 ;
type = L_20 ;
break;
case V_27 :
V_73 = V_37 -> V_54 ;
type = L_21 ;
break;
case V_29 :
V_73 = V_37 -> V_57 ;
type = L_22 ;
break;
default:
F_2 ( L_35 ) ;
return - V_77 ;
}
V_74 = NULL ;
while ( V_73 ) {
if ( ( V_73 -> V_15 == V_68 -> V_15 ) && ( V_73 -> V_17 == V_68 -> V_17 ) )
break;
V_74 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
}
if ( ! V_73 ) {
if ( V_68 -> type == V_29 ) {
V_73 = V_37 -> V_79 ;
V_74 = NULL ;
while ( V_73 ) {
if ( ( V_73 -> V_15 == V_68 -> V_15 ) && ( V_73 -> V_17 == V_68 -> V_17 ) ) {
V_78 = V_37 -> V_54 ;
while ( V_78 ) {
if ( ( V_78 -> V_15 == V_73 -> V_15 )
&& ( V_78 -> V_17 == V_73 -> V_17 ) )
break;
if ( V_78 -> V_67 )
V_78 = V_78 -> V_67 ;
else
V_78 = V_78 -> V_70 ;
}
if ( ! V_78 ) {
F_2 ( L_36 ) ;
return - V_77 ;
}
F_21 ( V_78 ) ;
if ( ! V_74 )
V_37 -> V_79 = V_73 -> V_67 ;
else
V_74 -> V_67 = V_73 -> V_67 ;
F_7 ( V_73 ) ;
return 0 ;
}
V_74 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
}
if ( ! V_73 ) {
F_2 ( L_37 ) ;
return - V_77 ;
}
} else {
F_2 ( L_38 , type ) ;
return - V_77 ;
}
}
if ( ! V_74 ) {
if ( V_73 -> V_67 ) {
switch ( V_68 -> type ) {
case V_31 :
V_37 -> V_59 = V_73 -> V_67 ;
break;
case V_27 :
V_37 -> V_54 = V_73 -> V_67 ;
break;
case V_29 :
V_37 -> V_57 = V_73 -> V_67 ;
break;
}
} else if ( V_73 -> V_70 ) {
switch ( V_68 -> type ) {
case V_31 :
V_37 -> V_59 = V_73 -> V_70 ;
break;
case V_27 :
V_37 -> V_54 = V_73 -> V_70 ;
break;
case V_29 :
V_37 -> V_57 = V_73 -> V_70 ;
break;
}
} else {
switch ( V_68 -> type ) {
case V_31 :
V_37 -> V_59 = NULL ;
break;
case V_27 :
V_37 -> V_54 = NULL ;
break;
case V_29 :
V_37 -> V_57 = NULL ;
break;
}
}
F_7 ( V_73 ) ;
return 0 ;
} else {
if ( V_73 -> V_67 ) {
if ( V_74 -> V_33 == V_73 -> V_33 )
V_74 -> V_67 = V_73 -> V_67 ;
else
V_74 -> V_70 = V_73 -> V_67 ;
} else if ( V_73 -> V_70 ) {
V_74 -> V_67 = NULL ;
V_74 -> V_70 = V_73 -> V_70 ;
} else {
V_74 -> V_67 = NULL ;
V_74 -> V_70 = NULL ;
}
F_7 ( V_73 ) ;
return 0 ;
}
return 0 ;
}
static struct V_21 * F_22 ( struct V_1 * V_37 , struct V_11 * V_68 )
{
struct V_21 * V_61 = NULL ;
switch ( V_68 -> type ) {
case V_31 :
V_61 = V_37 -> V_35 ;
break;
case V_27 :
V_61 = V_37 -> V_34 ;
break;
case V_29 :
V_61 = V_37 -> V_36 ;
break;
default:
F_2 ( L_39 ) ;
}
while ( V_61 ) {
if ( V_68 -> V_33 == V_61 -> V_33 )
break;
V_61 = V_61 -> V_67 ;
}
return V_61 ;
}
int F_23 ( struct V_11 * V_68 , T_2 V_80 )
{
struct V_1 * V_37 ;
struct V_21 * V_61 = NULL ;
struct V_11 * V_74 ;
struct V_11 * V_73 = NULL ;
T_3 V_81 = 0 , V_82 = 0 , V_83 = 0 ;
int V_84 = 0 ;
T_3 V_85 ;
T_3 V_86 ;
T_2 V_5 = 0 ;
if ( ! V_68 )
return - V_77 ;
if ( V_80 ) {
if ( V_68 -> type == V_31 )
V_86 = V_87 ;
else
V_86 = V_88 ;
} else
V_86 = V_68 -> V_19 ;
V_37 = F_15 ( V_68 -> V_4 , NULL , 0 ) ;
if ( ! V_37 ) {
F_9 ( L_27 ) ;
return - V_77 ;
}
F_9 ( L_25 , V_72 ) ;
F_9 ( L_40 , V_37 -> V_4 ) ;
V_68 -> V_19 -= 1 ;
switch ( V_68 -> type ) {
case V_31 :
V_73 = V_37 -> V_59 ;
V_84 = V_37 -> V_32 ;
break;
case V_27 :
V_73 = V_37 -> V_54 ;
V_84 = V_37 -> V_28 ;
break;
case V_29 :
V_73 = V_37 -> V_57 ;
V_84 = V_37 -> V_30 ;
break;
default:
F_2 ( L_41 ) ;
return - V_77 ;
}
V_74 = NULL ;
while ( V_73 ) {
V_61 = F_22 ( V_37 , V_73 ) ;
F_9 ( L_42 , V_72 , V_73 -> V_33 ) ;
if ( ! V_61 ) {
F_2 ( L_43 ) ;
return - V_77 ;
}
if ( ! V_74 ) {
V_83 = V_73 -> V_15 - 1 - V_61 -> V_15 ;
if ( ( V_73 -> V_15 != V_61 -> V_15 ) && ( V_83 >= V_68 -> V_19 ) ) {
F_9 ( L_44 , V_83 ) ;
if ( ( V_83 < V_81 ) || ( V_81 == 0 ) ) {
if ( ( V_61 -> V_15 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_61 -> V_15 ;
} else {
V_85 = V_61 -> V_15 ;
V_5 = 0 ;
while ( ( V_83 = V_73 -> V_15 - 1 - V_85 ) >= V_68 -> V_19 ) {
if ( ( V_85 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_85 ;
break;
}
V_85 += V_86 - V_85 % V_86 ;
if ( V_85 >= V_73 -> V_15 - 1 )
break;
}
}
if ( V_5 && V_81 == V_68 -> V_19 ) {
F_9 ( L_45 ) ;
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
}
}
}
}
if ( ! V_73 -> V_67 ) {
V_83 = V_61 -> V_17 - ( V_73 -> V_17 + 1 ) ;
if ( ( V_61 -> V_17 != V_73 -> V_17 ) && ( V_83 >= V_68 -> V_19 ) ) {
F_9 ( L_44 , V_83 ) ;
if ( ( V_83 < V_81 ) || ( V_81 == 0 ) ) {
if ( ( ( V_73 -> V_17 + 1 ) % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_73 -> V_17 + 1 ;
} else {
V_85 = V_73 -> V_17 + 1 ;
V_5 = 0 ;
while ( ( V_83 = V_61 -> V_17 - V_85 ) >= V_68 -> V_19 ) {
if ( ( V_85 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_85 ;
break;
}
V_85 += V_86 - V_85 % V_86 ;
if ( V_85 >= V_61 -> V_17 )
break;
}
}
if ( V_5 && V_81 == V_68 -> V_19 ) {
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
}
}
}
}
if ( V_74 ) {
if ( V_74 -> V_33 != V_73 -> V_33 ) {
V_83 = V_73 -> V_15 - 1 - V_61 -> V_15 ;
if ( ( V_73 -> V_15 != V_61 -> V_15 ) && ( V_83 >= V_68 -> V_19 ) ) {
if ( ( V_83 < V_81 ) || ( V_81 == 0 ) ) {
if ( ( V_61 -> V_15 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_61 -> V_15 ;
} else {
V_85 = V_61 -> V_15 ;
V_5 = 0 ;
while ( ( V_83 = V_73 -> V_15 - 1 - V_85 ) >= V_68 -> V_19 ) {
if ( ( V_85 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_85 ;
break;
}
V_85 += V_86 - V_85 % V_86 ;
if ( V_85 >= V_73 -> V_15 - 1 )
break;
}
}
if ( V_5 && V_81 == V_68 -> V_19 ) {
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
}
}
}
} else {
V_83 = V_73 -> V_15 - 1 - V_74 -> V_17 - 1 ;
if ( V_83 >= V_68 -> V_19 ) {
if ( ( V_83 < V_81 ) || ( V_81 == 0 ) ) {
if ( ( ( V_74 -> V_17 + 1 ) % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_74 -> V_17 + 1 ;
} else {
V_85 = V_74 -> V_17 + 1 ;
V_5 = 0 ;
while ( ( V_83 = V_73 -> V_15 - 1 - V_85 ) >= V_68 -> V_19 ) {
if ( ( V_85 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_85 ;
break;
}
V_85 += V_86 - V_85 % V_86 ;
if ( V_85 >= V_73 -> V_15 - 1 )
break;
}
}
if ( V_5 && V_81 == V_68 -> V_19 ) {
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
}
}
}
}
}
V_74 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
}
if ( ! V_74 ) {
switch ( V_68 -> type ) {
case V_31 :
V_61 = V_37 -> V_35 ;
break;
case V_27 :
V_61 = V_37 -> V_34 ;
break;
case V_29 :
V_61 = V_37 -> V_36 ;
break;
}
while ( V_61 ) {
V_83 = V_61 -> V_17 - V_61 -> V_15 ;
if ( V_83 >= V_68 -> V_19 ) {
if ( ( V_83 < V_81 ) || ( V_81 == 0 ) ) {
if ( ( V_61 -> V_15 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_61 -> V_15 ;
} else {
V_85 = V_61 -> V_15 ;
V_5 = 0 ;
while ( ( V_83 = V_61 -> V_17 - V_85 ) >= V_68 -> V_19 ) {
if ( ( V_85 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_85 ;
break;
}
V_85 += V_86 - V_85 % V_86 ;
if ( V_85 >= V_61 -> V_17 )
break;
}
}
if ( V_5 && V_81 == V_68 -> V_19 ) {
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
}
}
}
V_61 = V_61 -> V_67 ;
}
if ( ( ! V_61 ) && ( V_81 == 0 ) ) {
F_2 ( L_46 ) ;
return - V_77 ;
} else if ( V_81 ) {
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
}
}
if ( ! V_73 ) {
F_9 ( L_47 , V_74 -> V_33 , V_84 ) ;
if ( V_74 -> V_33 < V_84 ) {
switch ( V_68 -> type ) {
case V_31 :
V_61 = V_37 -> V_35 ;
break;
case V_27 :
V_61 = V_37 -> V_34 ;
break;
case V_29 :
V_61 = V_37 -> V_36 ;
break;
}
while ( V_61 ) {
V_83 = V_61 -> V_17 - V_61 -> V_15 ;
if ( V_83 >= V_68 -> V_19 ) {
if ( ( V_83 < V_81 ) || ( V_81 == 0 ) ) {
if ( ( V_61 -> V_15 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_61 -> V_15 ;
} else {
V_85 = V_61 -> V_15 ;
V_5 = 0 ;
while ( ( V_83 = V_61 -> V_17 - V_85 ) >= V_68 -> V_19 ) {
if ( ( V_85 % V_86 ) == 0 ) {
V_5 = 1 ;
V_81 = V_83 ;
V_82 = V_85 ;
break;
}
V_85 += V_86 - V_85 % V_86 ;
if ( V_85 >= V_61 -> V_17 )
break;
}
}
if ( V_5 && V_81 == V_68 -> V_19 ) {
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
}
}
}
V_61 = V_61 -> V_67 ;
}
if ( ( ! V_61 ) && ( V_81 == 0 ) ) {
F_2 ( L_46 ) ;
return - V_77 ;
} else if ( V_81 ) {
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
}
} else {
if ( V_81 ) {
V_68 -> V_15 = V_82 ;
V_68 -> V_19 += 1 ;
V_68 -> V_17 = V_68 -> V_15 + V_68 -> V_19 - 1 ;
return 0 ;
} else {
F_2 ( L_46 ) ;
return - V_77 ;
}
}
}
return - V_77 ;
}
int F_24 ( struct V_1 * V_89 , T_2 V_90 )
{
struct V_11 * V_73 ;
struct V_11 * V_91 ;
struct V_1 * V_92 ;
int V_44 ;
V_92 = F_15 ( V_90 , NULL , 0 ) ;
if ( ! V_92 ) {
F_9 ( L_48 ) ;
return - V_76 ;
}
F_9 ( L_49 , V_92 -> V_4 ) ;
V_44 = F_25 ( V_89 , V_92 ) ;
if ( V_44 )
return V_44 ;
if ( V_89 -> V_59 ) {
V_73 = V_89 -> V_59 ;
while ( V_73 ) {
V_91 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
F_7 ( V_91 ) ;
V_91 = NULL ;
}
V_89 -> V_59 = NULL ;
}
if ( V_89 -> V_54 ) {
V_73 = V_89 -> V_54 ;
while ( V_73 ) {
V_91 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
F_7 ( V_91 ) ;
V_91 = NULL ;
}
V_89 -> V_54 = NULL ;
}
if ( V_89 -> V_57 ) {
V_73 = V_89 -> V_57 ;
while ( V_73 ) {
V_91 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
F_7 ( V_91 ) ;
V_91 = NULL ;
}
V_89 -> V_57 = NULL ;
}
if ( V_89 -> V_79 ) {
V_73 = V_89 -> V_79 ;
while ( V_73 ) {
V_91 = V_73 ;
V_73 = V_73 -> V_67 ;
F_7 ( V_91 ) ;
V_91 = NULL ;
}
V_89 -> V_79 = NULL ;
}
F_26 ( & V_89 -> V_9 ) ;
F_7 ( V_89 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_21 * V_62 ;
struct V_21 * V_93 ;
int V_94 ;
struct V_11 * V_68 = NULL ;
if ( V_37 -> V_32 ) {
V_62 = V_37 -> V_35 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_32 ; V_94 ++ ) {
if ( F_27 ( V_38 , V_62 -> V_15 , & V_68 , V_31 ) < 0 )
return - V_77 ;
F_21 ( V_68 ) ;
V_93 = V_62 ;
V_62 = V_62 -> V_67 ;
F_7 ( V_93 ) ;
V_93 = NULL ;
}
V_37 -> V_35 = NULL ;
}
if ( V_37 -> V_28 ) {
V_62 = V_37 -> V_34 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_28 ; V_94 ++ ) {
if ( F_27 ( V_38 , V_62 -> V_15 , & V_68 , V_27 ) < 0 )
return - V_77 ;
F_21 ( V_68 ) ;
V_93 = V_62 ;
V_62 = V_62 -> V_67 ;
F_7 ( V_93 ) ;
V_93 = NULL ;
}
V_37 -> V_34 = NULL ;
}
if ( V_37 -> V_30 ) {
V_62 = V_37 -> V_36 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_30 ; V_94 ++ ) {
if ( F_27 ( V_38 , V_62 -> V_15 , & V_68 , V_29 ) < 0 )
return - V_77 ;
F_21 ( V_68 ) ;
V_93 = V_62 ;
V_62 = V_62 -> V_67 ;
F_7 ( V_93 ) ;
V_93 = NULL ;
}
V_37 -> V_36 = NULL ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_89 , T_3 V_95 , struct V_11 * * V_68 , int V_5 )
{
struct V_11 * V_73 = NULL ;
char * type = L_19 ;
if ( ! V_89 ) {
F_2 ( L_50 ) ;
return - V_76 ;
}
switch ( V_5 ) {
case V_31 :
V_73 = V_89 -> V_59 ;
type = L_20 ;
break;
case V_27 :
V_73 = V_89 -> V_54 ;
type = L_21 ;
break;
case V_29 :
V_73 = V_89 -> V_57 ;
type = L_22 ;
break;
default:
F_2 ( L_51 ) ;
return - V_77 ;
}
while ( V_73 ) {
if ( V_73 -> V_15 == V_95 ) {
* V_68 = V_73 ;
break;
}
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
}
if ( ! V_73 ) {
if ( V_5 == V_29 ) {
V_73 = V_89 -> V_79 ;
while ( V_73 ) {
if ( V_73 -> V_15 == V_95 ) {
* V_68 = V_73 ;
break;
}
V_73 = V_73 -> V_67 ;
}
if ( ! V_73 ) {
F_9 ( L_52 , type ) ;
return - V_77 ;
}
} else {
F_9 ( L_53 , type ) ;
return - V_77 ;
}
}
if ( * V_68 )
F_9 ( L_54 , ( * V_68 ) -> V_15 ) ;
return 0 ;
}
void F_28 ( void )
{
struct V_1 * V_37 = NULL ;
struct V_1 * V_96 ;
struct V_21 * V_62 ;
struct V_21 * V_93 ;
struct V_11 * V_73 ;
struct V_11 * V_91 ;
struct V_39 * V_40 ;
struct V_39 * V_67 ;
int V_94 = 0 ;
V_97 = 1 ;
F_29 (tmp, next, &gbuses) {
V_37 = F_13 ( V_40 , struct V_1 , V_9 ) ;
if ( V_37 -> V_32 ) {
V_62 = V_37 -> V_35 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_32 ; V_94 ++ ) {
if ( ! V_62 )
break;
V_93 = V_62 ;
V_62 = V_62 -> V_67 ;
F_7 ( V_93 ) ;
V_93 = NULL ;
}
}
if ( V_37 -> V_28 ) {
V_62 = V_37 -> V_34 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_28 ; V_94 ++ ) {
if ( ! V_62 )
break;
V_93 = V_62 ;
V_62 = V_62 -> V_67 ;
F_7 ( V_93 ) ;
V_93 = NULL ;
}
}
if ( V_37 -> V_30 ) {
V_62 = V_37 -> V_36 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_30 ; V_94 ++ ) {
if ( ! V_62 )
break;
V_93 = V_62 ;
V_62 = V_62 -> V_67 ;
F_7 ( V_93 ) ;
V_93 = NULL ;
}
}
if ( V_37 -> V_59 ) {
V_73 = V_37 -> V_59 ;
while ( V_73 ) {
V_91 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
F_7 ( V_91 ) ;
V_91 = NULL ;
}
V_37 -> V_59 = NULL ;
}
if ( V_37 -> V_54 ) {
V_73 = V_37 -> V_54 ;
while ( V_73 ) {
V_91 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
F_7 ( V_91 ) ;
V_91 = NULL ;
}
V_37 -> V_54 = NULL ;
}
if ( V_37 -> V_57 ) {
V_73 = V_37 -> V_57 ;
while ( V_73 ) {
V_91 = V_73 ;
if ( V_73 -> V_67 )
V_73 = V_73 -> V_67 ;
else
V_73 = V_73 -> V_70 ;
F_7 ( V_91 ) ;
V_91 = NULL ;
}
V_37 -> V_57 = NULL ;
}
if ( V_37 -> V_79 ) {
V_73 = V_37 -> V_79 ;
while ( V_73 ) {
V_91 = V_73 ;
V_73 = V_73 -> V_67 ;
F_7 ( V_91 ) ;
V_91 = NULL ;
}
V_37 -> V_79 = NULL ;
}
V_96 = V_37 ;
F_26 ( & V_37 -> V_9 ) ;
F_7 ( V_96 ) ;
V_96 = NULL ;
}
}
static int T_1 F_18 ( void )
{
struct V_11 * V_98 ;
struct V_11 * V_99 ;
struct V_11 * V_100 ;
struct V_1 * V_37 ;
struct V_39 * V_40 ;
F_12 (tmp, &gbuses) {
V_37 = F_13 ( V_40 , struct V_1 , V_9 ) ;
if ( ( ! V_37 -> V_36 ) && ( V_37 -> V_57 ) ) {
for ( V_98 = V_37 -> V_57 , V_99 = NULL ; V_98 ; V_99 = V_98 , V_98 = V_98 -> V_67 ) {
V_98 -> V_56 = 1 ;
if ( V_99 )
V_99 -> V_67 = V_98 -> V_67 ;
else
V_37 -> V_57 = V_98 -> V_67 ;
if ( ! V_37 -> V_79 )
V_98 -> V_67 = NULL ;
else
V_98 -> V_67 = V_37 -> V_79 ;
V_37 -> V_79 = V_98 ;
V_100 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_100 ) {
F_2 ( L_2 ) ;
return - V_26 ;
}
V_100 -> type = V_27 ;
V_100 -> V_4 = V_98 -> V_4 ;
V_100 -> V_13 = V_98 -> V_13 ;
V_100 -> V_15 = V_98 -> V_15 ;
V_100 -> V_17 = V_98 -> V_17 ;
V_100 -> V_19 = V_98 -> V_19 ;
if ( F_16 ( V_100 ) < 0 )
F_2 ( L_55 ) ;
V_98 -> V_33 = V_100 -> V_33 ;
}
}
}
return 0 ;
}
int F_30 ( struct V_11 * V_101 )
{
struct V_1 * V_37 = F_15 ( V_101 -> V_4 , NULL , 0 ) ;
if ( ! V_37 ) {
F_2 ( L_56 ) ;
return - V_76 ;
}
if ( V_37 -> V_79 )
V_101 -> V_67 = V_37 -> V_79 ;
else
V_101 -> V_67 = NULL ;
V_37 -> V_79 = V_101 ;
return 0 ;
}
struct V_1 * F_31 ( T_2 V_102 )
{
return F_15 ( V_102 , NULL , 0 ) ;
}
static struct V_1 * F_15 ( T_2 V_102 , struct V_1 * * V_103 , T_2 V_5 )
{
struct V_1 * V_37 ;
struct V_39 * V_40 ;
struct V_39 * V_104 ;
F_12 (tmp, &gbuses) {
V_104 = V_40 -> V_103 ;
V_37 = F_13 ( V_40 , struct V_1 , V_9 ) ;
if ( V_5 )
* V_103 = F_13 ( V_104 , struct V_1 , V_9 ) ;
if ( V_37 -> V_4 == V_102 )
return V_37 ;
}
return NULL ;
}
void F_32 ( void )
{
int V_94 = 0 ;
struct V_1 * V_37 = NULL ;
struct V_21 * V_61 ;
struct V_11 * V_68 ;
struct V_39 * V_40 ;
F_33 ( L_57 ) ;
if ( ( ! F_14 ( & V_10 ) ) && V_97 ) {
F_2 ( L_58 ) ;
return;
}
F_12 (tmp, &gbuses) {
V_37 = F_13 ( V_40 , struct V_1 , V_9 ) ;
F_33 ( L_59 , V_37 -> V_4 ) ;
F_33 ( L_60 , V_37 -> V_32 ) ;
F_33 ( L_61 , V_37 -> V_28 ) ;
F_33 ( L_62 , V_37 -> V_30 ) ;
F_33 ( L_63 ) ;
if ( V_37 -> V_35 ) {
V_61 = V_37 -> V_35 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_32 ; V_94 ++ ) {
F_33 ( L_64 , V_61 -> V_33 ) ;
F_33 ( L_65 , V_61 -> V_15 , V_61 -> V_17 ) ;
V_61 = V_61 -> V_67 ;
}
}
F_33 ( L_66 ) ;
if ( V_37 -> V_34 ) {
V_61 = V_37 -> V_34 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_28 ; V_94 ++ ) {
F_33 ( L_64 , V_61 -> V_33 ) ;
F_33 ( L_65 , V_61 -> V_15 , V_61 -> V_17 ) ;
V_61 = V_61 -> V_67 ;
}
}
F_33 ( L_67 ) ;
if ( V_37 -> V_36 ) {
V_61 = V_37 -> V_36 ;
for ( V_94 = 0 ; V_94 < V_37 -> V_30 ; V_94 ++ ) {
F_33 ( L_64 , V_61 -> V_33 ) ;
F_33 ( L_65 , V_61 -> V_15 , V_61 -> V_17 ) ;
V_61 = V_61 -> V_67 ;
}
}
F_33 ( L_68 ) ;
F_33 ( L_69 ) ;
if ( V_37 -> V_59 ) {
V_68 = V_37 -> V_59 ;
while ( V_68 ) {
F_33 ( L_70 , V_68 -> V_33 ) ;
F_33 ( L_71 , V_68 -> V_4 , V_68 -> V_13 ) ;
F_33 ( L_72 , V_68 -> V_15 , V_68 -> V_17 , V_68 -> V_19 ) ;
if ( V_68 -> V_67 )
V_68 = V_68 -> V_67 ;
else if ( V_68 -> V_70 )
V_68 = V_68 -> V_70 ;
else
break;
}
}
F_33 ( L_73 ) ;
if ( V_37 -> V_54 ) {
V_68 = V_37 -> V_54 ;
while ( V_68 ) {
F_33 ( L_70 , V_68 -> V_33 ) ;
F_33 ( L_71 , V_68 -> V_4 , V_68 -> V_13 ) ;
F_33 ( L_72 , V_68 -> V_15 , V_68 -> V_17 , V_68 -> V_19 ) ;
if ( V_68 -> V_67 )
V_68 = V_68 -> V_67 ;
else if ( V_68 -> V_70 )
V_68 = V_68 -> V_70 ;
else
break;
}
}
F_33 ( L_74 ) ;
if ( V_37 -> V_57 ) {
V_68 = V_37 -> V_57 ;
while ( V_68 ) {
F_33 ( L_70 , V_68 -> V_33 ) ;
F_33 ( L_71 , V_68 -> V_4 , V_68 -> V_13 ) ;
F_33 ( L_72 , V_68 -> V_15 , V_68 -> V_17 , V_68 -> V_19 ) ;
if ( V_68 -> V_67 )
V_68 = V_68 -> V_67 ;
else if ( V_68 -> V_70 )
V_68 = V_68 -> V_70 ;
else
break;
}
}
F_33 ( L_75 ) ;
if ( V_37 -> V_79 ) {
V_68 = V_37 -> V_79 ;
while ( V_68 ) {
F_33 ( L_70 , V_68 -> V_33 ) ;
F_33 ( L_71 , V_68 -> V_4 , V_68 -> V_13 ) ;
F_33 ( L_72 , V_68 -> V_15 , V_68 -> V_17 , V_68 -> V_19 ) ;
V_68 = V_68 -> V_67 ;
}
}
}
F_33 ( L_76 ) ;
}
static int F_34 ( struct V_21 * V_61 , struct V_1 * V_37 , T_2 type )
{
struct V_21 * V_62 = NULL ;
switch ( type ) {
case V_31 :
V_62 = V_37 -> V_35 ;
break;
case V_27 :
V_62 = V_37 -> V_34 ;
break;
case V_29 :
V_62 = V_37 -> V_36 ;
break;
default:
F_2 ( L_77 ) ;
return - V_76 ;
}
while ( V_62 ) {
if ( ( V_62 -> V_15 == V_61 -> V_15 ) && ( V_62 -> V_17 == V_61 -> V_17 ) )
return 1 ;
V_62 = V_62 -> V_67 ;
}
return 0 ;
}
static int T_1 F_17 ( struct V_1 * * V_89 )
{
T_2 V_105 , V_106 , V_107 , V_108 , V_109 , V_110 ;
T_4 V_111 , V_112 , V_113 , V_114 , V_115 ;
T_3 V_95 , V_116 , V_117 , V_118 ;
struct V_1 * V_119 ;
struct V_1 * V_37 ;
struct V_11 * V_120 ;
struct V_11 * V_100 ;
struct V_11 * V_101 ;
struct V_21 * V_61 ;
unsigned int V_121 ;
V_37 = * V_89 ;
if ( ! V_37 )
return - V_76 ;
V_122 -> V_123 = V_37 -> V_4 ;
F_9 ( L_78 , V_72 ) ;
F_9 ( L_79 , V_37 -> V_4 ) ;
for ( V_106 = 0 ; V_106 < 32 ; V_106 ++ ) {
for ( V_107 = 0x00 ; V_107 < 0x08 ; V_107 ++ ) {
V_121 = F_35 ( V_106 , V_107 ) ;
F_36 ( V_122 , V_121 , V_124 , & V_111 ) ;
if ( V_111 != V_125 ) {
F_37 ( V_122 , V_121 , V_126 , & V_108 ) ;
switch ( V_108 ) {
case V_127 :
V_107 = 0x8 ;
break;
case V_128 :
break;
case V_129 :
V_107 = 0x8 ;
case V_130 :
F_37 ( V_122 , V_121 , V_131 , & V_105 ) ;
V_119 = F_15 ( V_105 , NULL , 0 ) ;
if ( ! V_119 ) {
V_119 = F_1 ( NULL , V_105 , 1 ) ;
return 0 ;
}
F_37 ( V_122 , V_121 , V_132 , & V_109 ) ;
F_37 ( V_122 , V_121 , V_133 , & V_110 ) ;
F_36 ( V_122 , V_121 , V_134 , & V_112 ) ;
F_36 ( V_122 , V_121 , V_135 , & V_113 ) ;
V_95 = ( V_109 & V_136 ) << 8 ;
V_95 |= ( V_112 << 16 ) ;
V_116 = ( V_110 & V_136 ) << 8 ;
V_116 |= ( V_113 << 16 ) ;
if ( ( V_95 ) && ( V_95 <= V_116 ) ) {
V_61 = F_3 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_61 ) {
F_2 ( L_2 ) ;
return - V_26 ;
}
V_61 -> V_15 = V_95 ;
V_61 -> V_17 = V_116 + 0xfff ;
if ( V_119 -> V_32 > 0 ) {
if ( ! F_34 ( V_61 , V_119 , V_31 ) ) {
F_8 ( V_31 , V_61 , V_119 ) ;
++ V_119 -> V_32 ;
} else {
F_7 ( V_61 ) ;
V_61 = NULL ;
}
} else {
V_61 -> V_33 = 1 ;
V_119 -> V_35 = V_61 ;
++ V_119 -> V_32 ;
}
F_10 ( V_119 ) ;
if ( F_27 ( V_37 , V_95 , & V_120 , V_31 ) ) {
V_120 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_120 ) {
F_7 ( V_61 ) ;
F_2 ( L_2 ) ;
return - V_26 ;
}
V_120 -> type = V_31 ;
V_120 -> V_4 = V_37 -> V_4 ;
V_120 -> V_13 = ( ( V_106 << 3 ) | ( V_107 & 0x7 ) ) ;
V_120 -> V_15 = V_95 ;
V_120 -> V_17 = V_116 + 0xfff ;
V_120 -> V_19 = V_120 -> V_17 - V_120 -> V_15 + 1 ;
F_16 ( V_120 ) ;
}
}
F_36 ( V_122 , V_121 , V_137 , & V_114 ) ;
F_36 ( V_122 , V_121 , V_138 , & V_115 ) ;
V_95 = 0x00000000 | ( V_114 & V_139 ) << 16 ;
V_116 = 0x00000000 | ( V_115 & V_139 ) << 16 ;
if ( ( V_95 ) && ( V_95 <= V_116 ) ) {
V_61 = F_3 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_61 ) {
F_2 ( L_2 ) ;
return - V_26 ;
}
V_61 -> V_15 = V_95 ;
V_61 -> V_17 = V_116 + 0xfffff ;
if ( V_119 -> V_28 > 0 ) {
if ( ! F_34 ( V_61 , V_119 , V_27 ) ) {
F_8 ( V_27 , V_61 , V_119 ) ;
++ V_119 -> V_28 ;
} else {
F_7 ( V_61 ) ;
V_61 = NULL ;
}
} else {
V_61 -> V_33 = 1 ;
V_119 -> V_34 = V_61 ;
++ V_119 -> V_28 ;
}
F_10 ( V_119 ) ;
if ( F_27 ( V_37 , V_95 , & V_100 , V_27 ) ) {
V_100 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_100 ) {
F_7 ( V_61 ) ;
F_2 ( L_2 ) ;
return - V_26 ;
}
V_100 -> type = V_27 ;
V_100 -> V_4 = V_37 -> V_4 ;
V_100 -> V_13 = ( ( V_106 << 3 ) | ( V_107 & 0x7 ) ) ;
V_100 -> V_15 = V_95 ;
V_100 -> V_17 = V_116 + 0xfffff ;
V_100 -> V_19 = V_100 -> V_17 - V_100 -> V_15 + 1 ;
F_16 ( V_100 ) ;
}
}
F_36 ( V_122 , V_121 , V_140 , & V_114 ) ;
F_36 ( V_122 , V_121 , V_141 , & V_115 ) ;
F_38 ( V_122 , V_121 , V_142 , & V_117 ) ;
F_38 ( V_122 , V_121 , V_143 , & V_118 ) ;
V_95 = 0x00000000 | ( V_114 & V_139 ) << 16 ;
V_116 = 0x00000000 | ( V_115 & V_139 ) << 16 ;
#if V_144 == 64
V_95 |= ( ( long ) V_117 ) << 32 ;
V_116 |= ( ( long ) V_118 ) << 32 ;
#endif
if ( ( V_95 ) && ( V_95 <= V_116 ) ) {
V_61 = F_3 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_61 ) {
F_2 ( L_2 ) ;
return - V_26 ;
}
V_61 -> V_15 = V_95 ;
V_61 -> V_17 = V_116 + 0xfffff ;
if ( V_119 -> V_30 > 0 ) {
if ( ! F_34 ( V_61 , V_119 , V_29 ) ) {
F_8 ( V_29 , V_61 , V_119 ) ;
++ V_119 -> V_30 ;
} else {
F_7 ( V_61 ) ;
V_61 = NULL ;
}
} else {
V_61 -> V_33 = 1 ;
V_119 -> V_36 = V_61 ;
++ V_119 -> V_30 ;
}
F_10 ( V_119 ) ;
if ( F_27 ( V_37 , V_95 , & V_101 , V_29 ) ) {
V_101 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_101 ) {
F_7 ( V_61 ) ;
F_2 ( L_2 ) ;
return - V_26 ;
}
V_101 -> type = V_29 ;
V_101 -> V_4 = V_37 -> V_4 ;
V_101 -> V_13 = ( ( V_106 << 3 ) | ( V_107 & 0x7 ) ) ;
V_101 -> V_15 = V_95 ;
V_101 -> V_17 = V_116 + 0xfffff ;
V_101 -> V_19 = V_101 -> V_17 - V_101 -> V_15 + 1 ;
V_101 -> V_56 = 0 ;
F_16 ( V_101 ) ;
}
}
break;
}
}
}
}
V_89 = & V_37 ;
return 0 ;
}
